// FILE: adt.h
// Coder:
// Purpose:
//
#ifndef ADT_H_INCLUDED
#define ADT_H_INCLUDED

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
typedef ProcessItem DataType;

class Queue {
public:
  
  Queue(void);
  ~Queue(void);
  
  void insert(const DataType& newItem);
  bool remove(void);
  bool move(void);
  void moveToBack(void);
  void moveToFront(void);
  
  bool get(DataType& item) const;
  
private:
struct ProcessItem {
  int p_id, priority;
  float arrival_time;
  float total_CPU_Burst;
}  
  
struct Process {
  ProcessItem contents;
  Process* next;
};

Process * head, * tail, * cursor;
int counter = 0;
  
};
// Coder: J Yong
// Purpose: reads in a line of input from file stream
// Pre: file stream
// Post: True if the file is open, and reads in all input from file into a struct
//       False if the file is closed
bool read_File (struct Queue q);

#endif
