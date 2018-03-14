#include "zefir/cli/app.hpp"
#include <readline/readline.h>
#include <readline/history.h>
#include "zefir/secret.hpp"
#include <iostream>
#include <regex>
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
      } else if(input.compare(0, 4, "show") == 0) {
        std::regex expression("^show\\s+(\\w+)\\s*$");
        std::smatch matches;
        if(std::regex_match(input, matches, expression)){
          showPassword(matches[1].str());
        } else {
          std::cout << "You need to specify the name!" << std::endl;
        }
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

  void App::showPassword(const std::string & name) {
    auto secrets = repo->findByName(name);
    if(secrets.size() == 0) {
      std::cout << "No entry named: " << name << std::endl;
      return;
    }
    std::cout << secrets[0].getPassword() << std::endl;
  }

  void App::newSecret() {
    Secret secret;
    secret.setName(readLine("Name: "));
    secret.setDescription(readLine("Description: "));
    secret.setPassword(readPassword("Password: "));
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
