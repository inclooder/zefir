#include "zefir/cli/app.hpp"
#include <readline/readline.h>
#include <readline/history.h>
#include "zefir/secret.hpp"
#include <iostream>
#include <termios.h>


namespace Zefir::Cli {
  App::App(std::vector<std::string> args) {
    rl_bind_key('\t', rl_complete);
  }

  i32 App::run() {
    std::string masterPassword = readPassword("Master password: ");
    Repo repo(masterPassword);
    this->repo = &repo;
    while(true) {
      auto input = readLine();
      if(input.compare("") == 0) {
        //Do nothing
      } else if(input.compare("quit") == 0 || input.compare("exit") == 0) {
        std::cout << "Bye!" << std::endl;
        return 0;
      } else if(input.compare("list") == 0) {
        listSecrets();
      } else if(input.compare("new") == 0) {
        newSecret();
      } else {
        std::cout << "Unknown command: " << input << std::endl;
      }
    }
    return 0;
  }

  App::~App() {
  }

  std::string App::readLine(const std::string & prompt) {
    char * input = readline(prompt.c_str());
    add_history(input);
    std::string strInput(input);
    free(input);
    return strInput;
  }

  void App::listSecrets() {
    std::string delimiter = " - ";
    auto secrets = repo->all();
    if(secrets.size() > 0) {
      std::cout << "NAME" << delimiter << "DESCRIPTION" << std::endl;
    } else {
      return;
    }
    for(const auto & secret : secrets) {
      std::cout << secret.getName();
      if(secret.getDescription().size() > 0) {
        std::cout << delimiter << secret.getDescription();
      }
      std::cout << std::endl;
    }
  }

  void App::newSecret() {
    Secret secret;
    secret.setName(readLine("Name: "));
    secret.setDescription(readLine("Description: "));
    readPassword("Password: ");
    repo->save(secret);
  }

  std::string App::readPassword(const std::string & prompt) {
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
};
