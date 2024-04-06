/*
On my honor, I pledge that I have neither received nor provided improper assistance in the
completion of this assignment.
서명: 김성규 학번: 22100110
*/

#include <iostream>
using namespace std;

const int SIZE = 20;

template<typename T>
struct Stack{
    T *item;
    int N;
    int capacity;
};
template<typename T>
using stack = Stack<T> *;

template<typename T>
stack<T> newStack(int capacity);
template<typename T>
void free(stack<T> s);
template<typename T>
int size(stack<T> s);
template<typename T>
bool empty(stack<T> s);
template<typename T>
void pop(stack<T> s);
template<typename T>
T top(stack<T> s);
template<typename T>
void push(stack<T> s, T item);
template<typename T>
void printStack(stack<T> s);
template<typename T>
void printStack_fromBottom(stack<T> s);

int main(){
    
    //int list[] = {1, 2, 3, 4, 5, 0, 6, 0, 0, 7, 0, 0, 0, 8};
    string list[] = {"to", "be", "or", "not", "to", "-", "be", "-", "-", "that", "-", "-", "-", "is"};
    
    stack<string> s = newStack<string> (SIZE);
    
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

template<typename T>
stack<T> newStack(int capacity){
    stack<T> s = new Stack<T>;
    s->item = new T[capacity];
    s->N = 0;
    s->capacity = capacity;
    return s;
}

template<typename T>
void free(stack<T> s){
    delete[] s->item;
    delete s;
}

template<typename T>
int size(stack<T> s){
    return s->N;
}

template<typename T>
bool empty(stack<T> s){
    return s->N == 0;
}

template<typename T>
void pop(stack<T> s){
    s->N--;
}

template<typename T>
T top(stack<T> s){
    return s->item[s->N - 1];
}

template<typename T>
void push(stack<T> s, T item){
    s->item[s->N++] = item;
}

template<typename T>
void printStack(stack<T> s){
    stack<T> t = newStack<T>(SIZE);
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
        pop(t);
    }
    free(t);
}

template<typename T>
void printStack_fromBottom(stack<T> s){
    stack<T> t = newStack<T>(SIZE);
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
        pop(t);
    }
    free(t);
}

