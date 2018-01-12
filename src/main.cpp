#include <iostream>
#include "sql_cipher/connection.hpp"

int main(int argc, char **argv) {
  try {
    SqlCipher::Connection db("zefir.db", "mypass");
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
    std::exit(EXIT_FAILURE);
  }

  return EXIT_SUCCESS;
}
