#pragma once

#include <gtkmm.h>
#include "zefir/repo.hpp"

namespace Zefir::Gui {
  class SecretsWindow : public Gtk::Window {
    public:
      SecretsWindow(
        BaseObjectType* cobject,
        const Glib::RefPtr<Gtk::Builder>& builder,
        std::shared_ptr<SqlCipher::Connection> db
      );
      virtual ~SecretsWindow();
    private:
      Glib::RefPtr<Gtk::Builder> builder;
      std::shared_ptr<SqlCipher::Connection> db;
  };
};