#include "zefir/gui/master_password_window.hpp"

namespace Zefir::Gui {

  MasterPasswordWindow::MasterPasswordWindow(
    BaseObjectType* cobject,
    const Glib::RefPtr<Gtk::Builder>& builder,
    std::shared_ptr<SqlCipher::Connection> db
  ) : Gtk::Window(cobject), builder(builder), db(db)
  {
    builder->get_widget("password_entry", passwordEntry);
    if(passwordEntry) {
      passwordEntry->signal_activate().
        connect(sigc::mem_fun(*this, &MasterPasswordWindow::onEnterKeyPressed));
    }
  }

  MasterPasswordWindow::~MasterPasswordWindow() {
  }

  void MasterPasswordWindow::onEnterKeyPressed() {
    std::string masterPassword = passwordEntry->get_text();
    if(!db->setPassword(masterPassword)) {
      Gtk::MessageDialog dialog(*this, "Incorrect password.", false, Gtk::MessageType::MESSAGE_ERROR);
      dialog.run();
      passwordEntry->set_text("");
    } else {
      signalPasswordAccepted.emit();
    }
  }

  sigc::signal<void> MasterPasswordWindow::onPasswordAccepted() {
    return signalPasswordAccepted;
  }
};
