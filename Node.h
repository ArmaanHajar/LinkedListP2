//written by Eric Chen
//Date: 1/6/2023
//This is the .h file of the Node class 

#include <iostream>

#ifndef STUDENT_H
#define STUDENT_H
#include "Student.h"
#endif

using namespace std;

class Node{
 public:
  Node(Student* myStudent);//constructor
  ~Node();//destructor
  virtual Node* getNext();//return a pointer to the next node
  Student* getStudent();//returns a pointer to the student stored
  virtual void setNext(Node* myNode);//setting the next pointer

 private:
  Student* myStudent;
  Node* myNode;
};