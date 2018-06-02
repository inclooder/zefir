#ifndef APP_H
#define APP_H

#include <string>
#include <vector>
#include <memory>
#include "zefir/repo.hpp"
#include "framework/types.hpp"
#include "zefir/cli/terminal.hpp"
#include "zefir/cli/command.hpp"

namespace Zefir::Cli {
  class App {
    public:
      App();
      i32 run();
      ~App();
    private:
      void initializeCommands();
      bool findAndExecuteCommand(const std::string & input);
      void exit();
      void listSecrets();
      void newSecret();
      Repo * repo;
      Terminal terminal;
      std::vector<std::shared_ptr<Zefir::Cli::Command>> commands;
  };
};

#endif /* end of include guard: APP_H */
