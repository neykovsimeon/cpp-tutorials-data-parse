#ifndef STUDENTLIST_H
#define STUDENTLIST_H

// Standard headers
#include <iostream>		//cout, cin
#include <string>
#include <vector>
#include <sstream>		// stringstream
#include <fstream>		// ifstream and ofstream
#include <algorithm> 	// used for sorting information
#include <exception>


// Local headers
#include "Student.h"

class StudentList
{
	public:
		StudentList(std::string filePath);
		~StudentList();
	
	// Memeber methods
		Student getValedictorian();
		std::vector<Student> getHonorRoleStudents();
		std::vector<Student> getFailingStudents();
	
	private:
		std::vector<Student> students;
	
//	protected:
};

// Dedicated class for exceptions handling
class NoValedictorianException : public std::exception
{
	public:
		const char *what() const throw()
		{
			return "\n\n\tStudentList:  No Valedictorian!\n";	
		}	
};

#endif