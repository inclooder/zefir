#include "sql_cipher.hpp"

SqlCipher::SqlCipher(const std::string & dbPath) {
  if(SQLITE_OK != sqlite3_open(dbPath.c_str(), &dbHandle)){
    const char * errorMessage = sqlite3_errmsg(dbHandle);
    throw SqlCipherException(errorMessage);
  }
}

SqlCipher::~SqlCipher(){
  sqlite3_close(dbHandle);
}
