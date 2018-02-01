#ifndef SQL_CIPHER_STATEMENT_H
#define SQL_CIPHER_STATEMENT_H

#include "sql_cipher/connection.hpp"
#include "framework/types.hpp"

namespace SqlCipher {
  class Statement {
    public:
      Statement(Connection & connection, const std::string & sql);
      void setDouble(u8 position, double value);
      void setInt(u8 position, i32 value);
      void setText(u8 position, const std::string & value);
      ~Statement();
    private:
      sqlite3_stmt * statementHandle;
  };
};


#endif /* end of include guard: SQL_CIPHER_STATEMENT_H */
