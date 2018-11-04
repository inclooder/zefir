#include "zefir/secure_encryptor.hpp"
#include <cryptopp/modes.h>
#include <cryptopp/base64.h>
#include <iostream>
#include <iomanip>

using namespace CryptoPP;

namespace Zefir {
  SecureEncryptor::SecureEncryptor(const std::string & password) : key(0x00, AES::DEFAULT_KEYLENGTH), iv(AES::BLOCKSIZE) {
    AutoSeededRandomPool rnd;
    rnd.GenerateBlock(key, key.size());
    rnd.GenerateBlock(iv, iv.size());
  }

  std::string SecureEncryptor::encrypt(const std::string & payload) {
    CBC_Mode<AES>::Encryption encryptor;
    encryptor.SetKeyWithIV(key, sizeof(key), iv);

    std::string encrypted;
    StringSource(payload, true,
      new StreamTransformationFilter(encryptor,
        new Base64Encoder(
          new StringSink(encrypted)
        )
      )
    );
    return encrypted;
  }

  std::string SecureEncryptor::decrypt(const std::string & encrypted) {
    CBC_Mode<AES>::Decryption decryptor;
    decryptor.SetKeyWithIV(key, sizeof(key), iv);

    std::string decrypted;
    StringSource(encrypted, true,
      new Base64Decoder(
        new StreamTransformationFilter(decryptor,
          new StringSink(decrypted)
        )
      )
    );
    return decrypted;
  }
}
