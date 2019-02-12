#include "Student.hpp"


Student::Student(const std::string & firstName,
                 const std::string & lastName,
                 const std::string & pesel,
                 Gender gender,
                 const std::string & address,
                 int index)
    : Person(firstName, lastName, pesel, gender, address)
    , index_(index)
{}
int Student::getIndex() const
{
    return index_;
}


