
#include "Database.hpp"
#include "Student.hpp"

int main()
{
	Database db;
    Student jan("Jan", "Kowalski", "12345678",'M', "Rybacka 14/5", 111111);
    //Student jan("Jan", "Kowalski", 166666);
    db.addStudent(jan);
    Student ewa("Ewa", "Konieczna","23456789",'F',"Kielecka 34/2", 222222);
    //Student adam("Adam", "Adamski", 222222);
    db.addStudent(ewa);
    db.sortByIndex();
    db.removeStudent(111111);
    db.removeStudent(222222);
}
