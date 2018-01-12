#include "sql_cipher/error.hpp"
#include <sstream>

namespace SqlCipher {
  Error::Error(const std::string & message) : std::runtime_error("") {
    std::ostringstream stream;
    stream << "[SqlCipherException] " << message;
    fullMessage = stream.str();
  }

  const char * Error::what() const noexcept {
    return fullMessage.c_str();
  }
};
