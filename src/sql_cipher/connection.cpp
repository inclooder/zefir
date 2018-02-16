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

  void Connection::setPassword(const std::string & password) {
    sqlite3_key(dbHandle, password.c_str(), password.size());
  }

  Result Connection::execute(const std::string & sql) {
    Result result;
    std::vector<std::string> columnNames;
    std::vector<std::vector<std::string>> rows;
    BOOST_LOG(logger) << "Executing SQL: " << sql;
    auto execCallback = [](void * res, int numColumns, char ** values, char ** columns) -> int {
      Result * result = reinterpret_cast<Result *>(res);
      std::map<std::string, Result::Value> row;
      for(int i = 0; i < numColumns; ++i) {
        auto value = values[i];
        auto column = columns[i];
        row.insert({ column, value });
      }
      result->addRow(row);
      return 0;
    };

    auto retVal = sqlite3_exec(dbHandle, sql.c_str(), execCallback, &result, nullptr);
    BOOST_LOG(logger) << "sqlite3_exec return value = " << retVal;
    return result;
  }

  Statement Connection::statement(const std::string & sql) {
    return Statement(*this, sql);
  }
};
