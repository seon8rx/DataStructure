/*
On my honor, I pledge that I have neither received nor provided improper assistance in the
completion of this assignment.
서명: 김성규 학번: 22100110
*/

#include <iostream>
#include <string>
using namespace std;

int main() {

string name;

do{
cout << "Enter a name: ";
getline (cin, name);
if(name.length() > 0){
    cout << "Hello " << name <<"!" <<endl;
}else{
    cout << "Hello World!\n" << endl;
}
}while(name != "\0");

return EXIT_SUCCESS;
}