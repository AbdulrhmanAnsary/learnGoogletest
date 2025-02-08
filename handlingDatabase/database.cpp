#include "database.hpp"

void Database::addData(int id, int age) {
  database[id] = age; // Update the data if an id is present
}

int Database::getData(int id) const {
  auto it = database.find(id);
  return (it != database.end()) ? it->second : -1; // If the id is't exist return -1
}

void Database::printDatabase() const {
  std::cout << "{\n";
  for (auto it = database.begin(); it != database.end(); ++it) {
    std::cout << "  " << it->first << " : " << it->second;
    if (std::next(it) != database.end())
      std::cout << ",\n";
  }
  std::cout << "\n}\n";
}
