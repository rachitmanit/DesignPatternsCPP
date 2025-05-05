#include<bits/stdc++.h>
using namespace std;

class HTMLElement {
public:
    string name, text;
    vector<HTMLElement> elements;
    const size_t indent_size = 2;

    HTMLElement(){}

    HTMLElement(const string &name, const string &text): name(name), text(text) {}

    string str(int indent=0) const {
        ostringstream os;
        
        string i(indent_size * (indent), ' ');
        os << i << "<" << name << ">" << endl;

        if(text.size() > 0){
            os << string(indent_size * (indent + 1), ' ') << text << endl;
        }
        for(auto &item: elements)
            os << item.str(indent + 1);
        os << i << "</" << name << ">" << endl;
        return os.str();
    }
};

class HTMLBuilder {
public:
    HTMLElement root;

    HTMLBuilder(string root_name) {
        root.name = root_name;
    }

    HTMLBuilder(string root_name, string root_text) {
        root.name = root_name;
        root.text = root_text;
    }

    void add_child(string child_name, string child_text){
        HTMLElement elem(child_name, child_text);
        root.elements.emplace_back(elem);
    }

    string str() {
        return root.str();
    }
};

int main(){

    HTMLBuilder builder("ul");
    builder.add_child("li", "Apple");
    builder.add_child("li", "Banana");
    builder.add_child("li", "Grapes");
    cout << builder.str();

    cout << "----------------" << endl;

    HTMLBuilder builder2("ul", "This is a list");
    builder2.add_child("li", "Apple");
    builder2.add_child("li", "Banana");
    builder2.add_child("li", "Grapes");
    cout << builder2.str();

    return 0;
}