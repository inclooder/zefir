#pragma once

#include <string>
#include <vector>
#include <filesystem>
#include "zefir/secure_encryptor.hpp"

namespace Zefir {
  class CommandsLog {
    public:
      CommandsLog(const std::filesystem::path & logsPath);
      void addCommand(const std::string & command);
      std::vector<std::string> getCommands() const;
    private:
      std::filesystem::path logsPath;
      std::vector<std::filesystem::path> getLogFiles() const;
      std::unique_ptr<SecureEncryptor> encryptor;
  };
}
