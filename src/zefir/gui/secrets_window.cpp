#include "zefir/gui/secrets_window.hpp"

namespace Zefir::Gui {
  SecretsWindow::SecretsWindow(
    BaseObjectType* cobject,
    const Glib::RefPtr<Gtk::Builder>& builder,
    std::shared_ptr<SqlCipher::Connection> db
  ) : Gtk::Window(cobject), builder(builder), db(db)
  {
  }

  SecretsWindow::~SecretsWindow() {
  }
};
