#include "Person.hpp"
#include <sstream>

Person::Person(const std::string &name,
               const std::string &lastName,
               const std::string &pesel,
               Gender gender,
               const std::string &address)
    : name_(name), lastName_(lastName), pesel_(pesel), gender_(gender), address_(address)
{
}

std::string Person::getLastName() const
{
    return lastName_;
}

std::string Person::getPesel() const
{
    return pesel_;
}

int Person::getIndex() const{
    return 0;
}

void Person::setAddress(const std::string &newAddress)
{
    address_ = newAddress;
}

std::string Person::to_string(char delimeter) const
{
    std::stringstream ss;
    ss << name_ << delimeter
       << lastName_ << delimeter
       << pesel_ << delimeter
       << static_cast<char>(gender_) << delimeter
       << address_ << delimeter;
    return ss.str();
}