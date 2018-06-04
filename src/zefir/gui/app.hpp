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
    private:
      void initializeWidgets();
      void onAppStartup();
      void onEnterKeyPressed();
      void onPasswordChosen(Gtk::ListBoxRow * selection);
      int argc;
      char **argv;
      Glib::RefPtr<Gtk::Application> app;
      Gtk::Window * passwordWindow;
      Gtk::Entry * passwordEntry;
      Gtk::Window * accountsWindow;
      Gtk::ListBox * accountsList;
      std::shared_ptr<SqlCipher::Connection> db;
  };
};



#endif /* end of include guard: ZEFIR_GUI_APP_H */
