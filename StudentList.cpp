/*
 * Author: Armaan Hajar
 * Program: A student list creator that inputs the students first name, last name, gpa, and student ID to add it to a vector
 * Date: 
 */

#include <iostream>
#include <cstring>
#include "Student.h"
#include "Node.h"

using namespace std;

void add(Node* current, Node* &head);
void print(Node* head);
void myDelete(Node* head);
void average(Node* head);
void help();

int main() {
  Node* head = NULL;
  Node* current = NULL;
  char input[10];
  bool running = true;

  // main code, running will stay true until user says "QUIT"
  while (running == true) {
    cout << "---------------------------------------------------------------" << endl;
    cout << "What Would You Like To Do? (ADD/PRINT/DELETE/AVERAGE/QUIT/HELP)" << endl;

    cin.get(input, 10);
    cin.ignore(1, '\n');

    if (input[1] == 'D' || input[1] == 'd') { // adds student
      add(current, head);
    }
    else if (input[1] == 'R' || input[1] == 'r') { // prints all students inputted
      print(head);
    }
    else if (input[2] == 'L' || input[2] == 'l') { // deletes a student
      myDelete(head);
    }
    else if (input[1] == 'V' || input[1] == 'v') { // averages gpas
      average(head);
    }
    else if (input[0] == 'Q' || input[0] == 'q') { // ends program
      cout << "Thank You For Using the Student List Maker!" << endl;
      running = false;
    }
    else if (input[0] == 'H' || input[0] == 'h') {
      help();
    }
    else {
      cout << "Not Sure What You're Trying To Do" << endl;
    }
  }  
  return 0;
}
  
// adds new student
void add(Node* current, Node* &head) {
  char firstName[20];
  char lastName[20];
  float gpa;
  int studentID;
  Student* newStudent = new Student(firstName, lastName, gpa, studentID);
  
  cout << "First Name: " << endl;
  cin.get(firstName, 20);
  cin.ignore(1, '\n');
  newStudent->set_first_name(firstName);

  cout << "Last Name: " << endl;
  cin.get(lastName, 20);
  cin.ignore(1, '\n');
  newStudent->set_last_name(lastName);

  cout << "GPA: " << endl;
  cin >> gpa;
  cin.ignore(1, '\n');
  newStudent->set_gpa(gpa);

  cout << "Student ID: " << endl;
  cin >> studentID;
  cin.ignore(1, '\n');
  newStudent->set_id(studentID);

  Node* newNode = new Node(newStudent);

  if (head == NULL) { // no nodes already in list
    head = newNode;
    newNode->setNext(NULL);
    cout << "new head" << endl;
  }
  else if (newNode->getStudent()->get_id() < head->getStudent()->get_id()) { // new node is smaller than head
    head = newNode;
    newNode->setNext(head);
    cout << "put before existing head" << endl;
  }
  else {
    if (current->getNext() != NULL) { // if not at end of list
      if (newNode->getStudent()->get_id() >= current->getNext()->getStudent()->get_id()) { // if new node is greater than the node after current
        current = current->getNext();
        add(current, newNode);
        cout << "node is greater than current" << endl;
      }
      else { // if new node is smaller than the node after current
        Node* temp = current->getNext();
        current->setNext(newNode);
        newNode->setNext(temp);
        cout << "node is smaller than current" << endl;
      }
    }
    else if (newNode->getStudent()->get_id() >= current->getStudent()->get_id()) { // if new node is greater or equal to the current node
        Node* temp = current->getNext();
        current->setNext(newNode);
        newNode->setNext(temp);
        cout << "node is greater or equal to current" << endl;
    }
  }
}

// prints all students on seperate lines
void print(Node* head) {
  Node* current = head;
  while (current != NULL) {
    cout << "---------------------------------------------------------------" << endl;
    cout << "First Name: " << head->getStudent()->get_first_name() << endl;
    cout << "Last Name: " << head->getStudent()->get_last_name() << endl;
    cout << "GPA: " << head->getStudent()->get_gpa() << endl;
    cout << "Student ID: " << head->getStudent()->get_id() << endl;
    current = current->getNext();
  }
}

// deletes a student
void myDelete(Node* head) {
  bool deleted = false;
  int id;

  cout << "What Is The Student ID Of The Student You Want To Delete?" << endl;
  cin >> id;
  cin.ignore(1, '\n');

  Node* current = head;

  while (current->getNext() != NULL) {
    if (current->getNext()->getStudent()->get_id() == id) {
      current->setNext(current->getNext()->getNext());
      delete current->getNext();
      cout << "Student Successfully Deleted" << endl;
      deleted = true;
    }
    else {
      current = current->getNext();
    }
  }
  if (deleted == false) {
    cout << "Student Was Not Found" << endl;
  }
}

// averages all the gpas of the students then prints them
void average(Node* head) {
  int total = 0;
  int numOfStudents = 0;
  while (head->getNext() != NULL) {
    total += head->getStudent()->get_gpa();
    numOfStudents++;
    head = head->getNext();
  }
  cout << "The Average GPA Of All Students Is: " << total / numOfStudents << endl;
}

// describes what each input does
void help() {
  cout << "Type \"ADD\" To Enter A New Student" << endl;
  cout << "Type \"PRINT\" To Print Out All Stored Students" << endl;
  cout << "Type \"DELETE\" To Delete A Student" << endl;
  cout << "Type \"AVERAGE\" To Print The Average GPA Of All Students" << endl;
  cout << "Type \"QUIT\" To End Program" << endl;
}
