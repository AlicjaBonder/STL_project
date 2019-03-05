#include "Database.hpp"
#include "Student.hpp"
#include <algorithm>
#include <iostream>
#include <functional>
#include <fstream>

NotFound::NotFound(const std::string &message)
    : std::out_of_range(message)
{
}

void Database::addPerson(Person *person)
{
    persons_.push_back(person);
}
void Database::sortByIndex()
{
    std::sort(begin(persons_), end(persons_), [](const auto &lhs, const auto &rhs) {
        return lhs->getIndex() < rhs->getIndex();
    });
}
void Database::removeStudent(int index)
{
    auto iter = std::find_if(begin(persons_), end(persons_), [index](const auto &student) {
        return student->getIndex() == index;
    });
    if (iter != end(persons_))
    {
        persons_.erase(iter);
    }
}
void Database::removeByPesel(const std::string &pesel)
{
    auto iter = std::find_if(begin(persons_), end(persons_), [pesel](const auto &person) {
        return person->getPesel() == pesel;
    });
    if (iter != end(persons_))
    {
        persons_.erase(iter);
    }
}

Persons Database::findByLastName(const std::string &lastName) const
{
    std::vector<Person *> matching;
    std::copy_if(persons_.begin(), persons_.end(), std::back_inserter(matching), [lastName](const auto &item) {
        return item->getLastName() == lastName;
    });
    return matching;
}

void Database::show()
{

    for (const auto person : persons_)
    {
        std::cout << person->to_string();
    }
}
void Database::sortByName()
{
    std::sort(persons_.begin(), persons_.end(), [](Person lhs, Person rhs) {
        return lhs.getLastName() < rhs.getLastName();
    });
}
void Database::sortByPesel()
{
    std::sort(persons_.begin(), persons_.end(), [](Person lhs, Person rhs) {
        return lhs.getPesel() < rhs.getPesel();
    });
}
Person* Database::findByPesel(const std::string &pesel) const
{
    auto iter = std::find_if(begin(persons_), end(persons_), [pesel](const auto &person) {
        return person.getPesel() == pesel;
    });

    if(iter != end(persons_)){
        return *iter;
    }
    throw NotFound("Does not exist");
}

void Database::changeAddress(const std::string &pesel, const std::string &newAddress)
{

    auto person = findByPesel(pesel);
    person->setAddress(newAddress);
}
