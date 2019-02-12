//#include "database.hpp"
/*#include "Student.hpp"



int main()
{
    Database db;
    Student jan("Jan", "Kowalski", "Rybacka 14/5", "12345678",'M', 111111);
    db.addStudent(jan);
    Student adam("Ewa", "Konieczna","Kielecka 34/2","23456789",'F', 222222);
    db.addStudent(adam);
    db.sortByIndex();
    db.removeStudent(111111);
    db.removeStudent(222222);
}

*/



#include "Database.hpp"
#include "Student.hpp"

int main()
{
    Database db;
    Student jan("Jan", "Kowalski", 166666);
    db.addStudent(jan);
    Student adam("Adam", "Adamski", 222222);
    db.addStudent(adam);
    db.sortByIndex();
    db.removeStudent(111111);
    db.removeStudent(222222);
}
