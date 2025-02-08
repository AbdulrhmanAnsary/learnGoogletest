#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <iostream>
#include <map>

class Database {
private:
  std::map<int, int> database;

public:
  void addData(int id, int age);
  int getData(int id) const;
  void printDatabase() const;
};

#endif // DATABASE_HPP
