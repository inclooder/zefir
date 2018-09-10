#include "zefir/gui/app.hpp"
#include "zefir/secret.hpp"
#include "zefir/repo.hpp"
#include <iostream>

namespace Zefir::Gui {
  App::App(boost::program_options::variables_map options) : options(options) {
  }

  int App::run() {
    app = Gtk::Application::create();
    app->signal_startup().connect(sigc::mem_fun(*this, &App::onAppStartup));
    return app->run();
  }

  void App::showAccountsList() {
    Repo repo(db);
    auto secrets = repo.all();
    for(const auto & secret : secrets) {
      auto lbl = Gtk::manage(new Gtk::Label(secret.getName()));
      lbl->show();
      accountsList->append(*lbl);
    }
    accountsWindow->show();
    masterPasswordWindow->hide();
  }

  void App::showSecretsList() {
    secretsWindow->show();
    masterPasswordWindow->hide();
  }

  void App::initializeWidgets() {
    auto builder = Gtk::Builder::create_from_file("res/gui.glade");

    MasterPasswordWindow * mpw;
    builder->get_widget_derived("master_password_window", mpw, db);
    masterPasswordWindow = std::unique_ptr<MasterPasswordWindow>(mpw);
    if(options.count("select")) {
      masterPasswordWindow->onPasswordAccepted().connect(sigc::mem_fun(*this, &App::showAccountsList));
    } else {
      //Normal window
      masterPasswordWindow->onPasswordAccepted().connect(sigc::mem_fun(*this, &App::showSecretsList));
    }
    app->add_window(*masterPasswordWindow);

    SecretsWindow * sww;
    builder->get_widget_derived("secrets_window", sww, db);
    secretsWindow = std::unique_ptr<SecretsWindow>(sww);
    app->add_window(*secretsWindow);

    Gtk::Window * wnd = nullptr;
    builder->get_widget("accounts_window", wnd);
    accountsWindow = std::unique_ptr<Gtk::Window>(wnd);
    builder->get_widget("accounts_list", accountsList);
    accountsList->signal_row_activated().connect(sigc::mem_fun(*this, &App::onPasswordChosen));
    app->add_window(*accountsWindow);
  }

  void App::onAppStartup() {
    db = std::make_shared<SqlCipher::Connection>("zefir.db");
    initializeWidgets();
    masterPasswordWindow->show();
  }

  void App::onPasswordChosen(Gtk::ListBoxRow * selection) {
    auto secret_name = ((Gtk::Label *)selection->get_child())->get_text();
    auto clipboard = Gtk::Clipboard::get(GDK_SELECTION_PRIMARY);
    clipboard->set_text(secret_name);
    clipboard->store();
    accountsWindow->hide();
  }
};
