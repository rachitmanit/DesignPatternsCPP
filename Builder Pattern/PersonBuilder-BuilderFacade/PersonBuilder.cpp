#include "Person.cpp"
using namespace std;


class PersonAddressBuilder;
class PersonJobBuilder;

class PersonBuilderBase {
protected: // Protected so that child classes can access person attribute directly if required
    Person &person;
public:
    PersonBuilderBase(Person &p): person(p){}
    
    PersonAddressBuilder PersonBuilderBase::lives() const{
        return PersonAddressBuilder(person);
    }
    
    PersonJobBuilder PersonBuilderBase::works() const{
        return PersonJobBuilder(person);
    }

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
