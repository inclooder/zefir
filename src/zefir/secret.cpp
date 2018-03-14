#include "zefir/secret.hpp"

namespace Zefir {
  void Secret::setId(u32 id) {
    this->id = id;
  }
  void Secret::setName(const std::string & name) {
    this->name = name;
  }
  void Secret::setPassword(const std::string & password) {
    this->password = password;
  }
  void Secret::setDescription(const std::string & description) {
    this->description = description;
  }
  u32 Secret::getId() const {
    return id;
  }
  std::string Secret::getName() const {
    return name;
  }
  std::string Secret::getPassword() const {
    return password;
  }
  std::string Secret::getDescription() const {
    return description;
  }
  std::vector<Property> Secret::getProperties() const {
    return properties;
  }

  void Secret::setProperties(std::vector<Property> properties) {
  }
};
