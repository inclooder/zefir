#include "zefir/app.hpp"
#include <iostream>
#define BOOST_LOG_DYN_LINK
#include <boost/log/expressions.hpp>
#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include "zefir/cli/app.hpp"
#include "zefir/gui/app.hpp"


namespace Zefir {
  App::App(int argc, char **argv) : argc(argc), argv(argv) {
    configureLogger();
  }

  int App::run() {
    try {
      return Gui::App(argc, argv).run();
    } catch (std::exception& e) {
      std::cerr << e.what() << std::endl;
      std::exit(EXIT_FAILURE);
      return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
  }

  void App::configureLogger() {
    namespace logging = boost::log;

    logging::core::get()->set_filter
    (
      logging::trivial::severity >= logging::trivial::info
    );
  }
};
