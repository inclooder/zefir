#ifndef SQL_CIPHER_CONNECTION_H
#define SQL_CIPHER_CONNECTION_H

#include <string>
#include "sql_cipher/sqlite.hpp"
#include "sql_cipher/error.hpp"
#include "sql_cipher/result.hpp"
#include "sql_cipher/statement.hpp"
#include "framework/logger.hpp"

namespace SqlCipher {
  class Connection : public Framework::Logger {
    friend class Statement;
    public:
      Connection(const std::string & dbPath);
      ~Connection();
      bool setPassword(const std::string & password);
      Result execute(const std::string & query);
      Statement statement(const std::string & sql);
    private:
      sqlite3 * dbHandle;
  };
};



#endif /* end of include guard: SQL_CIPHER_H */
