#ifndef PROPERTY_H
#define PROPERTY_H

#include <string>

namespace Zefir {
  class Property {
    public:
      virtual std::string getName() = 0;
      virtual std::string getType() = 0;
      virtual std::string getValue() = 0;
      virtual ~Property() {};
  };
};


#endif /* end of include guard: PROPERTY_H */
