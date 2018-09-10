#pragma once

#include <vector>
#include "zefir/secret.hpp"
#include "sql_cipher/connection.hpp"
#include <memory>

namespace Zefir {
  class Repo {
    public:
      Repo(std::shared_ptr<SqlCipher::Connection> db);
      bool save(Secret & secret);
      bool save(std::vector<Secret> & secret);
      std::vector<Secret> all();
      bool findById(Secret & secret) const;
      std::vector<Secret> searchByName(const std::string & name);
      std::vector<Secret> findByName(const std::string & name);
    private:
      void initDatabase();
      std::shared_ptr<SqlCipher::Connection> db;
  };
};
