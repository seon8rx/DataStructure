/*
On my honor, I pledge that I have neither received nor provided improper assistance in the
completion of this assignment.
서명: 김성규 학번: 22100110
*/

#include <iostream>
#include <stack>
using namespace std;

void printStack(stack<string> s);
void printStack_fromBottom(stack<string> s);

int main(){
    
    //int list[] = {1, 2, 3, 4, 5, 0, 6, 0, 0, 7, 0, 0, 0, 8};
    string list[] = {"to", "be", "or", "not", "to", "-", "be", "-", "-", "that", "-", "-", "-", "is"};
    
    stack<string> s;
    
    for(auto x: list){
        if(x != "-"){
            s.push(x);
        }else{
            cout << s.top() << ' ';
            s.pop();
        }
    }

    cout << "\nsize : " << s.size();
    cout << "\ntop : " << s.top();
    cout << "\nstack T : ";
    printStack(s);
    cout << "\nstack B : ";
    printStack_fromBottom(s);
    cout << "\nHappy Coding";

}

// void printStack(stack<int> s){
//     stack<int> t;
//     while(!s.empty()){
//         cout << s.top() << ' ';
//         t.push(s.top());
//         s.pop();
//     }
//     while(!t.empty()){
//         s.push(t.top());
//         t.pop();
//     }

void printStack(stack<string> s){
    stack<string> t;
    if(s.empty()){
        return;
    }else{
        cout << s.top() << ' ';
        t.push(s.top());
        s.pop();
        printStack(s);
    }
    if(t.empty()){
        return;
    }else{
        s.push(t.top());
        t.pop();
    }
}

void printStack_fromBottom(stack<string> s){
    stack<string> t;
    if(s.empty()){
        return;
    }else{
        t.push(s.top());
        s.pop();
        printStack(s);
    }
    if(t.empty()){
        return; 
    }else{
        cout << t.top() << ' ';
        s.push(t.top());
        t.pop();
    }
}
