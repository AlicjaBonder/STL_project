#pragma once
#include "Student.hpp"
#include <vector>

using Students = std::vector<Student>;

class Database
{
public:
    void addStudent(const Student & student);
    void sortByIndex();
    void removeStudent(int index);

private:
    Students students_;
};
