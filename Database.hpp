#pragma once
#include <vector>
#include <functional>
#include "Student.hpp"

using Students = std::vector<Student>;

class Database
{
  public:
    void addStudent(const Student &student);
    void sortByIndex();
    void removeStudent(int index);
    void removeByPesel(const std::string &pesel);

    Students findByLastName(const std::string &lastName) const;
    Students findByPesel(const std::string &pesel) const;
    void show();
    void sortByName();
    void sortByPesel();
    void changeAddress(const std::string & pesel, const std::string & newAddress);

  private:
    Students students_;
};
