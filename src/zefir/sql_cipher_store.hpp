#ifndef ZEFIR_SQL_CIPHER_STORE_H
#define ZEFIR_SQL_CIPHER_STORE_H

#include "zefir/store.hpp"

namespace Zefir {
  class SqlCipherStore : public Store {
    public:
      std::vector<Secret> getSecrets(u32 startIndex, u32 limit) override;
      u32 countSecrets() override;
      SqlCipherStore(const std::string & password);
      ~SqlCipherStore() override;
  };
};

#endif /* end of include guard: ZEFIR_SQL_CIPHER_STORE_H */
