#ifndef APP_H
#define APP_H

#include <string>
#include <vector>
#include "zefir/repo.hpp"
#include "framework/types.hpp"

namespace Zefir::Cli {
  class App {
    public:
      App(std::vector<std::string> args);
      i32 run();
      ~App();
    private:
      void exit();
      std::string readLine(const std::string & prompt = "zefir> ");
      std::string readPassword(const std::string & prompt = "zefir> ");
      void listSecrets();
      void newSecret();
      Repo * repo;
  };
};

#endif /* end of include guard: APP_H */
