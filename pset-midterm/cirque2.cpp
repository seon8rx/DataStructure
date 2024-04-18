// implement a circular queue with q->maxlen and perform a simple test
// - Keep the FIFO principle, 
//   Enqueue is allowed while popping the least recent item if necessary.
//   Therefore no overflow happens.
//
#include <iostream>
#include <sstream>
#include <string>
#include <cassert>
using namespace std;

// q->maxlen of circular queue, a magic number to get rid of

struct CircularQueue {      
  string *items;             // queue item storage
  int front, back;                  // set to -1 to begin with
  int maxlen;
  const string dash = "-";

  CircularQueue(int capa=4){
    maxlen = capa;

    items = new string[maxlen];

    for (int i = 0; i < maxlen; i++) 
        items[i] = dash;
    front = -1;
    back = -1;
  }

  ~CircularQueue(){
    delete[] items;
  }
};

using cirque = CircularQueue *;

bool full(cirque q){
  if (q->front == 0 && q->back == q->maxlen - 1) return true;
  if (q->front == q->back + 1) return true;
  return false;
}

bool empty(cirque q){
  return q->front == -1;
}

int size(cirque q) {
  if(empty(q)) return 0;
  else if(full(q)) return q->maxlen;
  else{
    return (q->maxlen + q->back - q->front + 1)%q->maxlen;
  }
}

// Keep the FIFO principle and no overflow is allowed 
void enqueue(cirque q, string item) {  
  if (q->front == -1) 
      q->front = 0;
  else if (full(q)) 
      q->front = (q->front + 1) % q->maxlen;

  q->back = (q->back + 1) % q->maxlen;
  q->items[q->back] = item;
  cout << "enqueued: " << item << endl;
}

string dequeue(cirque q){
  if (empty(q)) return "";

  string item = q->items[q->front];
  q->items[q->front] = q->dash;       // a placeholder

  q->front++;
  q->front = q->front % q->maxlen;
  
  return item;
}

// show queue status
void show_qstat(cirque q) {
  cout << "Front:back=[" << q->front << ":"<< q->back << "]";
  cout << " q->maxlen=" << q->maxlen << " size=" << size(q) << endl; 
}

// show queue items[] as it is stored
void show_items(cirque q) {             // show items[]
  cout << "Items:[ ";
  for(int i = 0; i < q->maxlen; i++)
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
    index = index % q->maxlen;
  }

  cout << " ]\n"; 
} 

int main() {
    cirque q = new CircularQueue(6);
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

    q->~CircularQueue();

    return 0;
}

