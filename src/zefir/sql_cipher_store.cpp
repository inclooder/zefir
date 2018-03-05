#include "zefir/sql_cipher_store.hpp"

namespace Zefir {
  std::vector<Secret> SqlCipherStore::getSecrets(u32 startIndex, u32 limit) {
    return std::vector<Secret>();
  }
  u32 SqlCipherStore::countSecrets() {
    return 0;
  }
  SqlCipherStore::~SqlCipherStore() {
  }
};
