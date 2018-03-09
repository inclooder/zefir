#ifndef PROPERTY_H
#define PROPERTY_H

#include <string>
#include "framework/types.hpp"

namespace Zefir {
  class Property {
    public:
      void setId(u32 id);
      void setName(const std::string & name);
      void setValue(const std::string & value);
      u32 getId() const;
      std::string getName() const;
      std::string getValue() const;
    private:
      u32 id;
      std::string name;
      std::string value;
  };
};

#endif /* end of include guard: PROPERTY_H */
