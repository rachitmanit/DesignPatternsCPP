#include<bits/stdc++.h>
using namespace std;

enum class Color {read, green, blue};
enum class Size {small, medium, large};

class Product {
public:
    string name;
    Color color;
    Size size;

    Product(string name, Color color, Size size) {
        this->name = name;
        this->color = color;
        this->size = size;
    }
};

template <typename T> class Specification {
public:
    virtual bool is_satisfied(T* item) = 0;
};

template <typename T> class Filter {
public:
    virtual vector<T*> filter(vector<T*> &items, Specification<T> &spec) = 0;
};

class BetterFilter: public Filter<Product> {
public:
    vector<Product*> filter(vector<Product*> &items, Specification<Product> &spec) override {
        vector<Product*> result;
        for(auto &item: items){
            if(spec.is_satisfied(item)){
                result.push_back(item);
            }
        }
        return result;
    }
};

class ColorSpecification: public Specification<Product> {
public:
    Color color;
    ColorSpecification(Color color){
        this->color = color;
    }

    bool is_satisfied(Product* item) override {
        if(item->color == this->color)
            return true;
        return false;
    }
};

class SizeSpecification: public Specification<Product> {
public:
    Size size;
    SizeSpecification(Size size) {
        this->size = size;
    }

    bool is_satisfied(Product* item) override {
        if(item->size == this->size)
            return true;
        return false;
    }
};

template <typename T> class AndSpecification: public Specification<T> {
public:
    Specification<T> &first;
    Specification<T> &second;

    AndSpecification(Specification<T> &first, Specification<T> &second): first(first), second(second){}

    bool is_satisfied(T* item) override{
        return first.is_satisfied(item) && second.is_satisfied(item);
    }
};

int main() {

    Product p1{"A", Color::green, Size::large};
    Product p2{"B", Color::green, Size::small};
    Product p3{"C", Color::blue, Size::medium};

    BetterFilter filter;
    ColorSpecification cSpec(Color::green);

    vector<Product*> vec = {&p1, &p2, &p3};

    auto items = filter.filter(vec, cSpec);
    for(auto &item: items){
        cout << item->name << " is green" << endl;
    }

    cout << "------------------" << endl;

    SizeSpecification sizeSpec(Size::large);
    items = filter.filter(vec, sizeSpec);
    for(auto &item: items){
        cout << item->name << " is large" << endl;
    }


    cout << "---- AND SPEC ----" << endl;

    AndSpecification<Product> andSpec(sizeSpec, cSpec);
    items = filter.filter(vec, sizeSpec);
    for(auto &item: items){
        cout << item->name << " is green and large" << endl;
    }

    return 0;
}