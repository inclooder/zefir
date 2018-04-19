#include "sql_cipher/connection.hpp"
#include <vector>

namespace SqlCipher {
  Connection::Connection(const std::string & dbPath) {
    if(SQLITE_OK != sqlite3_open(dbPath.c_str(), &dbHandle)){
      const char * errorMessage = sqlite3_errmsg(dbHandle);
      throw Error(errorMessage);
    }
  }

  Connection::~Connection(){
    sqlite3_close(dbHandle);
  }

  bool Connection::setPassword(const std::string & password) {
    return sqlite3_key(dbHandle, password.c_str(), password.size()) == SQLITE_OK;
  }

  Result Connection::execute(const std::string & sql) {
    return statement(sql).execute();
  }

  Statement Connection::statement(const std::string & sql) {
    return Statement(*this, sql);
  }
};
