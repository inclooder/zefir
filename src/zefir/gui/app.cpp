#include "zefir/gui/app.hpp"
#include <iostream>

namespace Zefir::Gui {
  App::App(int argc, char **argv) : argc(argc), argv(argv) {
  }

  int App::run() {
    int argcForGtk = 1;
    auto app = Gtk::Application::create(argcForGtk, argv, "org.gtkmm.examples.base");

    Gtk::Window * window = nullptr;
    auto builder = Gtk::Builder::create_from_file("res/gui.glade");
    builder->get_widget("master_password_window", window);

    Gtk::Entry * passwordEntry = nullptr;
    builder->get_widget("password_entry", passwordEntry);
    passwordEntry->set_events(Gdk::ALL_EVENTS_MASK);
    passwordEntry->signal_activate().connect(sigc::mem_fun(*this, &App::onEnterKeyPressed));

    return app->run(*window);
  }

  void App::onEnterKeyPressed() {
    std::cout << "checking password" << std::endl;
  }
};
