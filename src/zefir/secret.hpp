#ifndef SECRET_H
#define SECRET_H

#include <vector>
#include <string>
#include "framework/types.hpp"
#include "zefir/property.hpp"

namespace Zefir {
  class Secret {
    public:
      virtual std::vector<Property> getProperties(u32 startIndex, u32 limit) = 0;
      virtual Property & getPropertyByName(const std::string &  name) = 0;
      virtual u32 countProperties() = 0;
      virtual ~Secret() {};
  };
};



#endif /* end of include guard: SECRET_H */
