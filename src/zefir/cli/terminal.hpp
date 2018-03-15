#ifndef ZEFIR_CLI_TERMINAL_H
#define ZEFIR_CLI_TERMINAL_H

#include <string>

namespace Zefir::Cli {
  class Terminal {
    public:
      Terminal();
      std::string readPassword(const std::string & prompt);
      std::string readLine(const std::string & prompt);
  };
};

#endif /* end of include guard: ZEFIR_CLI_TERMINAL_H */
