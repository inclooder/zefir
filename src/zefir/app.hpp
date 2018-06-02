#ifndef ZEFIR_APP_H
#define ZEFIR_APP_H

namespace Zefir {
  class App {
    public:
      App(int argc, char **argv);
      int run();
    private:
      void configureLogger();
      int argc;
      char **argv;
  };
};

#endif /* end of include guard: ZEFIR_APP_H */
