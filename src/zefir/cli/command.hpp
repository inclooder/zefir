#ifndef ZEFIR_CLI_COMMAND_H
#define ZEFIR_CLI_COMMAND_H

#include <string>
#include "framework/types.hpp"

namespace Zefir::Cli {
  class Command {
    public:
      virtual ~Command() {};
      void setInput(const std::string & input);
      virtual bool hasValidInput() = 0;
      virtual u32 execute() = 0;
    protected:
      std::string input;
  };
};

#endif /* end of include guard: ZEFIR_CLI_COMMAND_H */
