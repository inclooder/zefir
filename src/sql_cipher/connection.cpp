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

  void Connection::execute(const std::string & query) {
    std::vector<std::string> columnNames;
    std::vector<std::vector<std::string>> rows;
    std::cout << "Executing: " << query << std::endl;
    auto execCallback = [](void *, int numColumns, char ** values, char ** columns) -> int {
      std::cout << "received " << numColumns << " columns" << std::endl;
      /* bool populateColumns = columnNames.size() == 0; */
      std::vector<std::string> row;
      for(int i = 0; i < numColumns; ++i) {
        auto value = values[i];
        auto column = columns[i];
        std::cout << column << " => " << value << std::endl;
        /* if(populateColumns) columnNames.push_back(column); */
        row.push_back(value);
      }
      /* rows.push_back(row); */
      return 0;
    };

    auto retVal = sqlite3_exec(dbHandle, query.c_str(), execCallback, nullptr, nullptr);
    std::cout << "sqlite3_exec return value = " << retVal << std::endl;

  }
};
