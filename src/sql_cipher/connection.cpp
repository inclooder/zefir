#include "sql_cipher/connection.hpp"
#include <iostream>
#include <vector>

namespace SqlCipher {
  Connection::Connection(const std::string & dbPath, const std::string & key) {
    if(SQLITE_OK != sqlite3_open(dbPath.c_str(), &dbHandle)){
      const char * errorMessage = sqlite3_errmsg(dbHandle);
      throw Error(errorMessage);
    }
    auto retVal = sqlite3_key(dbHandle, key.c_str(), key.size());
    std::cout << "sqlite3_key return value = " << retVal << std::endl;
  }

  Connection::~Connection(){
    sqlite3_close(dbHandle);
  }

  Result Connection::execute(const std::string & query) {
    Result result;
    std::vector<std::string> columnNames;
    std::vector<std::vector<std::string>> rows;
    BOOST_LOG(Connection::logger) << "Executing: " << query;
    auto execCallback = [](void * res, int numColumns, char ** values, char ** columns) -> int {
      Result * result = reinterpret_cast<Result *>(res);
      std::map<std::string, std::string> row;
      for(int i = 0; i < numColumns; ++i) {
        auto value = values[i];
        auto column = columns[i];
        row.insert({ column, value });
      }
      result->addRow(row);
      return 0;
    };

    auto retVal = sqlite3_exec(dbHandle, query.c_str(), execCallback, &result, nullptr);
    std::cout << "sqlite3_exec return value = " << retVal << std::endl;
    return result;
  }
};
