#pragma once

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
      bool yesNoQuestion(const std::string & question);
  };
};
