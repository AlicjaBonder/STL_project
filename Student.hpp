#pragma once

#include <string>

enum class Gender : const char
{
    Male = 'M',
    Female = 'F'
};

class Student
{
  public:
    Student(const std::string &name,
            const std::string &lastName,
            const std::string &pesel,
            Gender gender,
            const std::string &address,
            int index);

    int getIndex() const;

    std::string getLastName() const;
    std::string getPesel() const;
    void setAddress(const std::string &);
    std::string to_string(char delimeter = ' ') const;

  private:
    int index_;
    std::string name_;
    std::string lastName_;
    std::string pesel_;
    Gender gender_;
    std::string address_;
};
