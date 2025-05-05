#pragma once

#include "PersonBuilder.hpp"
using namespace std;

class PersonAddressBuilder: public PersonBuilderBase {
public:
    PersonAddressBuilder(Person &p): PersonBuilderBase(p){}
    PersonAddressBuilder& at_street(string street_address){
        person.street_address = street_address;
        return *this;
    }

    PersonAddressBuilder& with_postcode(string postcode){
        person.post_code = postcode;
        return *this;
    }

    PersonAddressBuilder& in(string city){
        person.city = city;
        return *this;
    }
};