#pragma once

#include <stdexcept>
#include <string>

namespace SqlCipher {
  class Error : public std::runtime_error {
    public:
      Error(const std::string & message);
      virtual const char * what() const noexcept override;
    private:
      std::string fullMessage;
  };
};
