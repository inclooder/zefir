#ifndef SQL_CIPHER_H
#define SQL_CIPHER_H

#define SQLITE_HAS_CODEC
#include <sqlite3.h>
#include <string>
#include <stdexcept>

class SqlCipherException : public std::runtime_error {
  public:
    SqlCipherException(const std::string & message);
    virtual const char * what() const noexcept override;
  private:
    std::string fullMessage;
};

class SqlCipher {
  public:
    SqlCipher(const std::string & dbPath, const std::string & key);
    ~SqlCipher();
  private:
    sqlite3 * dbHandle;
};



#endif /* end of include guard: SQL_CIPHER_H */
