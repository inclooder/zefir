#pragma once

#include <string>
#include <vector>
#include <memory>
#include <boost/program_options.hpp>
#include "zefir/repo.hpp"
#include "framework/types.hpp"
#include "zefir/cli/terminal.hpp"
#include "zefir/cli/command.hpp"

namespace Zefir::Cli {
  class App {
    public:
      App(boost::program_options::variables_map options);
      i32 run();
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
