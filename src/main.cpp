#include <iostream>
#include "sql_cipher/connection.hpp"
#include "sql_cipher/result.hpp"
#include "sql_cipher/statement.hpp"
#include <boost/log/expressions.hpp>
#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>

#include "zefir/repo.hpp"
#include "zefir/cli/app.hpp"

namespace logging = boost::log;

void configureLogger() {
  logging::core::get()->set_filter
  (
    logging::trivial::severity >= logging::trivial::info
  );
}

using namespace Zefir;

int main(int argc, char **argv) {
  configureLogger();
  try {
    std::vector<std::string> args;
    Cli::App app(args);
    return app.run();
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
    std::exit(EXIT_FAILURE);
  }

  return EXIT_SUCCESS;
}
