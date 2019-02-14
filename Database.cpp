#include "Database.hpp"
#include "Student.hpp"
#include <algorithm>
#include <iostream>
#include <functional>
#include <fstream>

void Database::addStudent(const Student & student)
{
    students_.push_back(student);
}
void Database::sortByIndex()
{
    std::sort(begin(students_), end(students_), [](const auto & lhs, const auto & rhs){
        return lhs.getIndex() < rhs.getIndex();
    });
}

void Database::removeStudent(int index)
{
    auto iter = std::find_if(begin(students_), end(students_), [index](const auto & student){
        return student.getIndex() == index;
    });
    if (iter != end(students_))
    {
        students_.erase(iter);
    }
}
 void Database::removeByPesel(const std::string &pesel)
 {
     auto iter = std::find_if(begin(students_), end(students_), [pesel](const auto & student){
        return student.getPesel() == pesel;
    });
    if (iter != end(students_))
    {
        students_.erase(iter);
    }
 }

Students Database::findByLastName(const std::string & lastName) const
{
    std::vector<Student> matching;
    std::copy_if(students_.begin(), students_.end(), std::back_inserter(matching), [lastName]( const auto & item)
    {
        return item.getLastName() == lastName;
    });
    return matching;
}


void Database::show() 
{
    
    for( Student person : students_)
    {
        std::cout << person.to_string();
    }
}
void Database::sortByName()
{
    std::sort(students_.begin(), students_.end(), [](Student lhs, Student rhs)
    {
        return lhs.getLastName() < rhs.getLastName();
    });
}
void Database::sortByPesel()
{
    std::sort(students_.begin(), students_.end(), [](Student lhs, Student rhs)
    {
        return lhs.getPesel() < rhs.getPesel();
    });
}

void Database::changeAddress(const std::string & pesel, const std::string & newAddress){

  auto iter = std::find_if(begin(students_), end(students_), [pesel](const auto & student){
        return student.getPesel() == pesel;
    });
    if (iter != end(students_))
    {
        auto person = iter;
        person->setAddress(newAddress);
    }
}

