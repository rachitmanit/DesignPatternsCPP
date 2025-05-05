#include<bits/stdc++.h>
using namespace std;

class Document{
public:
    int data;
    Document(int d): data(d){}
};

// Below implementation is wrong as it has larger Interface which if anyone to implement has to 
// implement raising exceptions for non relevant methods.

// class IMachine {
// public:
//     virtual void print(Document &b) = 0;
//     virtual void scan(Document &b) = 0;
//     virtual void fax(Document &b) = 0;
// };

// class Printer: IMachine {
// public:
//     void print(Document &b) override{
//         cout << "Printing" << endl;
//     }

//     void scan(Document &b) override {

//     }

//     void fax(Document &b) override {
//         throw logic_error("Not implemented");
//     }
// };


// Right way is to create small Interfaces and implement as required

class IPrinter {
public:
    virtual void print(Document &b) = 0;
};

class IScanner {
public:
    virtual void scan(Document &b) = 0;
};

class IFax {
public:
    virtual void fax(Document &b) = 0;
};

class Printer: public IPrinter{
public:
    void print(Document &b) override {
        cout << "Printing " << b.data << endl;
    }
};

class Scanner: public IScanner{
public:
    void scan(Document &b) override {
        cout << "Scanning" << b.data << endl;
    }
};

class IMachine: public IPrinter, public IScanner {};

class Machine: IMachine {
public:
    IPrinter &printer;
    IScanner &scanner;

    Machine(IPrinter &printer, IScanner &scanner): printer(printer), scanner(scanner) {}

    void print(Document &b) override {
        printer.print(b);
    }

    void scan(Document &b) override {
        scanner.scan(b);
    }
};


int main(){
    Document d1(1);
    Document d2(2);

    Printer p; 
    p.print(d1);
    Scanner s;
    s.scan(d1);
    cout << "--------------" << endl;
    
    p.print(d2);
    s.scan(d2);
    cout << "--------------" << endl;
    
    Machine m(p, s);
    m.print(d1);
    m.print(d2);

    m.scan(d1);
    m.scan(d2);

    return 0;
}