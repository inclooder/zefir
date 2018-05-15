#include "zefir/cli/commands/show_password.hpp"
#include <iostream>
#include <regex>

namespace Zefir::Cli::Commands {
  ShowPassword::ShowPassword(Repo * repo) : repo(repo) {
  }

  u32 ShowPassword::execute() {
    if(!hasValidInput()) return 1;

    std::regex expression("^show\\s+(\\w+)\\s*$");
    std::smatch matches;
    if(std::regex_match(input, matches, expression)){
      std::string name = matches[1].str();
      auto secrets = repo->findByName(name);
      if(secrets.size() == 0) {
        std::cout << "No entry named: " << name << std::endl;
        return 1;
      }
      std::cout << secrets[0].getPassword() << std::endl;
    } else {
      std::cout << "You need to specify the name!" << std::endl;
      return 2;
    }
    return 0;
  }

  bool ShowPassword::hasValidInput() {
    return input.compare(0, 4, "show") == 0;
  }
};
