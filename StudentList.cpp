/*
 * Author: Armaan Hajar
 * Program: A student list creator that inputs the students first name, last name, gpa, and 
 *          student ID to add it to a vector
 * Date: 10/11/2022
 */

#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

// creating Student struct with all the inputs needed
struct Student {
  char firstName[30];
  char lastName[30];
  int studentID;
  float gpa;
};

void newStudent(vector<Student*> &studentList);
void printStudent(vector<Student*> &studentList);
void deleteStudent(vector<Student*> &studentList);
void help();

int main() {
  char input[7];
  bool running = true;
  vector<Student*> studentList;

  // main code, running will stay true unti luser says "QUIT"
  while (running == true) {
    cout << "---------------------------------------------------------" << endl;
    cout << "What Would You Like To Do? (ADD/PRINT/DELETE/QUIT/HELP)" << endl;

    cin >> input;


    if (strcmp(input, "ADD") == 0) { // adds student
      newStudent(studentList);
    }
    else if (strcmp(input, "PRINT") == 0) { // prints all students inputted
      printStudent(studentList);
    }
    else if (strcmp(input, "DELETE") == 0) { // deletes a student from the vector
      deleteStudent(studentList);
    }
    else if (strcmp(input, "QUIT") == 0) { // ends program
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
void newStudent(vector<Student*> &studentList) {
  Student* addStudent = new Student();
  char firstNameTemp[30];
  char lastNameTemp[30];
  int studentIDTemp;
  float gpaTemp;

  // inputting everything
  cout << "What Is The Student's First Name?" << endl;
  cin >> firstNameTemp;
  cout << "What Is The Student's Last Name?" << endl;
  cin >> lastNameTemp;
  cout << "What Is The Student's ID Number?" << endl;
  cin >> studentIDTemp;
  cout << "What Is The Student's GPA?" << endl;
  cin >> gpaTemp;

  // copys from temp variables into the vector
  strcpy(addStudent->firstName, firstNameTemp);
  strcpy(addStudent->lastName, lastNameTemp);
  addStudent->studentID = studentIDTemp;
  addStudent->gpa = gpaTemp;

  studentList.push_back(addStudent);
}

// prints all students in vector on seperate lines
void printStudent(vector<Student*> &studentList) {
  cout << "Here Are All The Students You've Listed So Far:" << endl;
  char buffer[10];

  // does a for loop to print all students
  for (int i = 0; i < studentList.size(); i++) {
    sprintf(buffer, "%.2f", studentList.at(i)->gpa);

    cout << studentList.at(i)->firstName << " "
	 << studentList.at(i)->lastName << ", "
	 << studentList.at(i)->studentID << ", "
	 << buffer << endl;
  }
}

// deletes a student from vector
void deleteStudent(vector<Student*> &studentList) {
  int studentIDTemp;
  cout << "What Is The Student ID Of The Student You'd Like To Delete?" << endl;

  cin >> studentIDTemp;

  // uses student ID to find student and delete them from vector
  for (int i = 0; i < studentList.size(); i++) {
    if ((studentList.at(i)->studentID) == studentIDTemp) {
      studentList.erase(studentList.begin() + i);
      cout << studentIDTemp << " Has Been Deleted" << endl;
    }
    else {
      cout << "This Student Is Not In Your List!" << endl;
    }
  }
}

// describes what each input does
void help() {
  cout << "Type \"ADD\" To Enter A New Student" << endl;
  cout << "Type \"PRINT\" To Print Out All Stored Students" << endl;
  cout << "Type \"DELETE\" To Delete A Student" << endl;
  cout << "Type \"QUIT\" To End Program" << endl;
}
