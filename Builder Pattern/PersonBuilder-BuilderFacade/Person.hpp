#pragma once

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

    static PersonBuilder create();

    friend std::ostream &operator<<(std::ostream &os, const Person &person);
};