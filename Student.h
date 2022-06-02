#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <sstream> // give us stringstream

//------------------------------------------------------------
class Student
{
	public:
		Student(std::string studentInformation);
		~Student();
		
		// Accessors
		std::string getFirstName(); 
		std::string getLastName(); 
		
		// both first name + last name
		std::string getName();
		
		int getID();
		double getGPA();
	
	private:
		std::string firstName;
		std::string lastName;
		int id;
		double gpa;
		
//	protected:
};
//-------------------------------------------------------------

#endif