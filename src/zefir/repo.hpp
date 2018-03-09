#ifndef SECRET_REPO_H
#define SECRET_REPO_H

#include <vector>
#include "zefir/secret.hpp"
#include "sql_cipher/connection.hpp"

namespace Zefir {
  class Repo {
    public:
      Repo(const std::string & password);
      bool save(Secret & secret);
      bool save(std::vector<Secret> & secret);
      std::vector<Secret> all();
      bool findById(Secret & secret) const;
    private:
      void initDatabase();
      SqlCipher::Connection db;
  };
};

#endif /* end of include guard: SECRET_REPO_H */
