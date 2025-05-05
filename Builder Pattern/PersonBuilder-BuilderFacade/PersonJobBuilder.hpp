#pragma once

#include "PersonBuilder.hpp"
using namespace std;

class PersonJobBuilder: public PersonBuilderBase {
public:
    PersonJobBuilder(Person &p): PersonBuilderBase(p){}
    
    PersonJobBuilder& at(string company){
        person.company_name = company;
        return *this;
    }

    PersonJobBuilder& as_a(string role){
        person.position = role;
        return *this;
    }

    PersonJobBuilder& earning(int income){
        person.annual_income = income;
        return *this;
    }
};