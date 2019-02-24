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
    void sortByIndex();
    void removeStudent(int index);
    void removeByPesel(const std::string &pesel);

    Persons findByLastName(const std::string &lastName) const;
    Person* findByPesel(const std::string &pesel) const;
    void show();
    void sortByName();
    void sortByPesel();
    void changeAddress(const std::string & pesel, const std::string & newAddress);
    void found(Persons);

  private:
    Persons persons_;
    Students students_;
};
