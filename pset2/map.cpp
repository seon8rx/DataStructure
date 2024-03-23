/*
On my honor, I pledge that I have neither received nor provided improper assistance in the
completion of this assignment.
서명: 김성규 학번: 22100110
*/

#include <iostream>
#include <map>
using namespace std;
int main() {
    cout << "declare a map variable called table\n";
    map<string, int> table;

    cout << "initialize table using array[], insert(), pair<>, make_pair()\n";
    table["John"] = 21;
    table.insert({"Paul", 15});
    table.insert(pair<string,int>("Pete", 10));
    table.insert(make_pair("Adam", 11));

    cout << "print table using range-based for loop\n";
    for(auto x: table){
        cout << "name : " << x.first << "\t";
        cout << "age : " << x.second << endl;
    }

    cout << "print table using iterator\n";
    for(auto i=table.begin(); i!=table.end(); i++){
        cout << "name : " << i->first << "\t";
        cout << "age : " << i->second << endl;
    }

    cout << "define and initialize chart using pair<> and make_pair() only\n";
    map<char,int> chart {
        pair<char,int>('A',65),
        make_pair('C',67),
        pair<char,int>('D',68),
        make_pair('B',66)
    };

    cout << "print chart using range-based for loop\n";
    for(auto as : chart){
        cout << "ascii : " << as.first << "\t";
        cout << "code : " << as.second << endl;
    }
    
    cout << chart['B'] << endl;
    return 0;
}