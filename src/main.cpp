#include <iostream>
#include <sql_cipher.hpp>

int main(int argc, char **argv) {
  try {
    SqlCipher db("zefir.db", "mypass");
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
    std::exit(EXIT_FAILURE);
  }

  return EXIT_SUCCESS;
}
