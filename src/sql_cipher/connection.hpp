#ifndef SQL_CIPHER_CONNECTION_H
#define SQL_CIPHER_CONNECTION_H

#define SQLITE_HAS_CODEC
#include <sqlite3.h>
#include <string>
#include "sql_cipher/error.hpp"
#include "sql_cipher/result.hpp"
#include "framework/logger.hpp"

namespace SqlCipher {
  class Connection : public Framework::Logger {
    public:
      Connection(const std::string & dbPath);
      ~Connection();
      void setPassword(const std::string & password);
      Result execute(const std::string & query);
    private:
      sqlite3 * dbHandle;
  };
};



#endif /* end of include guard: SQL_CIPHER_H */
