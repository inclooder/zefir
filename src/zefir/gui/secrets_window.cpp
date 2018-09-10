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
      connect(sigc::mem_fun(*this, &SecretsWindow::refreshList));
  }

  SecretsWindow::~SecretsWindow() {
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
};
