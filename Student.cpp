#include <iostream>

#include "Student.h"


using namespace std;

/*! Class  Student
* 
* @param studentInformation A single line from the data file
*
*/
Student::Student(string studentInformation)
{
	//cout << "\n\n\tBuilding a Student.\n";
	stringstream studentStream(studentInformation); // chops the line studentInformation by spaces
	studentStream >> firstName;
	studentStream >> lastName;
	studentStream >> id;
	studentStream >> gpa;	
}

//----------------------------------------------------------
string Student::getFirstName()
{
	return firstName;
}
//----------------------------------------------------------
string Student::getLastName()
{
	return lastName;
}
//----------------------------------------------------------
string Student::getName()
{
	return firstName + " " + lastName;
}
//----------------------------------------------------------
int Student::getID()
{
	return id;
}
//----------------------------------------------------------
double Student::getGPA()
{
	return gpa;
}
//----------------------------------------------------------

Student::~Student()
{
	//cout << "\n\n\tDestroying a Student.";
}
//----------------------------------------------------------
