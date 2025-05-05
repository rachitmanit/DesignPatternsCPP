#include<iostream>
using namespace std;

class PersonBuilder;

class Person {
    // address
    string street_address, post_code, city;

    // employment
    string company_name, position;
    int annual_income{0};

public:
    friend class PersonBuilder;
    friend class PersonJobBuilder;
    friend class PersonAddressBuilder;

    PersonBuilder Person::create() {
        return PersonBuilder();
    }
    
    friend ostream &operator<<(ostream &os, const Person &person) {
        return os << "street address: " << person.street_address << endl
                  << "post code: " << person.post_code << endl
                  << "city: " << person.city << endl
                  << "company name: " << person.company_name << endl
                  << "position: " << person.position << endl
                  << "annual income: " << person.annual_income << endl;
    }
};