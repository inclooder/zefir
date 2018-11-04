#include "zefir/commands_log.hpp"

#include <fstream>
#include <sstream>
#include <ctime>
#include <iostream>

namespace Zefir {
  CommandsLog::CommandsLog(const std::filesystem::path & logsPath) : logsPath(logsPath) {
  }
  void CommandsLog::addCommand(const std::string & command) {
    std::time_t now = std::time(nullptr);
    std::stringstream fileName;
    fileName << now;
    auto filePath = logsPath / fileName.str();
    std::ofstream log(filePath);
    log << command;
  }
  std::vector<std::string> CommandsLog::getCommands() const {
    std::vector<std::string> commands;
    for(auto& entry: std::filesystem::directory_iterator(logsPath)) {
      if(!entry.is_regular_file()) continue;
      std::ifstream log(entry.path());
      std::string line;
      while(std::getline(log, line)) {
        commands.push_back(line);
      }
    }
    return commands;
  }
}
