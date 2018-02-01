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
  void Statement::execute() {
    for(;;) {
      int ret = sqlite3_step(statementHandle);
      BOOST_LOG(logger) << "sqlite3_step " << ret;
      if(ret != SQLITE_ROW) break;
      int numOfColumns = sqlite3_column_count(statementHandle);
      for(int columnIndex = 0; columnIndex < numOfColumns; ++columnIndex) {
        int columnType = sqlite3_column_type(statementHandle, columnIndex);
        BOOST_LOG(logger) << "column type is " << columnType;
        switch(columnType) {
          case SQLITE_INTEGER:
            {
              int intValue = sqlite3_column_int(statementHandle, columnIndex);
              BOOST_LOG(logger) << "column value is " << intValue;
              break;
            }
          case SQLITE_FLOAT:
            {
              double floatValue = sqlite3_column_double(statementHandle, columnIndex);
              BOOST_LOG(logger) << "column value is " << floatValue;
              break;
            }
          case SQLITE_BLOB:
          case SQLITE_NULL:
            break;
          case SQLITE_TEXT:
            {
              const unsigned char * textPtr = sqlite3_column_text(statementHandle, columnIndex);
              std::string textValue(reinterpret_cast<const char *>(textPtr));
              BOOST_LOG(logger) << "column value is " << textValue;
              break;
            }
            break;
        }
      }
    }
    sqlite3_reset(statementHandle);
  }
};
