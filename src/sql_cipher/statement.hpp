#ifndef SQL_CIPHER_STATEMENT_H
#define SQL_CIPHER_STATEMENT_H

#include "sql_cipher/sqlite.hpp"
#include "sql_cipher/result.hpp"
#include "framework/types.hpp"
#include "framework/logger.hpp"

namespace SqlCipher {
  class Connection;
  class Statement : public Framework::Logger {
    friend class Connection;
    public:
      void setDouble(u8 position, double value);
      void setInt(u8 position, i32 value);
      void setText(u8 position, const std::string & value);
      Result execute();
      ~Statement();
    private:
      Statement(Connection & connection, const std::string & sql);
      sqlite3_stmt * statementHandle;
  };
};


#endif /* end of include guard: SQL_CIPHER_STATEMENT_H */
