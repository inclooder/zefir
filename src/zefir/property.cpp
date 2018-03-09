#include "zefir/property.hpp"

namespace Zefir {
  void Property::setId(u32 id) {
    this->id = id;
  }
  void Property::setName(const std::string & name) {
    this->name = name;
  }
  void Property::setValue(const std::string & value) {
    this->value = value;
  }
  u32 Property::getId() const {
    return id;
  }
  std::string Property::getName() const {
    return name;
  }
  std::string Property::getValue() const {
    return value;
  }
};
