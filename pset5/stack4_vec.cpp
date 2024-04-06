/*
On my honor, I pledge that I have neither received nor provided improper assistance in the
completion of this assignment.
서명: 김성규 학번: 22100110
*/

#include <iostream>
#include <vector>
using namespace std;

struct Stack{
    vector<string> item;
};
using stack = Stack *;

void free(stack s);
int size(stack s);
bool empty(stack s);
void pop(stack s);
string& top(stack s);
void push(stack& s, string item);
void printStack(stack s);
void printStack_fromBottom(stack s);

int main(){
    
    //int list[] = {1, 2, 3, 4, 5, 0, 6, 0, 0, 7, 0, 0, 0, 8};
    string list[] = {"to", "be", "or", "not", "to", "-", "be", "-", "-", "that", "-", "-", "-", "is"};
    
    stack s = new Stack();

    for(auto x: list){
        if(x != "-"){
            push(s, x);
        }else{
            cout << top(s) << ' ';
            pop(s);
        }
    }

    cout << "\nsize : " << size(s);
    cout << "\ntop : " << top(s);
    cout << "\nstack T : ";
    printStack(s);
    cout << "\nstack B : ";
    printStack_fromBottom(s);
    cout << "\nHappy Coding";

}

void free(stack s){
    delete s;
}

int size(stack s){
    return s->item.size();
}

bool empty(stack s){
    return s->item.empty();
}

void pop(stack s){
    s->item.pop_back();
    
    
    // if(s->item.size() == s->item.capacity()/4 && s->item.capacity()!=1) resize(s, s->item.capacity()/2);
}

string& top(stack s){
    return s->item[s->item.size() - 1];
}

void push(stack& s, string item){
    // if(s->item.size() == s-> item.capacity()) resize(s, 2*s->item.capacity());
    
    s->item.push_back(item);
    //cout << "\tsize: " << s->item.size() << ", capacity: " << s->item.capacity() << endl;
}

void printStack(stack s){
    stack t = new Stack;
    if(empty(s)){
        return;
    }else{
        cout << top(s) << ' ';
        push(t, top(s));
        pop(s);
        printStack(s);
    }
    if(empty(t)){
        return;
    }else{
        push(s, top(t));
        //cout << "\tsize: " << s->item.size() << ", capacity: " << s->item.capacity() << endl;
        pop(t);
    }
    free(t);
}

void printStack_fromBottom(stack s){
    stack t = new Stack;
    if(empty(s)){
        return;
    }else{
        push(t, top(s));
        pop(s);
        printStack_fromBottom(s);
    }
    if(empty(t)){
        return; 
    }else{
        cout << top(t) << ' ';
        push(s, top(t));
        //cout << "\tsize: " << s->item.size() << ", capacity: " << s->item.capacity() << endl;
        pop(t);
    }
    free(t);
}

