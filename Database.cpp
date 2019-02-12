#include "Database.hpp"
#include <algorithm>

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
