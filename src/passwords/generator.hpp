#ifndef PASSWORDS_GENERATOR_H
#define PASSWORDS_GENERATOR_H

#include <string>
#include <unordered_set>

namespace Passwords {
  class Generator {
    public:
      Generator();
      std::string generate() const;
      std::unordered_set<char> getAvailableCharacters() const;
  };
};

#endif /* end of include guard: PASSWORDS_GENERATOR_H */

