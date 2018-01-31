#include "zefir/sql_cipher_store.hpp"

namespace Zefir {
  void SqlCipherStore::add(const SecretMessage & message) {
  }
  bool SqlCipherStore::unlock(const std::string & password) {
    return true;
  }
  void SqlCipherStore::lock() {
  }
  SecretMessage SqlCipherStore::findByField(const std::string & name, const std::string & value) {
    return SecretMessage();
  }
  std::vector<SecretMessage> SqlCipherStore::all() {
    return std::vector<SecretMessage>();
  }
  SqlCipherStore::~SqlCipherStore() {
  }
};
