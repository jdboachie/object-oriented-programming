#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cstdlib>
#include <map>

using namespace std;


class Utils
{
public:
	static void userValidateInput()
	{
		while (true)
		{
			cout << "Is this information correct? (y/n) ";
			char confirm;
			cin >> confirm;
			if (confirm == 'n')
			{
				cout << "Please restart the program and enter the correct information.\n";
				exit(0);
			}
			else if (confirm != 'y')
			{
				cout << "Invalid input\n";
				continue;
			}
			cin.ignore(); // Ignore the newline character left by cin
			break;
		}
	}

	// A lot of other things to validate.
};

class Grade
{
private:
	string courseName;
	string courseID;
	float score;
	unsigned int weight;
	float weightedScore;

public:
	Grade() = default; // Default constructor

	Grade(string courseName, string courseID, float score, unsigned int weight)
		: courseName(courseName), courseID(courseID), score(score), weight(weight)
	{
		this->weightedScore = score * weight;
	}

	unsigned int getWeight() const
	{
		return weight;
	}

	string getCourseID() const
	{
		return courseID;
	}

	string getCourseName() const
	{
		return courseName;
	}

	float getWeightedScore() const
	{
		return weightedScore;
	}

	float getScore() const
	{
		return score;
	}
};

class Student
{
private:
	string name;
	string id;
	unsigned int numCourses;
	float CWA;
	float weightedScore;
	float totalWeight;
	map<string, Grade> scores;

public:
	Student(string name, string id, unsigned int numCourses)
		: name(name), id(id), numCourses(numCourses) {}

	string getName()
	{
		return name;
	}

	string getID()
	{
		return id;
	}

	float getCWA()
	{
		return this->CWA;
	}

	void setCWA(float value)
	{
		this->CWA = value;
	}

	void setWeightedScore(float value)
	{
		this->weightedScore = value;
	}

	void setTotalWeight(float value)
	{
		this->totalWeight = value;
	}

	void setNumCourses(unsigned int numCourses)
	{
		this->numCourses = numCourses;
	}

	void setScores(map<string, Grade> scores)
	{
		this->scores = scores;
	}

	map<string, Grade> &getScores()
	{
		return scores;
	}

	unsigned int getNumCourses()
	{
		return numCourses;
	}

	void show()
	{
		cout << setw(26) << "STUDENT INFO" << endl;
		cout << "------------------------------------------" << endl;
		cout << "|" << setw(20) << "ID: " << setw(20) << id << "|" << endl;
		cout << "|" << setw(20) << "Name: " << setw(20) << name << "|" << endl;
		cout << "|" << setw(20) << "Courses: " << setw(20) << numCourses << "|" << endl;
		cout << "------------------------------------------" << endl;

		cout << setw(23) << "SCORES" << endl;
		cout << "------------------------------------------" << endl;
		for (const auto &pair : scores)
		{
			const Grade &grade = pair.second;
			cout << "|" << setw(20) << "CourseID: " << setw(20) << grade.getCourseID() << "|" << endl;
			cout << "|" << setw(20) << "Course name: " << setw(20) << grade.getCourseName() << "|" << endl;
			cout << "|" << setw(20) << "Score: " << setw(20) << grade.getScore() << "|" << endl;
			cout << "|" << setw(20) << "Weight: " << setw(20) << grade.getWeight() << "|" << endl;
			cout << "|" << setw(20) << "Weighted score: " << setw(20) << grade.getWeightedScore() << "|" << endl;
			cout << "------------------------------------------" << endl;
		}

		cout << setw(23) << "SUMMARY" << endl;
		cout << "------------------------------------------" << endl;
		cout << "|" << setw(20) << "TotalWeightedScore: " << setw(20) << this->weightedScore << "|" << endl;
		cout << "|" << setw(20) << "TotalWeight: " << setw(20) << this->totalWeight << "|" << endl;
		cout << "|" << setw(20) << "CWA: " << setw(20) << this->CWA << "|" << endl;
		cout << "------------------------------------------" << endl;
	}
};

class CWACalculator
{
private:
	Student *student;
	double CWA;
	float totalWeightedScore = 0;
	unsigned int totalWeight = 0;

public:
	CWACalculator(Student *student) : student(student) {}

	float getCWA()
	{
		map<string, Grade> scores = student->getScores();

		for (const auto &pair : scores)
		{
			const Grade &grade = pair.second;
			this->totalWeightedScore += grade.getWeightedScore();
			this->totalWeight += grade.getWeight();
		}
		this->CWA = this->totalWeightedScore / this->totalWeight;
		return CWA;
	}

	float getTotalWeightScore()
	{
		return this->totalWeightedScore;
	}

	float getTotalWeight()
	{
		return this->totalWeight;
	}
};

int main()
{
	start:
	// Input student information
	string name, id;
	unsigned int numCourses;

	cout << "Student name:\t";
	getline(cin, name);

	cout << "Student ID:\t";
	getline(cin, id);

	cout << "No of courses:\t";
	cin >> numCourses;

	Utils::userValidateInput();
	system("cls");

	// Create student object
	Student student(name, id, numCourses);
	CWACalculator calculator(&student);

	// Input grades for each course
	map<string, Grade> userInputedScores; // Dictionary of scores


	cout << endl << "*********** ! ***********" << endl;

	cout << "Enter course information.\nFormat:\n\n\tcoursename courseID score weight\n\n(Remember not to add spaces between the courseName and courseID)\nEg. OOP COE254 80 3\n\n";
	cout << "*************************" << endl << endl;

	for (unsigned int i = 0; i < numCourses; i++)
	{
		string courseInput;
		cout << "Enter course " << i + 1 << " information: ";
		getline(cin, courseInput);

		istringstream iss(courseInput);
		string courseName, courseID;
		float score;
		unsigned int weight;

		// Extract course information from the input line
		iss >> courseName >> courseID >> score >> weight;

		userInputedScores[courseName] = Grade(courseName, courseID, score, weight);
	}

	// Clear the screen
	system("cls");

	// Calculate CWA
	student.setScores(userInputedScores);
	student.setCWA(calculator.getCWA());
	student.setWeightedScore(calculator.getTotalWeightScore());
	student.setTotalWeight(calculator.getTotalWeight());
	student.show();

	return 0;
}
