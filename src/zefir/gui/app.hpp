#ifndef ZEFIR_GUI_APP_H
#define ZEFIR_GUI_APP_H

#include <gtkmm.h>
#include <memory>
#include "sql_cipher/connection.hpp"

namespace Zefir::Gui {
  class App {
    public:
      App(int argc, char **argv);
      ~App();
      int run();
      void onEnterKeyPressed();
      void initializeWidgets();
    private:
      int argc;
      char **argv;
      Gtk::Window * passwordWindow;
      Gtk::Entry * passwordEntry;
      std::shared_ptr<SqlCipher::Connection> db;
  };
};



#endif /* end of include guard: ZEFIR_GUI_APP_H */
