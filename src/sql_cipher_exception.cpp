#include "sql_cipher.hpp"
#include <sstream>

SqlCipherException::SqlCipherException(const std::string & message) : std::runtime_error("") {
  std::ostringstream stream;
  stream << "[SqlCipherException] " << message;
  fullMessage = stream.str();
}

const char * SqlCipherException::what() const noexcept {
  return fullMessage.c_str();
}
