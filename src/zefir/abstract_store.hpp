#ifndef ZEFIR_ABSTRACT_STORE_H
#define ZEFIR_ABSTRACT_STORE_H

#include "zefir/secret_message.hpp"
#include <vector>
#include <memory>

namespace Zefir {
  class AbstractStore {
    public:
      virtual void add(const SecretMessage & message) = 0;
      virtual bool unlock(const std::string & password) = 0;
      virtual void lock() = 0;
      virtual SecretMessage findByField(const std::string & name, const std::string & value) = 0;
      virtual std::vector<SecretMessage> all() = 0;
      virtual ~AbstractStore() {};
  };
};


#endif /* end of include guard: ZEFIR_ABSTRACT_STORE_H */
