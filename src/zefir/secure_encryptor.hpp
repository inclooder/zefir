#pragma once

#include <string>
#include <cryptopp/rsa.h>
#include <cryptopp/cryptlib.h>
#include <cryptopp/osrng.h>

namespace Zefir {
  class SecureEncryptor {
    public:
      SecureEncryptor(const std::string & password);
      std::string encrypt(const std::string & payload);
      std::string decrypt(const std::string & encrypted);
    private:
      CryptoPP::SecByteBlock key;
      CryptoPP::SecByteBlock iv;
  };
}
