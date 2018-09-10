#pragma once

#include <boost/program_options.hpp>

namespace Zefir {
  class App {
    public:
      App(int argc, char **argv);
      int run();
    private:
      bool parseArgs();
      void configureLogger();
      int argc;
      char **argv;
      boost::program_options::variables_map options;
  };
};
