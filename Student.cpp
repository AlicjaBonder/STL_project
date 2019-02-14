#include "Student.hpp"
#include <sstream>

Student::Student(const std::string &name,
                 const std::string &lastName,
                 const std::string &pesel,
                 Gender gender,
                 const std::string &address,
                 int index)
    : name_(name), lastName_(lastName), pesel_(pesel), gender_(gender), address_(address), index_(index)
{
}
int Student::getIndex() const
{
    return index_;
}

std::string Student::getLastName() const
{
    return lastName_;
}
std::string Student::getPesel() const
{
    return pesel_;
}

void Student::setAddress(const std::string &newAddress)
{
    address_ = newAddress;
}

std::string Student::to_string(char delimeter) const
{
    std::stringstream ss;
    ss << name_ << delimeter
       << lastName_ << delimeter
       << pesel_ << delimeter
       << static_cast<char>(gender_) << delimeter
       << address_ << delimeter;

    return ss.str();
}
