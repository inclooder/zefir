#include "sql_cipher/result.hpp"
#include <algorithm>

namespace SqlCipher {
  void Result::addRow(std::map<std::string, Result::Value> row){
    for(const auto& entry : row) {
      if(std::find(columns.begin(), columns.end(), entry.first) == columns.end()) {
        columns.push_back(entry.first);
      }
    }
    std::vector<Result::Value> newRow;
    for(const auto& column : columns) {
      newRow.push_back(row[column]);
    }
    rows.push_back(newRow);
  }

  std::vector<std::string> Result::getColumns() const {
    return columns;
  }

  std::vector<std::vector<Result::Value>> Result::getRows() const {
    return rows;
  }
};
