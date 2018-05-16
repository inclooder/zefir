#include "zefir/cli/commands/new_password.hpp"
#include "zefir/secret.hpp"
#include "passwords/generator.hpp"

namespace Zefir::Cli::Commands {
  NewPassword::NewPassword(Repo * repo, Terminal * terminal) : repo(repo), terminal(terminal) {
  }

  u32 NewPassword::execute() {
    if(!hasValidInput()) return 1;

    Secret secret;
    secret.setName(terminal->readLine("Name: "));
    secret.setDescription(terminal->readLine("Description: "));
    bool generatePassword = terminal->yesNoQuestion("Would you like to generate the password?");

    std::string password;

    if(generatePassword) {
      Passwords::Generator generator;
      password = generator.generate();
    } else {
      password = terminal->readPassword("Password: ");
      auto passwordConfirmation = terminal->readPassword("Password Confirmation: ");
      if(password.compare(passwordConfirmation) != 0) {
        terminal->writeLine("Passwords must match!");
        return 2;
      }
    }

    secret.setPassword(password);
    repo->save(secret);
    return 0;
  }

  bool NewPassword::hasValidInput() {
    return input.compare("new") == 0;
  }
};
