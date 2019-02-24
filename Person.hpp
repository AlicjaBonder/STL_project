#pragma once
#include <string>

enum class Gender : const char
{
    Male = 'M',
    Female = 'F'
};

class Person
{
  public:
    Person(const std::string &name,
           const std::string &lastName,
           const std::string &pesel,
           Gender gender,
           const std::string &address);
    Person(const std::string &data);
    virtual ~Person() = default;

    std::string getLastName() const;
    std::string getPesel() const;
    void setAddress(const std::string &);
    virtual int getSalary() const;
    virtual void setSalary(unsigned int);
    virtual std::string to_string(char delimeter = ' ') const;

  private:
    std::string name_;
    std::string lastName_;
    std::string pesel_;
    Gender gender_;
    std::string address_;
};