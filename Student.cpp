#include "Student.hpp"
#include <sstream>

Student::Student(const std::string &name,
                 const std::string &lastName,
                 const std::string &pesel,
                 Gender gender,
                 const std::string &address,
                 int index)
    : Person(name, lastName, pesel, gender, address), index_(index)
{
}

int Student::getIndex() const
{
    return index_;
}

std::string Student::to_string(char delimeter) const
{
    std::stringstream ss;
    ss << Person::to_string(delimeter)
       << index_ << delimeter;

    return ss.str();
}
