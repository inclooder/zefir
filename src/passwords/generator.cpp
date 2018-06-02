#include "passwords/generator.hpp"
#include <cstdlib>
#include <algorithm>
#include <random>

namespace Passwords {
  Generator::Generator() {}
  std::string Generator::generate() const {
    auto chars = getAvailableCharacters();

    std::random_device seeder;
    std::mt19937 rng(seeder());
    std::uniform_int_distribution<int> distribution(10, 15);
    int passwordLength = distribution(rng);

    std::string generated;
    std::sample(chars.begin(), chars.end(), std::back_inserter(generated), passwordLength, rng);
    return generated;
  }

  std::unordered_set<char> Generator::getAvailableCharacters() const {
    static const std::string characters = "`1234567890-=~!@#$%^&*()qwertyuiop[]QWERTYUIOP{}aghjkl;'ASDFGHJKL:zxcvbnm,./ZXCVBNM<>?";
    std::unordered_set<char> availableChars;

    for(const char & character : characters) {
      availableChars.insert(character);
    }
    return availableChars;
  }
};
