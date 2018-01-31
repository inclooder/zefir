#include "sql_cipher/result.hpp"
#include <iostream>
#include <algorithm>

namespace SqlCipher {
  void Result::addRow(std::map<std::string, std::string> row){
    for(const auto& entry : row) {
      if(std::find(columns.begin(), columns.end(), entry.first) == columns.end()) {
        columns.push_back(entry.first);
      }
    }
    std::vector<std::string> newRow;
    for(const auto& column : columns) {
      newRow.push_back(row[column]);
    }
    rows.push_back(newRow);
  }

  std::vector<std::string> Result::getColumns() {
    return columns;
  }

  std::vector<std::vector<std::string>> Result::getRows() {
    return rows;
  }
};
