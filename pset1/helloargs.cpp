/*
On my honor, I pledge that I have neither received nor provided improper assistance in the
completion of this assignment.
서명: 김성규 학번: 22100110
*/

#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {

for(int i=1; i<=argc; i++){
    if(i!=argc) cout << "Hello " << argv[i] << "!" << endl;
    else cout << "Hello World!\n" << endl; 
}

return EXIT_SUCCESS;
}