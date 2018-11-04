#include "zefir/repo.hpp"
#include "sql_cipher/statement.hpp"
#include <vector>

namespace Zefir {
  Repo::Repo(std::shared_ptr<SqlCipher::Connection> db) {
    this->db = db;
    commandsLog = std::make_unique<CommandsLog>("/tmp/abc");
    initDatabase();
  }

  bool Repo::save(Secret & secret) {
    auto st = db->statement("INSERT INTO secrets (name, description, password) VALUES (?, ?, ?)");
    st.setText(1, secret.getName());
    st.setText(2, secret.getDescription());
    st.setText(3, secret.getPassword());
    st.execute();
    commandsLog->addCommand(st.toSql());
    return true;
  }

  bool Repo::update(Secret & secret) {
    auto st = db->statement("UPDATE secrets SET name = ?, description = ?, password = ? WHERE id = ?");
    st.setText(1, secret.getName());
    st.setText(2, secret.getDescription());
    st.setText(3, secret.getPassword());
    st.setInt(4, secret.getId());
    st.execute();
    commandsLog->addCommand(st.toSql());
    return true;
  }

  bool Repo::save(std::vector<Secret> & secret) {
    return false;
  }

  std::vector<Secret> Repo::all() {
    std::vector<Secret> secrets;
    SqlCipher::Result result = db->execute("SELECT name, description, password FROM secrets;");
    auto rows = result.getRows();
    for(const auto & row : rows) {
      Secret secret;
      std::string name = std::get<std::string>(row.at(0));
      std::string description = std::get<std::string>(row.at(1));
      std::string password = std::get<std::string>(row.at(2));
      secret.setName(name);
      secret.setDescription(description);
      secret.setPassword(password);
      secrets.push_back(secret);
    }
    return secrets;
  }

  bool Repo::findById(Secret & secret) const {
    return false;
  }

  void Repo::initDatabase() {
    db->execute("DROP TABLE IF EXISTS secrets");
    db->execute("DROP TABLE IF EXISTS properties");
    db->execute(
      "CREATE TABLE IF NOT EXISTS secrets"
      "(id integer PRIMARY KEY, name text, description text, password text);"
    );
    db->execute(
      "CREATE TABLE IF NOT EXISTS properties"
      "(id integer PRIMARY KEY, secret_id integer, name text, value text);"
    );
    for(const auto & command : commandsLog->getCommands()) {
      db->execute(command);
    }
  }

  std::vector<Secret> Repo::searchByName(const std::string & name) {
    std::vector<Secret> secrets;
    auto st = db->statement("SELECT name, description, password FROM secrets WHERE name LIKE ?;");
    st.setText(1, "%" + name + "%");
    auto rows = st.execute().getRows();
    for(const auto & row : rows) {
      Secret secret;
      std::string name = std::get<std::string>(row.at(0));
      std::string description = std::get<std::string>(row.at(1));
      std::string password = std::get<std::string>(row.at(2));
      secret.setName(name);
      secret.setDescription(description);
      secret.setPassword(password);
      secrets.push_back(secret);
    }
    return secrets;
  }

  std::vector<Secret> Repo::findByName(const std::string & name) {
    std::vector<Secret> secrets;
    auto st = db->statement("SELECT id, name, description, password FROM secrets WHERE name = ?;");
    st.setText(1, name);
    auto rows = st.execute().getRows();
    for(const auto & row : rows) {
      Secret secret;
      int id = std::get<int>(row.at(0));
      std::string name = std::get<std::string>(row.at(1));
      std::string description = std::get<std::string>(row.at(2));
      std::string password = std::get<std::string>(row.at(3));
      secret.setId(id);
      secret.setName(name);
      secret.setDescription(description);
      secret.setPassword(password);
      secrets.push_back(secret);
    }
    return secrets;
  }
};
