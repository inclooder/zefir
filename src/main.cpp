#include <iostream>
#include "sql_cipher/connection.hpp"
#include "sql_cipher/result.hpp"
#include "sql_cipher/statement.hpp"
#include <boost/log/expressions.hpp>
#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>

namespace logging = boost::log;

void configureLogger() {
  /* logging::core::get()->set_filter */
  /* ( */
  /*   logging::trivial::severity >= logging::trivial::info */
  /* ); */
}


int main(int argc, char **argv) {
  configureLogger();
  try {
    SqlCipher::Connection db("zefir.db");
    db.setPassword("mypass");
    db.execute("DROP TABLE IF EXISTS numbers;");
    db.execute("CREATE TABLE IF NOT EXISTS numbers(id integer PRIMARY KEY, name text);");
    db.execute("INSERT INTO numbers (name) VALUES ('jeden'), ('dwa'), ('trzy');");

    SqlCipher::Statement st = db.statement("SELECT * FROM numbers WHERE name = ?;");
    st.setText(1, "dwa");
    st.execute();
    SqlCipher::Result result = db.execute("SELECT * FROM numbers;");
    auto columns = result.getColumns();
    for(auto& column : columns) {
      std::cout << column << " ";
    }
    std::cout << std::endl;
    auto rows = result.getRows();
    for(auto& row : rows) {
      for(auto& entry : row) {
        std::visit([](const auto &val) {
            std::cout << val << std::endl;
        }, entry);
      }
      std::cout << std::endl;
    }
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
    std::exit(EXIT_FAILURE);
  }

  return EXIT_SUCCESS;
}
