#include<bits/stdc++.h>
using namespace std;

int main(){

    vector<string> vec = {"Hello", "World"};
    ostringstream os;
    os << "<ul>";
    for(auto &word: vec) {
        os << "<li>" << word << "</li>";
    }
    os << "</ul>";

    cout << os.str();

    return 0;
}