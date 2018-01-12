#include "sql_cipher.hpp"
#include <iostream>

SqlCipher::SqlCipher(const std::string & dbPath, const std::string & key) {
  if(SQLITE_OK != sqlite3_open(dbPath.c_str(), &dbHandle)){
    const char * errorMessage = sqlite3_errmsg(dbHandle);
    throw SqlCipherException(errorMessage);
  }
  auto retVal = sqlite3_key(dbHandle, key.c_str(), key.size());
  std::cout << "sqlite3_key return value = " << retVal << std::endl;
}

SqlCipher::~SqlCipher(){
  sqlite3_close(dbHandle);
}
