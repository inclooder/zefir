#include "zefir/gui/app.hpp"
#include "zefir/secret.hpp"
#include "zefir/repo.hpp"
#include <iostream>

namespace Zefir::Gui {
  App::App(int argc, char **argv) : argc(argc), argv(argv) {
  }

  App::~App() {
    delete passwordWindow;
    delete accountsWindow;
  }

  int App::run() {
    app = Gtk::Application::create();
    app->signal_startup().connect(sigc::mem_fun(*this, &App::onAppStartup));
    return app->run();
  }

  void App::onEnterKeyPressed() {
    std::string masterPassword = passwordEntry->get_text();
    if(!db->setPassword(masterPassword)) {
      Gtk::MessageDialog dialog(*passwordWindow, "Incorrect password.", false, Gtk::MessageType::MESSAGE_ERROR);
      dialog.run();
      passwordEntry->set_text("");
    } else {
      Repo repo(db);
      auto secrets = repo.all();
      for(const auto & secret : secrets) {
        auto lbl = Gtk::manage(new Gtk::Label(secret.getName()));
        lbl->show();
        accountsList->append(*lbl);
      }
      accountsWindow->show();
      passwordWindow->hide();
    }
  }

  void App::initializeWidgets() {
    auto builder = Gtk::Builder::create_from_file("res/gui.glade");
    builder->get_widget("master_password_window", passwordWindow);
    builder->get_widget("password_entry", passwordEntry);
    builder->get_widget("accounts_window", accountsWindow);
    builder->get_widget("accounts_list", accountsList);
    passwordEntry->signal_activate().connect(sigc::mem_fun(*this, &App::onEnterKeyPressed));
    accountsList->signal_row_activated().connect(sigc::mem_fun(*this, &App::onPasswordChosen));
  }

  void App::onAppStartup() {
    db = std::make_shared<SqlCipher::Connection>("zefir.db");
    initializeWidgets();
    app->add_window(*passwordWindow);
    app->add_window(*accountsWindow);
    passwordWindow->show();
  }

  void App::onPasswordChosen(Gtk::ListBoxRow * selection) {
    auto secret_name = ((Gtk::Label *)selection->get_child())->get_text();
    auto clipboard = Gtk::Clipboard::get(GDK_SELECTION_PRIMARY);
    clipboard->set_text(secret_name);
    clipboard->store();
    accountsWindow->hide();
  }
};
