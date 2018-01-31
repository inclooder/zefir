#ifndef ZEFIR_SQL_CIPHER_STORE_H
#define ZEFIR_SQL_CIPHER_STORE_H

#include "zefir/abstract_store.hpp"
#include "zefir/secret_message.hpp"

namespace Zefir {
  class SqlCipherStore : public AbstractStore {
    public:
      void add(const SecretMessage & message) override;
      bool unlock(const std::string & password) override;
      void lock() override;
      SecretMessage findByField(const std::string & name, const std::string & value) override;
      std::vector<SecretMessage> all() override;
      ~SqlCipherStore() override;
  };
};


#endif /* end of include guard: ZEFIR_SQL_CIPHER_STORE_H */
