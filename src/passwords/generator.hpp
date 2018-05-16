#ifndef PASSWORDS_GENERATOR_H
#define PASSWORDS_GENERATOR_H

#include <string>

namespace Passwords {
  class Generator {
    public:
      Generator();
      std::string generate() const;
  };
};

#endif /* end of include guard: PASSWORDS_GENERATOR_H */

