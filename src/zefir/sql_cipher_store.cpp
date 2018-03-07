#include "zefir/sql_cipher_store.hpp"
#include "sql_cipher/result.hpp"
#include <iostream>
#include <variant>

namespace Zefir {
  SqlCipherStore::SqlCipherStore(const std::string & password) : db("zefir.db") {
    db.setPassword(password);
    initDatabase();
  }

  std::vector<Secret> SqlCipherStore::getSecrets(u32 startIndex, u32 limit) {
    return std::vector<Secret>();
  }

  u32 SqlCipherStore::countSecrets() {
    SqlCipher::Result result = db.execute("SELECT COUNT(*) from secrets;");
    auto value = result.getRows().front().front();

    return std::get<int>(value);
  }

  SqlCipherStore::~SqlCipherStore() {
  }

  void SqlCipherStore::initDatabase() {
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
