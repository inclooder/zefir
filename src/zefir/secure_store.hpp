#ifndef ZEFIR_SECURE_STORE_H
#define ZEFIR_SECURE_STORE_H

#include "zefir/secure_message.hpp"
#include <vector>
#include <memory>

namespace Zefir {
  class SecureStore {
    public:
      virtual void add(const SecureMessage & message) = 0;
      virtual std::unique_ptr<SecureMessage> findByField(const std::string & name, const std::string & value) = 0;
      virtual std::vector<SecureMessage> all() = 0;
      virtual ~SecureStore() = 0;
  };
};


#endif /* end of include guard: ZEFIR_SECURE_STORE_H */
