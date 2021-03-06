#pragma once
#include "Person.hpp"
#include <string>


class Student : public Person
{
public:
    Student(const std::string & name,
            const std::string & lastName,
            const std::string & pesel,
            Gender gender,
            const std::string & address,
            int index);
 
    std::string to_string(char delimeter = ' ') const override;
    int getIndex() const override;

private:
    int index_;
};

