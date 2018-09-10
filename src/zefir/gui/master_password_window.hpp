#pragma once

#include <gtkmm.h>
#include "zefir/repo.hpp"

namespace Zefir::Gui {
  class MasterPasswordWindow : public Gtk::Window {
    public:
      MasterPasswordWindow(
        BaseObjectType* cobject,
        const Glib::RefPtr<Gtk::Builder>& builder,
        std::shared_ptr<SqlCipher::Connection> db
      );
      virtual ~MasterPasswordWindow();
      void onEnterKeyPressed();
      sigc::signal<void> onPasswordAccepted();
    private:
      Glib::RefPtr<Gtk::Builder> builder;
      std::shared_ptr<SqlCipher::Connection> db;
      sigc::signal<void> signalPasswordAccepted;
      Gtk::Entry* passwordEntry;
  };
};
