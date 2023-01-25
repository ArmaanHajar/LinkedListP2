/*
 * Author: Armaan Hajar
 * Program: A student list creator that inputs the students first name, last name, gpa, and 
 *          student ID to add it to a vector
 * Date: 10/11/2022
 */

#include <iostream>
#include <cstring>
#include "Student.h"
#include "Node.h"

using namespace std;

void add(Node* head);
void print(Node* head);
void myDelete(Node* head);
void average(Node* head);
void help();

int main() {
  Node* head = NULL;
  char input[7];
  bool running = true;

  // main code, running will stay true unti luser says "QUIT"
  while (running == true) {
    cout << "---------------------------------------------------------" << endl;
    cout << "What Would You Like To Do? (ADD/PRINT/DELETE/AVERAGE/QUIT/HELP)" << endl;

    cin >> input;

    if (input[1] == 'D' || input[1] == 'd') { // adds student
      add(head);
    }
    else if (input[1] == 'R' || input[1] == 'r') { // prints all students inputted
      print(head);
    }
    else if (input[1] == 'E' || input[1] == 'e') { // deletes a student
      myDelete(head);
    }
    else if (input[1] == 'V' || input[1] == 'v') { // averages gpas
      average(head);
    }
    else if (input[0] == 'Q' || input[0] == 'q') { // ends program
      cout << "Thank You For Using the Student List Maker!" << endl;
      running = false;
    }
    else if (strcmp(input, "HELP") == 0) { // prints what each input does
      help();
    }
    else { // if user doesn't typ add, print, delete, or quit
      cout << "Not Sure What You're Trying To Do" << endl;
    }
  }  
  return 0;
}

// adds new student
void add(Node* head) {
  char firstName[20];
  char lastName[20];
  float gpa;
  int studentID;
  Student* newStudent = new Student(firstName, lastName, gpa, studentID);
  
  cout << "First Name: " << endl;
  cin.get(firstName, 20);
  cin.get();
  newStudent->set_first_name(firstName);

  cout << "Last Name: " << endl;
  cin.get(lastName, 20);
  cin.get();
  newStudent->set_last_name(lastName);

  cout << "GPA: " << endl;
  cin >> gpa;
  newStudent->set_gpa(gpa);

  cout << "Student ID: " << endl;
  cin >> studentID;
  newStudent->set_id(studentID);
  Node* newNode = new Node(newStudent);

  if (head == NULL) {
    head = newNode;
  }
  else {
    while (head->getNext() != NULL) {
      if (newNode->getStudent()->get_id() > head->getNext()->getStudent()->get_id()) {
        head->setNext(newNode);
        newNode->setNext(head->getNext()->getNext());
      }
    }
  }
}

// prints all students on seperate lines
void print(Node* head) {
  while (head->getNext() != NULL) {
    cout << "---------------------------------------------------------" << endl;
    cout << "First Name: " << head->getStudent()->get_first_name() << endl;
    cout << "Last Name: " << head->getStudent()->get_last_name() << endl;
    cout << "GPA: " << head->getStudent()->get_gpa() << endl;
    cout << "Student ID: " << head->getStudent()->get_id() << endl;
    head = head->getNext();
  }
}

// deletes a student
void myDelete(Node* head) {
  int id;
  cout << "What Is The Student ID Of The Student You Want To Delete?" << endl;
  cin >> id;

  while (head->getNext() != NULL) {
    if (head->getNext()->getStudent()->get_id() == id) {
      head->setNext(head->getNext()->getNext());
    }
    head = head->getNext();
  }
}

// averages all the gpas of the students then prints them
void average(Node* head) {
  int total = 0;
  while (head->getNext() != NULL) {
    total += head->getStudent()->get_gpa();
    head = head->getNext();
  }
  cout << "The Average GPA Of All Students Is: " << total / head->getStudent()->get_id() << endl;
}

// describes what each input does
void help() {
  cout << "Type \"ADD\" To Enter A New Student" << endl;
  cout << "Type \"PRINT\" To Print Out All Stored Students" << endl;
  cout << "Type \"DELETE\" To Delete A Student" << endl;
  cout << "Type \"AVERAGE\" To Print The Average GPA Of All Students" << endl;
  cout << "Type \"QUIT\" To End Program" << endl;
}