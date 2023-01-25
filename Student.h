// Student.h

#pragma once
#include <iostream>

using namespace std;

class Student {
 public:
  Student(char*, char*, float, int);
  void set_first_name(char*);
  void set_last_name(char*);
  void set_gpa(float);
  void set_id(int);
  char* get_first_name();
  char* get_last_name();
  float get_gpa();
  int get_id();

  char firstName[20];
  char lastName[20];
  float gpa;
  int studentID;
};