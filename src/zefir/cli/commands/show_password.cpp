#include "zefir/cli/commands/show_password.hpp"
#include <iostream>

namespace Zefir::Cli::Commands {
  ShowPassword::ShowPassword(const std::string & name, Repo & repo) : repo(repo) {
    this->name = name;
  }

  u32 ShowPassword::execute() {
    auto secrets = repo.findByName(name);
    if(secrets.size() == 0) {
      std::cout << "No entry named: " << name << std::endl;
      return 1;
    }
    std::cout << secrets[0].getPassword() << std::endl;
    return 0;
  }
};
