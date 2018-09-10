#pragma once

#include <gtkmm.h>
#include <memory>
#include <boost/program_options.hpp>
#include "sql_cipher/connection.hpp"
#include "zefir/gui/master_password_window.hpp"

namespace Zefir::Gui {
  class App {
    public:
      App(boost::program_options::variables_map options);
      int run();
    private:
      void initializeWidgets();
      void onAppStartup();
      void showAccountsList();
      void onPasswordChosen(Gtk::ListBoxRow * selection);
      Glib::RefPtr<Gtk::Application> app;
      std::unique_ptr<MasterPasswordWindow> masterPasswordWindow;
      std::unique_ptr<Gtk::Window> accountsWindow;
      Gtk::ListBox* accountsList;
      std::shared_ptr<SqlCipher::Connection> db;
      boost::program_options::variables_map options;
  };
};
