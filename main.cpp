// Based on youtube serie
// https://www.youtube.com/watch?v=NIoEVxe-rpk&t=3s

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <exception>

#include "Student.h"
#include "StudentList.h"

using namespace std;

void printStudent(Student student);

//--------------------------------------------------------------
int main(int argc, char** argv) 
{	
// Just to test class Student
//	Student student ("Goody Two-Shoes 8534 99.6");

 	//Just to test class StudentList, you need vector students in public scope
 	try
 	{
		StudentList list("dataFile.txt"); // the same directory as the executable
		
		cout << "\n\n\tValedictorian: \n";
		printStudent(list.getValedictorian());
		
		cout << "\n\n\tHonor Role Students: \n";	
		for (Student s : list.getHonorRoleStudents())
		{
			printStudent(s); 
		}	

		cout << "\n\n\tFailing Students: \n";	
		for (Student s : list.getFailingStudents())
		{
			printStudent(s); 
		}		
			
	}
	catch (exception &e)
	{
		cout << "\n\n\tError! An exception was thrown!";
		cout << e.what() << endl;
	}

	
//	
//	cout << "\n\n\tFirst iteration method:";
//	for (Student s: list.students)
//	{
//		printStudent(s);
//	}
//	// alternative
//	cout << "\n\n\tSecond iteration method:";
//	for (int i = 0; i<list.students.size(); i++)
//	{
//		Student s = list.students.at(i);
//		printStudent(s);
//	}


	
	//------------------------------------------------------------
	cout << "\n\n\t";
	system("pause");
	return 0;	
}
//----------------------------------------------------------------
//----------------------------------------------------------------
void printStudent(Student student)
{
	cout << "\n\n\t----------studentInformation-------------";
	cout << "\n\tName: " << student.getName();
	cout << "\n\tID: " << student.getID();
	cout << "\n\tGPA: " << student.getGPA();
	cout << "\n\t--------------------------------------------";	
}
//----------------------------------------------------------------