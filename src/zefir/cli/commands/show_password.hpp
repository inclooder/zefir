#ifndef ZEFIR_CLI_SHOW_PASSWORD_H
#define ZEFIR_CLI_SHOW_PASSWORD_H

#include <string>
#include "zefir/cli/command.hpp"
#include "zefir/repo.hpp"

namespace Zefir::Cli::Commands {
  class ShowPassword : public Command {
    public:
      ShowPassword(const std::string & name, Repo & repo);
      u32 execute() override;
    private:
      std::string name;
      Repo & repo;
  };
};

#endif /* end of include guard: ZEFIR_CLI_SHOW_PASSWORD_H */
