#include "zefir/cli/terminal.hpp"
#include <iostream>
#include <readline/readline.h>
#include <readline/history.h>
#include <termios.h>
#include <unistd.h>

namespace Zefir::Cli {
  Terminal::Terminal() {
    rl_bind_key('\t', rl_complete);
  }

  std::string Terminal::readPassword(const std::string & prompt) {
    std::cout << prompt;
    struct termios oldAttr, newAttr;
    tcgetattr(STDIN_FILENO, &oldAttr);
    newAttr = oldAttr;
    newAttr.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &newAttr);
    // TODO: add error checking
    std::string password;
    std::cin >> password;
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &oldAttr);
    std::cout << std::endl;
    return password;
  }

  std::string Terminal::readLine(const std::string & prompt) {
    char * input = readline(prompt.c_str());
    add_history(input);
    std::string strInput(input);
    free(input);
    return strInput;
  }

  void Terminal::writeLine(const std::string & line) {
    std::cout << line << std::endl;
  }

  void Terminal::write(const std::string & line) {
    std::cout << line;
  }

  void Terminal::breakLine() {
    std::cout << std::endl;
  }

  bool Terminal::yesNoQuestion(const std::string & question) {
    std::cout << question << " Y/N ";
    std::string answer;
    std::cin >> answer;
    return answer.compare("Y") == 0 || answer.compare("y") == 0;
  }
};
