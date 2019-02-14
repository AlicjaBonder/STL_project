
#include "Database.hpp"
#include "Student.hpp"
#include <iostream>

int main()
{
    Database db;
    Student jan("Jan", "Kowalski", "12345678",Gender::Male, "Rybacka 14/5", 111111);
    db.addStudent(jan);
    Student ewa("Ewa", "Konieczna","23456789",Gender::Female,"Kielecka 34/2", 222222);
    Student george("George","Kwiatkowski","88031312475",Gender::Male,"Kniaziewicza 12/2",123456);

    db.addStudent(george);
    db.addStudent(ewa);
    db.show();
    db.sortByName();
    std::cout<<std::endl; 
    db.show();
    db.findByLastName("Kowalski");
    db.changeAddress("12345678","Zmieniona 1/1");
     db.show();
    db.removeStudent(111111);
  

}
