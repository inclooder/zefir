#ifndef APP_H
#define APP_H

#include <string>
#include <vector>
#include "zefir/repo.hpp"
#include "framework/types.hpp"
#include "zefir/cli/terminal.hpp"

namespace Zefir::Cli {
  class App {
    public:
      App(std::vector<std::string> args);
      i32 run();
      ~App();
    private:
      void exit();
      void listSecrets();
      void newSecret();
      Repo * repo;
      Terminal terminal;
  };
};

#endif /* end of include guard: APP_H */
