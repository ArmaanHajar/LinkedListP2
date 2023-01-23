/*
 * Author: Armaan Hajar
 * Program: A student list creator that inputs the students first name, last name, gpa, and 
 *          student ID to add it to a vector
 * Date: 10/11/2022
 */

#include <iostream>
#include "Student.h"
#include "Node.h"

using namespace std;

void add();
void print();
void myDelete();
void average();
void help();

int main() {
  char input[7];
  bool running = true;

  // main code, running will stay true unti luser says "QUIT"
  while (running == true) {
    cout << "---------------------------------------------------------" << endl;
    cout << "What Would You Like To Do? (ADD/PRINT/DELETE/AVERAGE/QUIT/HELP)" << endl;

    cin >> input;

    if (input[1] == 'D' || input[1] == 'd') { // adds student
      add();
    }
    else if (input[1] == 'R' || input[1] == 'r') { // prints all students inputted
      print();
    }
    else if (input[1] == 'E' || input[1] == 'e') { // deletes a student
      myDelete();
    }
    else if (input[1] == 'V' || input[1] == 'v') { // averages gpas
      average();
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

// adds new student to the studentList vector
void add() {

}

// prints all students in vector on seperate lines
void print() {

}

// deletes a student from vector
void myDelete() {

}

void average() {

}

// describes what each input does
void help() {
  cout << "Type \"ADD\" To Enter A New Student" << endl;
  cout << "Type \"PRINT\" To Print Out All Stored Students" << endl;
  cout << "Type \"DELETE\" To Delete A Student" << endl;
  cout << "Type \"AVERAGE\" To Print The Average GPA Of All Students" << endl;
  cout << "Type \"QUIT\" To End Program" << endl;
}
