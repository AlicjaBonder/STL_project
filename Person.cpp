#include "Person.hpp"


Person::Person(const std::string & firstName,
               const std::string & lastName,
               const std::string & pesel,
               Gender gender,
               const std::string & address)
    : firstName_(firstName)
    , lastName_(lastName)
    , pesel_(pesel)
    , gender_(gender)
    , address_(address)
{}
