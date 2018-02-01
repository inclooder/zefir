#include "sql_cipher/statement.hpp"

namespace SqlCipher {
  Statement::Statement(Connection & connection, const std::string & sql) {
    sqlite3_prepare_v2(connection.dbHandle, sql.c_str(), sql.size(), &statementHandle, nullptr);
  }
  Statement::~Statement() {
    sqlite3_finalize(statementHandle);
  }
  void Statement::setDouble(u8 position, double value) {
    sqlite3_bind_double(statementHandle, position, value);
  }
  void Statement::setInt(u8 position, i32 value) {
    sqlite3_bind_int(statementHandle, position, value);
  }
  void Statement::setText(u8 position, const std::string & value) {
    sqlite3_bind_text(statementHandle, position, value.c_str(), value.size(), SQLITE_TRANSIENT);
  }
};
