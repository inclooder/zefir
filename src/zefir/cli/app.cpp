#include "zefir/cli/app.hpp"
#include "zefir/secret.hpp"
#include <iostream>
#include <regex>
#include "zefir/cli/commands/show_password.hpp"

namespace Zefir::Cli {
  App::App(std::vector<std::string> args) {
  }

  i32 App::run() {
    std::string masterPassword = terminal.readPassword("Master password: ");
    Repo repo(masterPassword);
    this->repo = &repo;
    while(true) {
      auto input = terminal.readLine("zefir> ");
      if(input.compare("") == 0) {
        //Do nothing
      } else if(input.compare("quit") == 0 || input.compare("exit") == 0) {
        std::cout << "Bye!" << std::endl;
        return 0;
      } else if(input.compare("list") == 0) {
        listSecrets();
      } else if(input.compare(0, 4, "show") == 0) {
        std::regex expression("^show\\s+(\\w+)\\s*$");
        std::smatch matches;
        if(std::regex_match(input, matches, expression)){
          Commands::ShowPassword(matches[1].str(), repo).execute();
        } else {
          std::cout << "You need to specify the name!" << std::endl;
        }
      } else if(input.compare("new") == 0) {
        newSecret();
      } else {
        std::cout << "Unknown command: " << input << std::endl;
      }
    }
    return 0;
  }

  App::~App() {
  }

  void App::listSecrets() {
    std::string delimiter = " - ";
    auto secrets = repo->all();
    if(secrets.size() > 0) {
      std::cout << "NAME" << delimiter << "DESCRIPTION" << std::endl;
    } else {
      return;
    }
    for(const auto & secret : secrets) {
      std::cout << secret.getName();
      if(secret.getDescription().size() > 0) {
        std::cout << delimiter << secret.getDescription();
      }
      std::cout << std::endl;
    }
  }

  void App::newSecret() {
    Secret secret;
    secret.setName(terminal.readLine("Name: "));
    secret.setDescription(terminal.readLine("Description: "));
    secret.setPassword(terminal.readPassword("Password: "));
    repo->save(secret);
  }
};
