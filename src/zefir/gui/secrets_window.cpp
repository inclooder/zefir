#include "zefir/gui/secrets_window.hpp"
#include <iostream>

using std::cout;
using std::endl;

namespace Zefir::Gui {
  SecretsWindow::SecretsWindow(
    BaseObjectType* cobject,
    const Glib::RefPtr<Gtk::Builder>& builder,
    std::shared_ptr<SqlCipher::Connection> db
  ) : Gtk::Window(cobject), builder(builder), db(db)
  {
    builder->get_widget("search_secret_entry", searchEntry);
    searchEntry->signal_search_changed().
      connect(sigc::mem_fun(*this, &SecretsWindow::refreshList));
    builder->get_widget("secrets_list", secretsList);

    this->signal_show().
      connect(sigc::mem_fun(*this, &SecretsWindow::startup));

    secretsList->signal_row_activated().connect(sigc::mem_fun(*this, &SecretsWindow::selectSecret));
    builder->get_widget("edit_secret_name", secretName);
    builder->get_widget("edit_password_entry", editPasswordEntry);
    builder->get_widget("update_password_btn", updatePasswordBtn);
    updatePasswordBtn->signal_clicked().connect(sigc::mem_fun(*this, &SecretsWindow::updatePassword));
  }

  SecretsWindow::~SecretsWindow() {
  }

  void SecretsWindow::startup() {
    refreshList();
    auto firstSecret = secretsList->get_row_at_index(0);
    secretsList->select_row(*firstSecret);
    selectSecret(firstSecret);
  }

  void SecretsWindow::refreshList() {
    for(Gtk::Widget * widget : secretsList->get_children()) {
      secretsList->remove(*widget);
      delete widget;
    }

    Repo repo(db);
    auto secrets = repo.searchByName(searchEntry->get_text());
    for(const auto & secret : secrets) {
      auto lbl = Gtk::manage(new Gtk::Label(secret.getName()));
      lbl->show();
      secretsList->append(*lbl);
    }
  }

  void SecretsWindow::updatePassword() {
    cout << "Password changed" << endl;
    auto secret_name = secretName->get_text();
    Repo repo(db);
    auto secrets = repo.findByName(secret_name);
    if(secrets.size() > 0) {
      auto secret = secrets[0];
      secret.setPassword(editPasswordEntry->get_text());
      repo.update(secret);
      refreshList();
    }
  }

  void SecretsWindow::selectSecret(Gtk::ListBoxRow * selection) {
    auto secret_name = ((Gtk::Label *)selection->get_child())->get_text();
    secretName->set_text(secret_name);

    Repo repo(db);
    auto secrets = repo.findByName(secret_name);
    if(secrets.size() > 0) {
      auto secret = secrets[0];
      editPasswordEntry->set_text(secret.getPassword());
    }
  }
};
