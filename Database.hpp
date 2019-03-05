#pragma once
#include <vector>
#include <functional>
#include "Person.hpp"
#include "Student.hpp"

using Persons = std::vector<Person*>;
using Students = std::vector<Student>;

struct NotFound : public std::out_of_range
{
    NotFound(const std::string & message);
};


class Database
{
  public:
    void addPerson(Person* person);
    void removeByPesel(const std::string &pesel);
    void removeStudent(int index);
    Persons findByLastName(const std::string &lastName) const;
    Person* findByPesel(const std::string &pesel) const;
    void show();
    void sortByName();
    void sortByPesel();
    void sortByIndex();
    void changeAddress(const std::string & pesel, const std::string & newAddress);
    void found(Persons);

  private:
    Persons persons_;
};
