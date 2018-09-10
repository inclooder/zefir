#pragma once

#include <string>
#include <vector>
#include "framework/types.hpp"
#include "zefir/property.hpp"

namespace Zefir {
  class Secret {
    public:
      void setId(u32 id);
      void setName(const std::string & name);
      void setDescription(const std::string & description);
      void setPassword(const std::string & password);
      u32 getId() const;
      std::string getName() const;
      std::string getPassword() const;
      std::string getDescription() const;
      std::vector<Property> getProperties() const;
      void setProperties(std::vector<Property> properties);
    private:
      u32 id;
      std::string name;
      std::string password;
      std::string description;
      std::vector<Property> properties;
  };
};
