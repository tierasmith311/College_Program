#include <iostream>
#include <cstdlib> //for atoi() <-- you might not use this
using namespace std;
#include "/cs/slott/cs211/checkInput.h"
#include <fstream>
#include <cstdlib>
#include "price.h"
#include "student.h"
#include "array.h"

const int SIZE = 100; //size of the array
const int START = 100000;//student id starts at 100000
const int PASSWORD = 123; //password for admission's office 
const int PRIME1 = 31; //used to calculate a student's password
const int PRIME2 = 5;



int showMenu();
int showAdmMenu();
int showStuMenu();

void addStu(Student[], int&, int&);
void showStuInfo(const Student&);
void allStuInfo( Student[], int&);
void removeStu(Student[], int&);
void addStuFromFile(Student[], int&, int&);
bool operator==(const Student&, int);
int addCourse( Student &);
int dropCourse(Student &);
int makePayment( Student &);
bool checkPassword(int );
int findStu(Student [], int );


int main()
{
  int count = 0; //the number of students in the array
  int curID = START; //curID is the student id used for the next student you are creating
  Student students[SIZE]; //making an array of students with SIZE slots 
  int menuChoice;
  int admChoice;
  int stuChoice; 
  int classNum;

  do
    {
      menuChoice = showMenu();
      switch(menuChoice)
	{
	case 1:
	  {
	    int admPass = checkPassword(PASSWORD);
	    if(admPass == true)  
	      {
		do
		  {
		    admChoice = showAdmMenu();
		    if(admChoice == 1) //adding a new student 
		      {
			cout << "in choice 1" << endl;
			addStu(students, curID,count );
		      }
		    else if(admChoice == 2) //adding student from file         
		      {
			cout << "in choice 2" << endl;
			addStuFromFile(students, count, curID);
		      }
		    else if(admChoice == 3) //removing student
		      {
			cout << "in choice 3" << endl;
			removeStu(students, count);
		      }
		    else if(admChoice == 4)
		      {
			cout << "in choice 4" << endl;
			int b = findStu(students, SIZE);
			if( b == -1 )
			  {
			    cout << "cant find student" << endl;
			  }
			else
			  {
			    showStuInfo(students[b]);
			  }
		      }
		    else if(admChoice == 5) //show all students
		      {
			cout << "in choice 5" << endl;
			allStuInfo(students,count);
		      }
		  }while(admChoice != 6);//do while
	      }//if admpass = true
	    else
	      {
		//break;
	      }
	    	  	  break;
	  }//case 1 {}
	  
	case 2:
	  {
	    findStu(students, SIZE);
	    int student_id = START;
	    //	    int studentID = student_id 
	      int stuPassword = checkPassword(student_id % (PRIME1 * PRIME2));
	    if(stuPassword == true) //if the password is correct              
	      { 
		cout << "Welcome " <<  endl;
		do
		  {
		    stuChoice = showStuMenu();
		    if(stuChoice == 1) //add a course                            
		      {
			addCourse(students[count]);                            
		      }
		    else if(stuChoice == 2) //dropping course from stu          
		      {
			dropCourse(students[count]);                                                                                               
		      }
		  else if(stuChoice == 3) //make a payment                    
		    {
		      makePayment(students[count]);
		    }
		  else if(stuChoice == 4) // view info                        
		    {
		      showStuInfo(students[count]);
		    }
		  }while( stuChoice != 5);//while()
	      }
	    else 
	      {
		//empty, else for if stupassword
	      }
	    break;
	  }//ifmenuc = 2
	case 3: 
	    {
	      exit(1);
	    }
	default:
	cout << "default" << endl;
	}
    }while (menuChoice != 3 ); //do while for menu choice {}




  return 0;
}



// ************************  PHASE 1  ****************************

/******************************************** 
students[] holds the array of students objects
stuid holds student id and will increment
stucount holds total number of students

*********************************************/
void addStu(Student students[], int& stuID, int &count)
{
//case 1 of admission
  // to add a student, we must know the first name, last name, and gender...so create variables to store these values
  string firstName, lastName;
  char gender;

  // take in user input
  cout << "Enter student first name: ";
  cin >> firstName;
  cout << "Enter student last name: ";
  cin >> lastName;
  cout << "Enter student gender: ";
  cin >> gender;
  
  //call the student constructor to create a student, increment the studentID as we add more in the array
  Student s(firstName, lastName, gender, stuID++ ); //student object
  students[count++] = s; //store student object into the array increment since were adding
  cout << endl;
  /*
create a student object. The first student created is given a stu id, 100000 (coming from const START).
The second student gets 100001, the third student gets 100002, etc (notice curID in main).

copy the info from the stu obj into the array at the appropriate slot
	    */  
}                                     

void  showStuInfo( const Student &s) //pass ONE student object - NOT the array ) 
{                                                                                 
//*********************************************************************
//DO NOT send the entire array to this function. BIG deduction if you do.
//SEND only ONE student object as a parameter. If you don't know how, check
//lab1-struct.cpp.
//********************************************************************** 

//use getters
  int studentID;

  cout << "--------------------" << endl;                   

  cout << "first name: " <<  s.getFirstName()  << endl;                   //to show first name                               
  cout << "last name: " << s.getLastName() << endl;                        //to show last name                                                    
   cout << "gender: " << s.getGender()<< endl;                                 //to show gender                                                 
  cout << "stu id: " << s.getStuID() << endl;           // to show students id    
  cout << "num classes: " << s.getNumClass() << endl; //
  cout << "Courses: ";                                                                                                                        
  //we go through a loop to count the number of classes
  for(int i = 0; i < s.getNumClass() ; i++)  //Don't use showAllCourses() but show each course at a time. Which memeber function shows one course?      
    cout << s.getClassOf(i)  << ", "; //display i

  cout << "\nAmount owed $" << s.getBalance()  << endl;  //You have an operator overloading function to show a price object at once                   
 
  cout << endl;
 
}


void allStuInfo( Student s[], int &count)
{
//Case 5 of Admission and case 4 of student
//Call showStuInfo()
//******************************************
//YOU MUST call showStuInfo() to show each student.
//*******************************************
  for(int i = 0; i < count; i++)
    {
      //we go through a the student array with a loop to show all of the students that has been added so far. condition is with count because its the array size, so it loops based on how many students gets added
      showStuInfo(s[i]); //call showstuinfo with s[i]
    }
  
}
/********************************************                                                                                                            
student& s is for the condition
int id is used for the condition

this function is for the remove student function
*********************************************/

bool operator==(const Student& s, int id) 
{
  //if the id from the student the user added matches the 
  if(s.getStuID() == id)
    {
      return true; //if student id is the same as t
    }else{
    return false;
  } // return false if conditional is false
}
/********************************************                                                                                                            
students[] holds the array of students objects                                                                                                           stucount holds total number of students                                                                                                                 
this function is to remove a student by the id the user inputs.
using find function                                                                                                                                                          
*********************************************/

void removeStu(Student s[], int& stuCount)
{
//Case 3 of Admission

//2 different messages
  int stuId; // variable for the find function ( the student id )
  // User provides the student id that he wants to remove.
  cout << "Enter the student ID: ";
  cin >> stuId;

  //using find function from array.h  to see if the specified student ID is within the student array.
  int index = find(s, stuCount, stuId);

  // if the find function returns -1, then the student is not in the student array.
  if (index == -1) {
    cout << "student with id " << stuId << " does not exist." << endl;
    return;
  }
  // otherwise, we can successfully remove the student.
  else {
    remove(s, stuCount, stuId);
    cout << s[index].getFirstName() << " " << s[index].getLastName() << " has been removed" << endl;
    stuCount--;
  }
}
/********************************************                                                                                                            
students[] holds the array of students objects                                                                                                           
stuid holds student id and will increment                                                                                                                
stucount holds total number of students                                                                                                                  
this function is to add a student from the file                                                                                                         *dont forget to use include <fstream>, open and close the file                                                
*********************************************/
// parameters is the student array, 
void  addStuFromFile(Student s[], int& stuCount, int& stuId)
{
//Case 2 of admission

  ifstream fin; // file input stream
  string filename;
  string fName;
  string lName;
  char gender;

  cout << "Enter a filename: ";
  cin >> filename;
  fin.open(filename.c_str());

  if (!fin.is_open()) { // if the user enters a different file name 
    cout << filename << " does not exist." << endl; //cout it doesnt exist
    return;
  }

  // as long as it's not the end of the file, we keep looping
  while (!fin.eof()) {
    fin >> fName; // getting first name
    fin >> lName; //getting last name 
    fin >> gender; // basicall getting the gender from main

    // now that we have read in from the file all the info that we need, we can create a Student object
    Student student(fName, lName, gender, stuId++);

    //  we now have a Student object, we add it to the Student array. 
    s[stuCount++] = student;
  }
  fin.close(); // when we are done reading from the file, make sure to close!
}
//*******************  PHASE 2 ****************************

int addCourse( Student &s)
{
  int courseNum;

//case 1 of student
//FYI, I am passing one student to this function not the array. 
  cout << "Enter a course to add" << endl;
  cin >> courseNum;
  
  if(s.addCourse(courseNum) == 1)
    {
      s.addFee(50, 14);
      cout << " has been added successfully" << endl;

    }else if(s.addCourse(courseNum) == 0)
    {
      cout <<  "course  was not added because you have " << courseNum << " already." <<  endl;
    }else if(s.addCourse(courseNum) == -1)
    {
      cout << " was not added because your schedule is full." <<  endl;
    }
}


int dropCourse(Student &s)
{
//case 2 of admission
//FYI, I am passing one student to this function not the array. 
  int courseNum;
  
  cout << "Enter a course to drop:" << endl;
  cin >> courseNum;  
  
  if (s.dropCourse(courseNum) == false)
      {
	cout << " wasn't dropped from " << s.getFirstName() << " because " << courseNum << " doesn't exist" << endl;

      }else
      {
	s.reduceFee(50, 14);
        //      remove(classes, numClass, courseNum );    
        cout << " has been dropped successfully." << endl;
      }
}


int makePayment( Student &s)
{
//case 3 of student
//FYI, I am passing one student to this function not the array.  

  int dollar;
  int cent;
  cout << "You owe " << s.getBalance() <<  endl;
  cout << "Enter your payment: " << endl;
  cin >> dollar >> cent;

  s.reduceFee(dollar,cent);  


}

//******************** PHASE 3 ****************************
/*
  if student id is 10000 , student_id & (PRIMe1 * prime2)
 */
bool checkPassword(int passWord)
{
  int password;
  cout << "Enter the password : " << endl;
  cin >> password;
  if(password == passWord )
    {     
      return true;
    }else{
    cout << "Invalid password" << endl;
    return false;

  }

//I am using this function to check a password for both the admission's office and student
//FYI, I am passing the correct password as a parameter and returning true/false.
//The correct password for a student is  student_id % (PRIME1 * PRIME2)
}


int findStu(Student s[], int size)
{
  int stuID;
//Small function. You may choose not to use this function. That is OK.
  cout << "Enter student id" << endl; 
  cin >> stuID;
  int id = find(s, size, stuID);
  if (id == -1)
    {
      cout << " The student ID doesnt exist " << endl;
    }
  return id;
//Ask for the student id
//call find() to find the student id
//return what find() returned which is index where it was found or -1
}


void  viewStuInfo(Student s[], int& stuCount)
{
  int stuID;
//Case 4 of admission
//Ask for the student id
  cout << "Enter student id" << endl; 
  cin >> stuID;
  int findStu = (s, stuCount, stuID);

  if(findStu == -1 )
    {
      cout << "the student ID does not exist." << endl;
    }
  else 
    {
      showStuInfo(s[stuID]);
    }
//If the student doesn't exist, show an error message.
//If it exists, call showStuInfo to show the student
}

/*
int verifyStu(Student s[], int& stuCount)
{

//You may decide not to use this function. If so, that is OK.

//When the user is a student, select 2 in the top menu. He/she enters hi/her student id.
//Make sure the stuent id exists in the array. If not, I am showing an error message.
//FYI, I am returning the index where the student was found or -1 if not found.
  int stuID;
  cout << "Enter student id: " << endl;
  cin >> stuID;
  int verify = find(s, stuCount, stuID);
  if(verify == -1)
    {
      cout << "student id does not exist." << endl;
    }
  else 
    {
      return verify;
    }

    }*/


int showMenu()
{
  int choice;
  cout << "========================================================" << endl;
  cout << "1: Admission's Office" << endl;
  cout << "2: Student" << endl;
  cout << "3: End program" << endl;
  cout << "========================================================" << endl;
  cout << "Enter your choice: ";
  choice = getData(1, 3, "\tInvalid choice. Enter only 1, 2 or 3: ");

  return choice;
}


int showStuMenu()
{
  int choice;

  cout << endl;
  cout << "***************************" << endl;
  cout << "1: Add a course" << endl;
  cout << "2: drop a course" << endl;
  cout << "3: Make a payment" << endl;
  cout << "4: View my information" << endl;
  cout << "5: Quit" << endl;
  cout << "***************************" << endl;
  cout << "Enter your choice: ";
  choice = getData(1, 5, "\tInvalid choice. Enter only 1 through 5: ");

  return choice;
}

int showAdmMenu()
{
  int choice;

  cout << endl;
  cout << "***************************" << endl;
  cout << "1: Add a new student" << endl;
  cout << "2: Add new students from a file" << endl;
  cout << "3: drop a student" << endl;
  cout << "4: View one student info" << endl;
  cout << "5: View all students' info" << endl;
  cout << "6: Quit" << endl;
  cout << "***************************" << endl;
  cout << "Enter your choice: ";
  choice = getData(1, 6, "\tInvalid choice. Enter only 1 through 6: ");

  return choice;
}



