#include "Person.hpp"
#include "PersonBuilder.hpp"

PersonBuilder Person::create() {
    return PersonBuilder();
}

ostream &operator<<(ostream &os, const Person &person) {
    return os << "street address: " << person.street_address << endl
              << "post code: " << person.post_code << endl
              << "city: " << person.city << endl
              << "company name: " << person.company_name << endl
              << "position: " << person.position << endl
              << "annual income: " << person.annual_income << endl;
}