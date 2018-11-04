#pragma once

#include <string>
#include <vector>
#include <filesystem>

namespace Zefir {
  class CommandsLog {
    public:
      CommandsLog(const std::filesystem::path & logsPath);
      void addCommand(const std::string & command);
      std::vector<std::string> getCommands() const;
    private:
      std::filesystem::path logsPath;
  };
}
