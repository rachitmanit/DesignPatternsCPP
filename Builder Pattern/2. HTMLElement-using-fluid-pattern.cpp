#include<bits/stdc++.h>
using namespace std;

class HTMLBuilder;

class HTMLElement {

    friend class HTMLBuilder;
    string name, text;
    vector<HTMLElement> elements;
    const size_t indent_size = 2;

    HTMLElement(){}

    HTMLElement(const string &name, const string &text): name(name), text(text) {}

public:
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

    static HTMLBuilder create(string root_name);
    static HTMLBuilder create(string root_name, string root_text);
};

class HTMLBuilder {
    HTMLElement root;

public:
    HTMLBuilder(string root_name) {
        root.name = root_name;
    }

    HTMLBuilder(string root_name, string root_text) {
        root.name = root_name;
        root.text = root_text;
    }

    HTMLBuilder& add_child(string child_name, string child_text){
        HTMLElement elem(child_name, child_text);
        root.elements.emplace_back(elem);
        return *this;
    }

    string build(){
        return this->str();
    }

    string str() {
        return root.str();
    }
};

HTMLBuilder HTMLElement::create(string root_name) {
    return create(root_name, "");
}

HTMLBuilder HTMLElement::create(string root_name, string root_text) {
    return HTMLBuilder(root_name, root_text);
}

int main() {
   auto HTMLContent = HTMLElement::create("ul", "").add_child("li", "Apple").add_child("li", "Banana").add_child("li", "Grapes").build();
    cout << HTMLContent << endl;

    cout << "----------------" << endl;

    HTMLContent = HTMLElement::create("ul", "This is a list").add_child("li", "Apple").add_child("li", "Banana").add_child("li", "Grapes").build();
    cout << HTMLContent << endl;

    return 0;
}