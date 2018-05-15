#include "zefir/cli/command.hpp"

namespace Zefir::Cli {
  void Command::setInput(const std::string & input) {
    this->input = input;
  }
};
