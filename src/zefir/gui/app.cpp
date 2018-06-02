#include "zefir/gui/app.hpp"
#include <gtkmm.h>

namespace Zefir::Gui {
  App::App(int argc, char **argv) : argc(argc), argv(argv) {
  }

  int App::run() {
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.examples.base");
    Gtk::Window window;
    window.set_modal(true);
    window.set_default_size(200, 200);
    return app->run(window);
  }
};
