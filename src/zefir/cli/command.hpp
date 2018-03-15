#ifndef ZEFIR_CLI_COMMAND_H
#define ZEFIR_CLI_COMMAND_H

#include <string>
#include "framework/types.hpp"

namespace Zefir::Cli {
  class Command {
    public:
      virtual ~Command() {};
      virtual u32 execute() = 0;
  };
};

#endif /* end of include guard: ZEFIR_CLI_COMMAND_H */
