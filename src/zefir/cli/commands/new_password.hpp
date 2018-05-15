#ifndef ZEFIR_CLI_NEW_PASSWORD_H
#define ZEFIR_CLI_NEW_PASSWORD_H

#include "zefir/cli/command.hpp"
#include "zefir/repo.hpp"
#include "zefir/cli/terminal.hpp"

namespace Zefir::Cli::Commands {
  class NewPassword : public Command {
    public:
      NewPassword(Repo * repo, Terminal * terminal);
      bool hasValidInput() override;
      u32 execute() override;
    private:
      Repo * repo;
      Terminal * terminal;
  };
};

#endif /* end of include guard: ZEFIR_CLI_NEW_PASSWORD_H */
