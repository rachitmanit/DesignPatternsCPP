#include <iostream>
#include "Person.cpp"
#include "PersonBuilder.hpp"
#include "PersonJobBuilder.hpp"
#include "PersonAddressBuilder.hpp"

using namespace std;

int main() {

    Person p = Person::create().
        lives().at_street("Carmelaram").with_postcode("560035").in("Bangalore").
        works().at("Flipkart").as_a("Software Developer").earning(4800000);
    
    cout << p << endl;

    return 0;
}