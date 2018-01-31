#include <iostream>
#include "sql_cipher/connection.hpp"

int main(int argc, char **argv) {
  try {
    SqlCipher::Connection db("zefir.db", "mypass");
    db.execute("DROP TABLE IF EXISTS numbers;");
    db.execute("CREATE TABLE IF NOT EXISTS numbers(id integer PRIMARY KEY, name text);");
    db.execute("INSERT INTO numbers (name) VALUES ('jeden'), ('dwa'), ('trzy');");
    db.execute("SELECT * FROM numbers;");
    db.execute("SELECT count(*) FROM sqlite_master;");
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
    std::exit(EXIT_FAILURE);
  }

  return EXIT_SUCCESS;
}
