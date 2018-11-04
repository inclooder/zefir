#pragma once

#include "sql_cipher/sqlite.hpp"
#include "sql_cipher/result.hpp"
#include "framework/types.hpp"
#include "framework/logger.hpp"
#include <string>

namespace SqlCipher {
  class Connection;
  class Statement : public Framework::Logger {
    friend class Connection;
    public:
      void setDouble(u8 position, double value);
      void setInt(u8 position, i32 value);
      void setText(u8 position, const std::string & value);
      std::string toSql();
      Result execute();
      ~Statement();
    private:
      Statement(Connection & connection, const std::string & sql);
      sqlite3_stmt * statementHandle;
  };
};
