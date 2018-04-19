#include "zefir/cli/app.hpp"
#include "zefir/secret.hpp"
#include <iostream>
#include <regex>
#include "zefir/cli/commands/show_password.hpp"
#include <memory>

namespace Zefir::Cli {
  App::App(std::vector<std::string> args) {
  }

  i32 App::run() {
    std::string masterPassword = terminal.readPassword("Master password: ");
    std::shared_ptr<SqlCipher::Connection> db(new SqlCipher::Connection("zefir.db"));
    if(!db->setPassword(masterPassword)) {
      terminal.writeLine("Incorrect master password!");
      return 1;
    }
    Repo repo(db);
    this->repo = &repo;
    while(true) {
      auto input = terminal.readLine("zefir> ");
      if(input.compare("") == 0) {
        //Do nothing
      } else if(input.compare("quit") == 0 || input.compare("exit") == 0) {
        terminal.writeLine("Bye!");
        return 0;
      } else if(input.compare("list") == 0) {
        listSecrets();
      } else if(input.compare(0, 4, "show") == 0) {
        std::regex expression("^show\\s+(\\w+)\\s*$");
        std::smatch matches;
        if(std::regex_match(input, matches, expression)){
          Commands::ShowPassword(matches[1].str(), repo).execute();
        } else {
          terminal.writeLine("You need to specify the name!");
        }
      } else if(input.compare("new") == 0) {
        newSecret();
      } else {
        terminal.write("Unknown command: ");
        terminal.write(input);
        terminal.breakLine();
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
      terminal.write("NAME");
      terminal.write(delimiter);
      terminal.write("DESCRIPTION");
      terminal.breakLine();
    } else {
      return;
    }
    for(const auto & secret : secrets) {
      terminal.write(secret.getName());
      if(secret.getDescription().size() > 0) {
        terminal.write(delimiter);
        terminal.write(secret.getDescription());
      }
      terminal.breakLine();
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
