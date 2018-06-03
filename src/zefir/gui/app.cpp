#include "zefir/gui/app.hpp"
#include <iostream>

namespace Zefir::Gui {
  App::App(int argc, char **argv) : argc(argc), argv(argv) {
  }

  App::~App() {
    delete passwordWindow;
  }

  int App::run() {
    db = std::make_shared<SqlCipher::Connection>("zefir.db");

    int argcForGtk = 1;
    auto app = Gtk::Application::create(argcForGtk, argv, "org.gtkmm.examples.base");
    initializeWidgets();

    return app->run(*passwordWindow);
  }

  void App::onEnterKeyPressed() {
    std::string masterPassword = passwordEntry->get_text();
    if(!db->setPassword(masterPassword)) {
      std::cout << "invalid password" << std::endl;
      Gtk::MessageDialog dialog(*passwordWindow, "Incorrect password.", false, Gtk::MessageType::MESSAGE_ERROR);
      dialog.run();
      passwordEntry->set_text("");
    } else {
      std::cout << "valid password" << std::endl;
      //Pokazac liste haseł
      passwordWindow->hide();
    }
  }

  void App::initializeWidgets() {
    auto builder = Gtk::Builder::create_from_file("res/gui.glade");
    builder->get_widget("master_password_window", passwordWindow);
    builder->get_widget("password_entry", passwordEntry);
    passwordEntry->set_events(Gdk::ALL_EVENTS_MASK);
    passwordEntry->signal_activate().connect(sigc::mem_fun(*this, &App::onEnterKeyPressed));
  }
};
