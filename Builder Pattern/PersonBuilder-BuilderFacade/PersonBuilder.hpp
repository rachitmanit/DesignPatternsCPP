#pragma once

using namespace std;

class Person;
class PersonAddressBuilder;
class PersonJobBuilder;

class PersonBuilderBase {
protected: // Protected so that child classes can access person attribute directly if required
    Person &person;
public:
    PersonBuilderBase(Person &p): person(p){}
    PersonAddressBuilder lives() const;
    PersonJobBuilder works() const;

    operator Person() const {
        // return person;
        return move(person); // This saves space and moves out the original person object;
    }
};

class PersonBuilder: public PersonBuilderBase {
public:
    PersonBuilder(): PersonBuilderBase(p){}
private: 
    Person p;
};