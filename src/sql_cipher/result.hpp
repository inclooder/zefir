#pragma once

#include <map>
#include <vector>
#include <string>
#include <variant>


namespace SqlCipher {
  class Result {
    friend class Connection;
    friend class Statement;
    public:
      typedef std::variant<int, double, std::string> Value;
      typedef std::vector<Value> Row;
      std::vector<std::string> getColumns() const;
      std::vector<Row> getRows() const;
    private:
      void addRow(std::map<std::string, Value> row);
      void addRow(Row row);
      std::vector<std::string> columns;
      std::vector<Row> rows;
  };
};
