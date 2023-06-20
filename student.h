#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include "price.h"
using namespace std;
//contains data memebers and prototypes of memeber functions(behaviors)
const int MAX = 6;


class Student
{
  //attributes
  
 private:
  string fName;
  string lName;
  int stuID;
  char gender;
  int numClass;
  //  int sizeOfArray;
  int classes[MAX];
  Price balance;
  //behaviors 
 public:


  Student();
  Student(string f, string l, char g, int i);
  int addCourse(int);
  void viewAllCourses() const;
  string getFirstName() const;
  string getLastName() const;
  int getNumClass() const;
  char getGender() const;
  int getStuID() const;
  Price getBalance() const;
  void addFee(int, int);
  void reduceFee(int, int);
  int getClassOf(int) const;
  bool dropCourse(int);
  

};


#endif
