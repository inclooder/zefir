#ifndef STORE_H
#define STORE_H

#include <string>
#include <vector>
#include "framework/types.hpp"
#include "zefir/secret.hpp"

namespace Zefir {
  class Store {
    public:
      virtual std::vector<Secret> getSecrets(u32 startIndex, u32 limit) = 0;
      virtual u32 countSecrets() = 0;
      virtual ~Store() {};
  };
};



#endif /* end of include guard: STORE_H */
