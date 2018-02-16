#ifndef SQL_CIPHER_RESULT_H
#define SQL_CIPHER_RESULT_H

#include <map>
#include <vector>
#include <string>
#include <variant>


namespace SqlCipher {
  class Result {
    typedef std::variant<int, float, std::string> Value;
    friend class Connection;
    public:
      std::vector<std::string> getColumns() const;
      std::vector<std::vector<Value>> getRows() const;
    private:
      void addRow(std::map<std::string, Value> row);
      std::vector<std::string> columns;
      std::vector<std::vector<Value>> rows;
  };
};



#endif /* end of include guard: SQ */
