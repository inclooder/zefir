#include "zefir/commands_log.hpp"

#include <fstream>
#include <sstream>
#include <ctime>
#include <iostream>
#include <algorithm>

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
    for(const auto & path : getLogFiles()) {
      std::ifstream log(path);
      std::string line;
      while(std::getline(log, line)) {
        commands.push_back(line);
      }
    }
    return commands;
  }

  std::vector<std::filesystem::path> CommandsLog::getLogFiles() const {
    std::vector<std::filesystem::path> files;
    for(auto& entry: std::filesystem::directory_iterator(logsPath)) {
      if(!entry.is_regular_file()) continue;
      files.push_back(entry.path());
    }
    std::sort(files.begin(), files.end());
    return files;
  }
}
