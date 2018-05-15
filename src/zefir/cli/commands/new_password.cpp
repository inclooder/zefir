#include "zefir/cli/commands/new_password.hpp"
#include "zefir/secret.hpp"

namespace Zefir::Cli::Commands {
  NewPassword::NewPassword(Repo * repo, Terminal * terminal) : repo(repo), terminal(terminal) {
  }

  u32 NewPassword::execute() {
    if(!hasValidInput()) return 1;

    Secret secret;
    secret.setName(terminal->readLine("Name: "));
    secret.setDescription(terminal->readLine("Description: "));
    secret.setPassword(terminal->readPassword("Password: "));
    repo->save(secret);
    return 0;
  }

  bool NewPassword::hasValidInput() {
    return input.compare("new") == 0;
  }
};
