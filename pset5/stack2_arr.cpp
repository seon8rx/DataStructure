#include <iostream>
using namespace std;

const int SIZE = 20;

struct Stack{
    string *item;
    int N;
    int capacity;
};
using stack = Stack *;

stack newStack(int capacity);
void free(stack s);
int size(stack s);
bool empty(stack s);
void pop(stack s);
string top(stack s);
void push(stack s, string item);
void printStack(stack s);
void printStack_fromBottom(stack s);

int main(){
    
    //int list[] = {1, 2, 3, 4, 5, 0, 6, 0, 0, 7, 0, 0, 0, 8};
    string list[] = {"to", "be", "or", "not", "to", "-", "be", "-", "-", "that", "-", "-", "-", "is"};
    
    stack s = newStack (SIZE);
    
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

stack newStack(int capacity){
    stack s = new Stack;
    s->item = new string[capacity];
    s->N = 0;
    s->capacity = capacity;
    return s;
}

void free(stack s){
    delete[] s->item;
    delete s;
}

int size(stack s){
    return s->N;
}

bool empty(stack s){
    return s->N == 0;
}

void pop(stack s){
    s->N--;
}

string top(stack s){
    return s->item[s->N - 1];
}

void push(stack s, string item){
    s->item[s->N++] = item;
}

void printStack(stack s){
    stack t = newStack(SIZE);
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

// void printStack(stack s){
//     stack t = newStack(200);
//     while(!empty(s)){
//         cout << top(s) << ' ';
//         push(t, top(s));
//         pop(s);
//     }
//     while(!empty(t)){
//         push(s,top(t));
//         pop(t);
//     }
//     free(t);
// }

void printStack_fromBottom(stack s){
    stack t = newStack(SIZE);
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

