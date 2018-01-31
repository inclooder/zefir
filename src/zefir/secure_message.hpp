#ifndef ZEFIR_SECURE_MESSAGE_H
#define ZEFIR_SECURE_MESSAGE_H

#include <string>

namespace Zefir {
  class SecureMessage {
    public:
      virtual void setField(const std::string & name, const std::string & value) = 0;
      virtual ~SecureMessage() = 0;
  };
};



#endif /* end of include guard: ZEFIR_SECURE_MESSAGE_H */
