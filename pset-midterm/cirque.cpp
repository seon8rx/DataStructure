// implement a circular queue with q->maxlen and perform a simple test
// - Keep the FIFO principle, 
//   Enqueue is allowed while popping the least recent item if necessary.
//   Therefore no overflow happens.
//
#include <iostream>
#include <sstream>
#include <string>
#include <cassert>
#include "cirque.h"
using namespace std;



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

void resize(cirque q, int new_capa){   // resize the queue items[] by resetting the maxlen
    string *resizedItems = new string[new_capa];

    if(empty(q)){
        for(int i=0; i<new_capa; i++) resizedItems[i]=q->dash;
        delete[] q->items;
        q->items = resizedItems;
        q->maxlen = new_capa;
        return;
    }

    int s = size(q);
    if(new_capa >= q->maxlen){
        for(int i=0; i<s; i++){
            resizedItems[i] = q->items[q->front];
            q->front++;
            q->front = q->front % q->maxlen;
        }
        for(int i=s; i<new_capa; i++){
            resizedItems[i] = q->dash;
        }
        q->front = 0;
        q->back = s - 1;
    }else{
        if(new_capa >= s){
            for(int i=0; i<s; i++){
                resizedItems[i] = q->items[q->front];
                q->front++;
                q->front = q->front % q->maxlen;
            }
            for(int i=s; i<new_capa; i++){
                resizedItems[i] = q->dash;
            }
            q->front = 0;
            q->back = s - 1;

        }else{
            int index = (q->maxlen + s - new_capa + q->front)%q->maxlen;
            for(int i=0; i<new_capa; i++){
                resizedItems[i] = q->items[index];
                index++;
                index = index % q->maxlen;
            }
            q->front = 0;
            q->back = new_capa - 1;
        }
    }
    delete[] q->items;
    q->items = resizedItems;
    q->maxlen = new_capa;
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

  if(q->front == q->back+1){
    q->front = -1;
    q->back = -1;
  }
  
  return item;
}

void clear(cirque q){                  // q->items are cleared, no change in capa or maxlen 
    while(!empty(q)) dequeue(q);
    q->front = -1;
    q->back = -1;
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