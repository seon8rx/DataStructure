/*
On my honor, I pledge that I have neither received nor provided improper assistance in the
completion of this assignment.
서명: 김성규 학번: 22100110
*/

// implement a circular queue with MAXLEN and perform a simple test
// - Keep the FIFO principle, 
//   Enqueue is allowed while popping the least recent item if necessary.
//   Therefore no overflow happens.
//
#include <iostream>
#include <sstream>
#include <string>
#include <cassert>
using namespace std;

// MAXLEN of circular queue, a magic number to get rid of
const int MAXLEN = 4;
struct CircularQueue {      
  string items[MAXLEN];             // queue item storage
  int front, back;                  // set to -1 to begin with
};

using cirque = CircularQueue *;

cirque newCircularQueue(){
  cirque q = new CircularQueue;
  for (int i = 0; i < MAXLEN; i++) 
    q->items[i] = '-';            // dash: a placeholder for empty slot
  q->front = -1;
  q->back = -1;
  return q;
}

bool full(cirque q){
  if (q->front == 0 && q->back == MAXLEN - 1) return true;
  if (q->front == q->back + 1) return true;
  return false;
}

bool empty(cirque q){
  return q->front == -1;
}

int size(cirque q) {
  if(empty(q)) return 0;
  else if(full(q)) return MAXLEN;
  else{
    return (MAXLEN + q->back - q->front + 1)%MAXLEN;
  }
}

// Keep the FIFO principle and no overflow is allowed 
void enqueue(cirque q, string item) {  
  if (q->front == -1) 
      q->front = 0;
  else if (full(q)) 
      q->front = (q->front + 1) % MAXLEN;

  q->back = (q->back + 1) % MAXLEN;
  q->items[q->back] = item;
  cout << "enqueued: " << item << endl;
}

string dequeue(cirque q){
  if (empty(q)) return "";

  string item = q->items[q->front];
  q->items[q->front] = '-';       // a placeholder

  q->front++;
  q->front = q->front % MAXLEN;
  
  return item;
}

// show queue status
void show_qstat(cirque q) {
  cout << "Front:back=[" << q->front << ":"<< q->back << "]";
  cout << " maxlen=" << MAXLEN << " size=" << size(q) << endl; 
}

// show queue items[] as it is stored
void show_items(cirque q) {             // show items[]
  cout << "Items:[ ";
  for(int i = 0; i < MAXLEN; i++)
      cout << q->items[i] << ' ';
  cout << "]\n"; 
}

// show queue from 'front' to 'back'
void show_queue(cirque q) {             
  cout << "Queue:[ ";
  
  int index = q->front;
  
  for(int i=0; i<size(q); i++){
    cout << q->items[index];
    if(i!=size(q)-1) cout<<" ";
    index++;
    index = index % MAXLEN;
  }

  cout << " ]\n"; 
} 

int main() {
    cirque q = newCircularQueue();
    show_qstat(q); show_items(q); show_queue(q); cout << endl;
  
    enqueue(q, "a");
    enqueue(q, "b");
    show_qstat(q); show_items(q); show_queue(q); cout << endl;

    enqueue(q, "c");
    enqueue(q, "d");
    enqueue(q, "e");
    enqueue(q, "f"); 
    show_qstat(q); show_items(q); show_queue(q); cout << endl;

    string item = dequeue(q);
    cout << "dequeued: " << item << endl;
    show_qstat(q); show_items(q); show_queue(q); cout << endl;

    enqueue(q, "g");
    show_qstat(q); show_items(q); show_queue(q); cout << endl;
    
    enqueue(q, "h"); 
    dequeue(q);
    dequeue(q);
    show_qstat(q); show_items(q); show_queue(q); cout << endl;
    return 0;
}

