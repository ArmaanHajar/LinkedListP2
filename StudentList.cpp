/*
 * Author: Armaan Hajar
 * Program: A student list creator that uses a linked list to add all the students
 * Date: 1/29/2023
 */

#include <iostream>
#include <cstring>
#include <cstdio>
#include "Student.h"
#include "Node.h"

using namespace std;

void add(Node* head, Node* newNode);
void print(Node* head);
void myDelete(int id, Node* head);
void average(float total, int numOfStudents, Node* head);
void help();

int main() {
  Node* head = NULL;
  char input[10];
  bool running = true;

  // main code, running will stay true until user says "QUIT"
  while (running == true) {
    cout << "---------------------------------------------------------------" << endl;
    cout << "What Would You Like To Do? (ADD/PRINT/DELETE/AVERAGE/QUIT/HELP)" << endl;

    cin.get(input, 10);
    cin.ignore(1, '\n');

    if (input[1] == 'D' || input[1] == 'd') { // adds student
      char firstName[20];
      char lastName[20];
      int studentID = 0;
      float gpa = 0.0;
      Student* newStudent = new Student(firstName, lastName, studentID, gpa);
      
      // read in first name
      cout << "First Name: " << endl;
      cin.get(firstName, 20);
      cin.ignore(1, '\n');
      newStudent->set_first_name(firstName);

      // read in last name
      cout << "Last Name: " << endl;
      cin.get(lastName, 20);
      cin.ignore(1, '\n');
      newStudent->set_last_name(lastName);

      // read in student id
      cout << "Student ID: " << endl;
      cin >> studentID;
      cin.ignore();
      newStudent->set_id(studentID);

      // read in gpa
      cout << "GPA: " << endl;
      cin >> gpa;
      cin.ignore();
      newStudent->set_gpa(gpa);

      Node* newNode = new Node(newStudent);

      if (head == NULL) { // no nodes already in list
        head = newNode;
        newNode->setNext(NULL);
      }
      else if (newNode->getStudent()->get_id() < head->getStudent()->get_id()) { // new node is smaller than head
        newNode->setNext(head);
        head = newNode;
      }
      else {
        add(head, newNode);
      }
    }
    else if (input[1] == 'R' || input[1] == 'r') { // prints all students inputted
      print(head);
    }
    else if (input[2] == 'L' || input[2] == 'l') { // deletes a student
      int id;

      // read in id
      cout << "What Is The Student ID Of The Student You Want To Delete?" << endl;
      cin >> id;
      cin.ignore(1, '\n');

      myDelete(id, head);
    }
    else if (input[1] == 'V' || input[1] == 'v') { // averages gpas
      float total = 0.0;
      int numOfStudents = 0;

      // adds gpa of head
      total += head->getStudent()->get_gpa();
      numOfStudents++;
      average(total, numOfStudents, head);
    }
    else if (input[0] == 'Q' || input[0] == 'q') { // ends program
      cout << "Thank You For Using the Student List Maker!" << endl;
      running = false;
    }
    else if (input[0] == 'H' || input[0] == 'h') { // prints help message
      help();
    }
    else {
      cout << "Not Sure What You're Trying To Do" << endl;
    }
  }  
  return 0;
}
  
// adds new student
void add(Node* head, Node* newNode) {
  if (head->getNext() != NULL) { // if not at end of list
    if (newNode->getStudent()->get_id() >= head->getNext()->getStudent()->get_id()) { // if id of new node is greater than or equal to id of the current node
      head = head->getNext();
      add(head, newNode);
    }
    else { // if id of new node is less than id of the current node
      Node* temp = head->getNext();
      head->setNext(newNode);
      newNode->setNext(temp);
    }
  }
  else { // at end of list
    head->setNext(newNode);
    newNode->setNext(NULL);
  }
}

// prints all students on seperate lines
void print(Node* head) {
  Node* current = head;
  if (current != NULL) {
    cout << "---------------------------------------------------------------" << endl;
    cout << "First Name: " << current->getStudent()->get_first_name() << endl;
    cout << "Last Name: " << current->getStudent()->get_last_name() << endl;
    cout << "Student ID: " << current->getStudent()->get_id() << endl;
    cout << "GPA: " << current->getStudent()->get_gpa() << endl;
    current = current->getNext();
    print(current);
  }
}

// deletes a student
void myDelete(int id, Node* head) {
  bool deleted = false;
  if (id == head->getStudent()->get_id()) { // if user wants to delete head node
    Node* temp = head;
    head = head->getNext();
    delete temp;
    deleted = true;
    cout << "Student Successfully Deleted" << endl;
  }
  else if (id == head->getNext()->getStudent()->get_id()) { // deleting any other node
    Node* temp = head->getNext();
    head->setNext(head->getNext()->getNext());
    delete temp;
    deleted = true;
    cout << "Student Successfully Deleted" << endl;
  }
  else { // inputted id isn't equal to id of current node
    head = head->getNext();
    myDelete(id, head);
  }

  if (deleted == false) { // id was not found in list
    cout << "Student Was Not Found" << endl;
  }
}

// averages all the gpas of the students then prints them
void average(float total, int numOfStudents, Node* head) {
  if (head->getNext() != NULL) { // adds all gpas together
    head = head->getNext();
    total = total + head->getStudent()->get_gpa();
    numOfStudents++;
    average(total, numOfStudents, head);
  }
  else { // averages all gpas and rounds it to 2 decimal places
    float printGPA = total / numOfStudents;
    cout << "The Average GPA Of All Students Is: ";
    printf("%.2f", printGPA);
    cout << endl;
  }
}

// describes what each input does
void help() {
  cout << "Type \"ADD\" To Enter A New Student" << endl;
  cout << "Type \"PRINT\" To Print Out All Stored Students" << endl;
  cout << "Type \"DELETE\" To Delete A Student" << endl;
  cout << "Type \"AVERAGE\" To Print The Average GPA Of All Students" << endl;
  cout << "Type \"QUIT\" To End Program" << endl;
}
