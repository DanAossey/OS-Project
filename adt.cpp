// FILE: adt.cpp 
// Coder: J Yong
// Purpose: this can be deleted 
#include "adt.h"
#include<iostream>
using namespace std;

const int LASTNODE = 0;

//id arr burst priority
bool read_File (struct Queue q) {
  int i = 0;
  ifstream inFile("input"); 
  if (!inFile.is_open()) {
    return false;
  }
  while (!inFile.eof()) { //fig how to look for unfinished lines?
     inFile >> q[i].p_id;
     inFile >> q[i].arrival_time;
     inFile >> q[i].total_CPU_burst;
     inFile >> q[i].priority; 
     i++;
  }
  return true;
  inFile.close();
}

// Mutators

Queue::Queue(void){
  head = new Process;
  head->next = LASTNODE;
  cursor = head;
  tail = head;
}

Queue::~Queue(void) {
  
  moveToFront();
  while (remove()){
  }
  delete head;
}

void Queue::insert(const DataType& newItem) {
  Process* temp;
  temp = new Process;
  temp->contents = newItem;
  
  temp->next = cursor->next;
  cursor->next = temp;
  
  if (temp->next == 0){
    tail = temp;
  }
}

void Queue::remove(void) {
  Process* temp;
  temp = cursor->next;
  
  if (temp == 0) {
    return false;
  }
  cursor->next = temp->next;
  
  delete temp;
  return true;
}

bool Queue::move(void){
  if(cursor->next == 0){
    return false;
  }
  cursor = cursor->next;
  
  return true;
}

void Queue::moveToBack(void){
  cursor = tail;
}

void Queue::moveToFront(void){
  cursor = head;
}
// Accessors

bool Queue::get(DataType& item) const{
  if (cursor->next == 0){
    return false;
  }
  
  item =  cursor->next->data;
  return true;
}
