
#include "Database.hpp"
#include "Student.hpp"
#include <iostream>
#include "PeselValidation.hpp"
#include <cassert>

int main()
{
    assert(not isPeselValid("1234567a901", Gender::Female) && "not a digit");
    assert(not isPeselValid("12345678901", Gender::Female) && "invalid month");
    assert(not isPeselValid("12325678901", Gender::Female) && "invalid day");
    assert(not isPeselValid("03222978901", Gender::Female) && "not leap year");
    assert(not isPeselValid("04222978911", Gender::Female) && "not a female");
    assert(not isPeselValid("04222978901", Gender::Male) && "not a male");
    assert(not isPeselValid("04222978901", Gender::Female) && "invalid checksum");
    assert(isPeselValid("04222978907", Gender::Female) && "valid");

    Database db;

    Person *jan = new Student("Jan", "Kowalski", "12345678", Gender::Male, "Rybacka 14/5", 111111);
    db.addPerson(jan);
    Person *ewa = new Student("Ewa", "Konieczna", "23456789", Gender::Female, "Kielecka 34/2", 222222);
    Person *george = new Student("George", "Kwiatkowski", "88031312475", Gender::Male, "Kniaziewicza 12/2", 123456);

    db.addPerson(george);
    Person *alicja = new Student("Alicja", "Potrzebna", "90102005987", Gender::Female, "Szczesliwa 22/3", 112233);
    db.addPerson(ewa);
    db.addPerson(alicja);
    db.show();
    db.sortByName();
    std::cout << std::endl;
    std::cout << "after sorting" << std::endl;
    db.show();
    auto kowalski = db.findByPesel("12345678");

    db.changeAddress("12345678", "Zmieniona 1/1");
    std::cout << "after change address" << std::endl;
    db.show();
    db.removeStudent(123456);
    std::cout << "after remove" << std::endl;
    db.show();

    return 0;
}
