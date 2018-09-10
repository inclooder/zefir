#pragma once

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
