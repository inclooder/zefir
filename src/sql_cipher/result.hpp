#ifndef SQL_CIPHER_RESULT_H
#define SQL_CIPHER_RESULT_H

#include <map>
#include <vector>
#include <string>

namespace SqlCipher {
  class Result {
    public:
      void addRow(std::map<std::string, std::string> row);
      std::vector<std::string> getColumns();
      std::vector<std::vector<std::string>> getRows();
    private:
      std::vector<std::string> columns;
      std::vector<std::vector<std::string>> rows;
  };
};



#endif /* end of include guard: SQ */
