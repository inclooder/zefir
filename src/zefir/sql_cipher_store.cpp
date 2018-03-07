#include "zefir/sql_cipher_store.hpp"

namespace Zefir {
  SqlCipherStore::SqlCipherStore(const std::string & password) : db("zefir.db") {
    db.setPassword(password);
    initDatabase();
  }

  std::vector<Secret> SqlCipherStore::getSecrets(u32 startIndex, u32 limit) {
    return std::vector<Secret>();
  }

  u32 SqlCipherStore::countSecrets() {
    return 0;
  }

  SqlCipherStore::~SqlCipherStore() {
  }

  void SqlCipherStore::initDatabase() {
    db.execute(
      "CREATE TABLE IF NOT EXISTS secrets"
      "(id integer PRIMARY KEY, vault_id integer, name text, description text);"
    );
    db.execute(
      "CREATE TABLE IF NOT EXISTS properties"
      "(id integer PRIMARY KEY, secret_id integer, name text, value text);"
    );
  }
};
