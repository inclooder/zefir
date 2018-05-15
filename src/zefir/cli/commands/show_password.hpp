#ifndef ZEFIR_CLI_SHOW_PASSWORD_H
#define ZEFIR_CLI_SHOW_PASSWORD_H

#include <string>
#include "zefir/cli/command.hpp"
#include "zefir/repo.hpp"

namespace Zefir::Cli::Commands {
  class ShowPassword : public Command {
    public:
      ShowPassword(Repo * repo);
      bool hasValidInput() override;
      u32 execute() override;
    private:
      Repo * repo;
  };
};

#endif /* end of include guard: ZEFIR_CLI_SHOW_PASSWORD_H */
