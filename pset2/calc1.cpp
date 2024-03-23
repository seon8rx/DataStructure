/*
On my honor, I pledge that I have neither received nor provided improper assistance in the
completion of this assignment.
서명: 김성규 학번: 22100110
*/

#include <iostream>
#include <sstream>
using namespace std;

int add(int a, int b) {return a+b;}
int mul(int a, int b) {return a*b;}
int sub(int a, int b) {return a-b;}
int dvd(int a, int b) {if(b!=0) return a/b; else return 0;}

int get_int();
char get_op(string opstr);

int main(){
    int a { get_int()};
    char op {get_op("+-*/")};
    int b {get_int()};

    // int (*addptr)(int, int) = add;
    // int (*mulptr)(int, int) = mul;
    // int (*subptr)(int, int) = sub;
    // int (*dvdptr)(int, int) = dvd;
    int (*ptr)(int, int);


    switch (op){
        case '+':
            ptr = add;
            cout << a << " " << op << " " << b << " = " << ptr(a,b) <<endl;
            break;
        case '-':
            ptr = sub;
            cout << a << " " << op << " " << b << " = " << ptr(a,b) <<endl;
            break;
        case '*':
            ptr = mul;
            cout << a << " " << op << " " << b << " = " << ptr(a,b) <<endl;
            break;
        case '/':
            ptr = dvd;
            cout << a << " " << op << " " << b << " = " << ptr(a,b) <<endl;
            break;
        default:
            break;
    }
    return 0;
}

int get_int(){
    int x;
    
    do{
        cout << "Enter an integer: ";
        string str;
        getline(cin, str);
        try{
            x = stoi(str);
            break;
        }
        catch(invalid_argument& e){
            cerr << e.what() << " error occurred. Retry~" << endl;
        }
    }while(true);
    return x;
}

char get_op(string opstr){
    char op;
    
    do{
        stringstream ss;
        string str;
        cout << "Enter an operator( " << opstr << " ): ";
        getline(cin, str);
        ss << str;
        ss >> op;
    }while(opstr.find(op) == string::npos);
    return op;
}