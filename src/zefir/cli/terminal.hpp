#ifndef ZEFIR_CLI_TERMINAL_H
#define ZEFIR_CLI_TERMINAL_H

#include <string>

namespace Zefir::Cli {
  class Terminal {
    public:
      Terminal();
      std::string readPassword(const std::string & prompt);
      std::string readLine(const std::string & prompt);
      void writeLine(const std::string & line);
      void write(const std::string & line);
      void breakLine();
  };
};

#endif /* end of include guard: ZEFIR_CLI_TERMINAL_H */
