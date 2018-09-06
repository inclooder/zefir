#include "zefir/cli/app.hpp"
#include "zefir/secret.hpp"
#include <iostream>
#include <regex>
#include "zefir/cli/commands/show_password.hpp"
#include "zefir/cli/commands/new_password.hpp"
#include <memory>

namespace Zefir::Cli {
  App::App(int argc, char **argv) {
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
    initializeCommands();
    while(true) {
      auto input = terminal.readLine("zefir> ");

      if(input.compare("") == 0) {
        //Do nothing
      } else if(input.compare("quit") == 0 || input.compare("exit") == 0) {
        terminal.writeLine("Bye!");
        return 0;
      } else if(input.compare("list") == 0) {
        listSecrets();
      } else if(findAndExecuteCommand(input)) {
      } else {
        terminal.write("Unknown command: ");
        terminal.write(input);
        terminal.breakLine();
      }
    }
    return 0;
  }

  void App::initializeCommands() {
    std::shared_ptr<Command> show_password_command(new Commands::ShowPassword(this->repo));
    this->commands.push_back(show_password_command);

    std::shared_ptr<Command> new_password_command(new Commands::NewPassword(this->repo, &this->terminal));
    this->commands.push_back(new_password_command);
  }

  bool App::findAndExecuteCommand(const std::string & input) {
    for(auto & command : this->commands) {
      command->setInput(input);
      if(command->hasValidInput()) {
        command->execute();
        return true;
      }
    }
    return false;
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
