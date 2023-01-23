#pragma once
#include <iostream>

using namespace std;

class Student {
 public:
  void set_first_name(char*);
  void set_last_name(char*);
  void set_gpa(float);
  void set_student_id(int);
  char* get_first_name();
  char* get_last_name();
  float get_gpa();
  int get_student_id();

  char firstName[20];
  char lastName[20];
  float gpa;
  int studentID;
};
