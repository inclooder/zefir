#ifndef ZEFIR_SECRET_MESSAGE_H
#define ZEFIR_SECRET_MESSAGE_H

#include <string>
#include <map>

namespace Zefir {
  class SecretMessage {
    public:
      void setField(const std::string & name, const std::string & value);
      std::string getField(const std::string & name) const;
    private:
      std::map<std::string, std::string> fields;
  };
};

#endif /* end of include guard: ZEFIR_SECRET_MESSAGE_H */
