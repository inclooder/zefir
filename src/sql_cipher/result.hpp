#ifndef SQL_CIPHER_RESULT_H
#define SQL_CIPHER_RESULT_H

#include <map>
#include <vector>
#include <string>

namespace SqlCipher {
  class Result {
    friend class Connection;
    public:
      std::vector<std::string> getColumns() const;
      std::vector<std::vector<std::string>> getRows() const;
    private:
      void addRow(std::map<std::string, std::string> row);
      std::vector<std::string> columns;
      std::vector<std::vector<std::string>> rows;
  };
};



#endif /* end of include guard: SQ */
