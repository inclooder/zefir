#include "zefir/repo.hpp"

namespace Zefir {
  Repo::Repo(const std::string & password) : db("zefir.db") {
    db.setPassword(password);
    initDatabase();
  }

  bool Repo::save(Secret & secret) {
  }

  bool Repo::save(std::vector<Secret> & secret) {
  }

  std::vector<Secret> Repo::all() {
    std::vector<Secret> secrets;
    SqlCipher::Result result = db.execute("SELECT name, description FROM secrets;");
    auto rows = result.getRows();
    for(const auto & row : rows) {
      Secret secret;
      std::string name = std::get<std::string>(row.at(0));
      std::string description = std::get<std::string>(row.at(1));
      secret.setName(name);
      secret.setDescription(description);
      secrets.push_back(secret);
    }
    return secrets;
  }

  bool Repo::findById(Secret & secret) const {
  }

  void Repo::initDatabase() {
    db.execute(
      "CREATE TABLE IF NOT EXISTS secrets"
      "(id integer PRIMARY KEY, name text, description text);"
    );
    db.execute(
      "CREATE TABLE IF NOT EXISTS properties"
      "(id integer PRIMARY KEY, secret_id integer, name text, value text);"
    );
  }
};
