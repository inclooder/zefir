#ifndef SQL_CIPHER_ERROR_H
#define SQL_CIPHER_ERROR_H

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

#endif /* end of include guard: ERROR_H */


