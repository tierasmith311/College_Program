#include "student.h"
#include "array.h"
#include <iostream>
#include "price.h"
using namespace std;
//this is implementation file, bodies of memeber function


//default constructor (no parameters)
Student::Student()
{
  fName = "unknown";
  lName = "unknown";
  gender = 'X';
  stuID = -1;
  //  sizeOfArray = 0; // my numClass
    numClass = 0;
  
}

//class_name::functionName()
//non default constructir
Student::Student(string f, string l, char g, int i)
{  fName = f;
  lName = l;
  gender = g;
  stuID = i;
  // sizeOfArray = 0;
   numClass = 0; //initial value. when new student is made they have no classes

}
//
int Student::addCourse(int crn)
{
    //anywhere u see size of array replace with this
    //int sizeOfAr = this->sizeOfArray;


    //if array is full
    if (numClass >= MAX) {
      return -1; //full
    }

    int findResult = find(classes, numClass, crn);
    //if 
    if (findResult != -1) {
      return 0; // return 0 because already exists in the array
    }
    else {
      //added succssfully
      classes[numClass++] = crn;
      return 1;
    }

}

void Student::viewAllCourses() const
{
  print(classes, numClass);
}


// bool remove(ourArray, sizeOfArray, crn)
bool Student::dropCourse(int crn)
{
  bool rem = remove(classes, numClass, crn);

  if(rem == true)
    {
      numClass--;
      return true;
    }else if(rem == false)
    {
      return false;
    }
  
}
//making get and set functions

string Student::getFirstName() const
{
  return fName;
}

int Student::getNumClass() const
{
  return numClass;
}
string Student::getLastName() const
{
  return lName;
}

char Student::getGender() const
{
  return gender;
}

int Student::getStuID() const
{
  return stuID;
}


//returns crn at i from classes array 
int Student::getClassOf(int i) const
{
 
  int temp = classes[i];
  // int key;
  // if(temp == key)
   
      return temp;
   
}
Price Student::getBalance() const
{
  
  return balance;
}

void Student::addFee(int d, int c)
{
  Price p(d, c); // make a new price from d and c
  
   balance = balance + p;
  //  Price balace = p;
  //add it to balance
  
}

void Student::reduceFee(int d, int c)
{
  Price p(d, c);
  balance = balance - p;

}

