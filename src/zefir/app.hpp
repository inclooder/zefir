#ifndef ZEFIR_APP_H
#define ZEFIR_APP_H

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

#endif /* end of include guard: ZEFIR_APP_H */
