#ifndef SQL_CIPHER_H
#define SQL_CIPHER_H

#include <string>
#include <stdexcept>
#include <sqlite3.h>

class SqlCipherException : public std::runtime_error {
  public:
    SqlCipherException(const std::string & message) : std::runtime_error(message) { }
};

class SqlCipher {
  public:
    SqlCipher(const std::string & dbPath);
    ~SqlCipher();
  private:
    sqlite3 * dbHandle;
};



#endif /* end of include guard: SQL_CIPHER_H */
