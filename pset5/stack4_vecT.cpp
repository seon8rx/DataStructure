/*
On my honor, I pledge that I have neither received nor provided improper assistance in the
completion of this assignment.
서명: 김성규 학번: 22100110
*/

#include <iostream>
#include <vector>
using namespace std;

template<typename T>
struct Stack{
    vector<T> item;
};
template<typename T>
using stack = Stack<T> *;

template<typename T>
void free(stack<T> s);
template<typename T>
//int size(stack<T> s);
typename vector<T>::size_type size(stack<T> s);
template<typename T>
bool empty(stack<T> s);
template<typename T>
void pop(stack<T> s);
template<typename T>
T& top(stack<T> s);
template<typename T>
void push(stack<T>& s, T item);
template<typename T>
void printStack(stack<T>& s);
template<typename T>
void printStack_fromBottom(stack<T>& s);

int main(){
    
    //int list[] = {1, 2, 3, 4, 5, 0, 6, 0, 0, 7, 0, 0, 0, 8};
    string list[] = {"to", "be", "or", "not", "to", "-", "be", "-", "-", "that", "-", "-", "-", "is"};
    
    stack<string> s = new Stack<string>();

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
void free(stack<T> s){
    delete s;
}
template<typename T>
typename vector<T>::size_type size(stack<T> s){
    return s->item.size();
}
template<typename T>
bool empty(stack<T> s){
    return s->item.empty();
}
template<typename T>
void pop(stack<T> s){
    s->item.pop_back();
    
    
    // if(s->item.size() == s->item.capacity()/4 && s->item.capacity()!=1) resize(s, s->item.capacity()/2);
}
template<typename T>
T& top(stack<T> s){
    return s->item[s->item.size() - 1];
}
template<typename T>
void push(stack<T>& s, T item){
    // if(s->item.size() == s-> item.capacity()) resize(s, 2*s->item.capacity());
    
    s->item.push_back(item);
    //cout << "\tsize: " << s->item.size() << ", capacity: " << s->item.capacity() << endl;
}
template<typename T>
void printStack(stack<T>& s){
    stack<T> t = new Stack<T>;
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
template<typename T>
void printStack_fromBottom(stack<T>& s){
    stack<T> t = new Stack<T>;
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

