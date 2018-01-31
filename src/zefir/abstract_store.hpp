#ifndef ZEFIR_ABSTRACT_STORE_H
#define ZEFIR_ABSTRACT_STORE_H

#include "zefir/secret_message.hpp"
#include <vector>
#include <memory>

namespace Zefir {
  class AbstractStore {
    public:
      virtual void add(const AbstractMessage & message) = 0;
      virtual bool unlock(const std::string & password) = 0;
      virtual void lock() = 0;
      virtual SecureMessage findByField(const std::string & name, const std::string & value) = 0;
      virtual std::vector<SecureMessage> all() = 0;
      virtual ~SecureStore() = 0;
  };
};


#endif /* end of include guard: ZEFIR_ABSTRACT_STORE_H */
