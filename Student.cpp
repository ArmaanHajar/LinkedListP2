// Student.cpp

#include <iostream>
#include "Student.h"
#include <cstring>

using namespace std;

Student::Student(char* firstName, char* lastName, float gpa, int studentID) {
  strncpy(this->firstName, firstName, 19);
  strncpy(this->lastName, lastName, 19);
  this->gpa = gpa;
  this->studentID = studentID;
}

void Student::set_first_name(char* firstNameTemp) {
  strncpy(firstName, firstNameTemp, 19);
}

void Student::set_last_name(char* lastNameTemp) {
  strncpy(lastName, lastNameTemp, 19);
}

void Student::set_gpa(float gpatemp) {
  gpa = gpatemp;
}

void Student::set_id(int studentIDTemp) {
  studentID = studentIDTemp;
}

char* Student::get_first_name() {
  return firstName;
}

char* Student::get_last_name() {
  return lastName;
}

float Student::get_gpa() {
  return gpa;
}

int Student::get_id() {
  return studentID;
}