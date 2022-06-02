// Standard headers

// Local headers
#include "StudentList.h"

#define FAILING_GRADE 65
#define HONORROLE_GRADE 90

using namespace std;

//------------------------------------------------------------
StudentList::StudentList(string filePath)
{
	//cout << "\n\n\tBuilding a Students List...";
	
	ifstream studentFile(filePath);
	
	string lineContent;
	while(!studentFile.eof())
	{
		// get a line from studentFile and store in lineContent
		// push_back stored line into a vector
		// do it untill end of file is reached
		getline(studentFile, lineContent); 
		
		Student s(lineContent); // stored line is parsed onto student information
		students.push_back(s);	// student information is loaded in a vector (dynamic array)
	}
	
	studentFile.close();
	
	// Sort the information by GPA field with lambda expressions
	// Two elements of the vector students are compared by GPAs
	// Comparisson returns true if the 1st argument is less than the 2nd argument (increase order
	// needs compiler C++11 or above
	sort(students.begin(), students.end(), [](Student &s1, Student &s2)
											{
												//return s1.getGPA() < s2.getGPA(); // increase order
												return s1.getGPA() > s2.getGPA(); 	// decrease order
											});
}
//-------------------------------------------------------------
StudentList::~StudentList()
{
	
}
//-------------------------------------------------------------
Student StudentList::getValedictorian()
{
	if (students.size() == 0 || students.at(0).getGPA() < FAILING_GRADE) // if empty list or all students are failing
	// consider size == 0  checked first. If true - throw exception without checking GPA < 65
	// otherwise checking GPA < 65 while size == 0 would crash
	{
		throw NoValedictorianException();
	}
	return students.at(0); // possible since the vector students is sorted
}
//-------------------------------------------------------------
// supposed sorted input list of students
vector<Student> StudentList::getHonorRoleStudents()
{
	vector<Student> toReturn;
	// Iterate all the students and select these above ranking of 90;
	for (Student s : students)
	{
		if (s.getGPA() < HONORROLE_GRADE)
		{
			break; // use the opposite logic as the students are sorted from highest GPA
		}
		else
		{
			toReturn.push_back(s);
		}
	}
	return toReturn;
	
}
//-------------------------------------------------------------
// supposed sorted input list of students
vector<Student> StudentList::getFailingStudents()
{
	vector<Student> toReturn;
	// use reversed iterator as the failing students starts from the bottom of the sorted list
	for (vector<Student>::reverse_iterator iter = students.rbegin(); 
										   iter < students.rend(); 
										   iter++)
	{
		if (iter->getGPA() >= FAILING_GRADE)
		{
			break; // use the opposite logic as the students are sorted
		}
		else
		{
			toReturn.push_back(*iter);
		}	
		
		// Alternative
//		if ((*iter).getGPA() >= FAILING_GRADE)
//		{
//			break; // use the opposite logic as the students are sorted
//		}
//		else
//		{
//			toReturn.push_back(*iter);
//		}		
	}
	
	return toReturn;
}
//-------------------------------------------------------------