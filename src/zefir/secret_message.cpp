#include "zefir/secret_message.hpp"

namespace Zefir {
  void SecretMessage::setField(const std::string & name, const std::string & value) {
    fields[name] = value;
  }

  std::string SecretMessage::getField(const std::string & name) const {
    return fields.at(name);
  }
};
