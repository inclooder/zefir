#pragma once

#include <gtkmm.h>
#include <memory>
#include "sql_cipher/connection.hpp"
#include "zefir/gui/master_password_window.hpp"

namespace Zefir::Gui {
  class App {
    public:
      App(int argc, char **argv);
      int run();
    private:
      void initializeWidgets();
      void onAppStartup();
      void showAccountsList();
      void onPasswordChosen(Gtk::ListBoxRow * selection);
      int argc;
      char **argv;
      Glib::RefPtr<Gtk::Application> app;
      std::unique_ptr<MasterPasswordWindow> masterPasswordWindow;
      std::unique_ptr<Gtk::Window> accountsWindow;
      Gtk::ListBox* accountsList;
      std::shared_ptr<SqlCipher::Connection> db;
  };
};
