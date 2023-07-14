#include <iostream>
#include <iomanip>
#include <string>
#include <map>

using namespace std;

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
		cout << "-----------------------------------------" << endl;
		cout << "|" << setw(20) << "ID: " << id << "     \t|" << endl;
		cout << "|" << setw(20) << "Name: " << name << "\t|" << endl;
		cout << "|" << setw(20) << "Courses: " << numCourses << "\t        \t|" << endl;
		cout << "-----------------------------------------" << endl;

		cout << setw(23) << "SCORES" << endl;
		cout << "-----------------------------------------" << endl;
		for (const auto &pair : scores)
		{
			const Grade &grade = pair.second;
			cout << "|" << setw(20) << "CourseID: " << grade.getCourseID() << "        \t|" << endl;
			cout << "|" << setw(20) << "Course name: " << grade.getCourseName() << "        \t|" << endl;
			cout << "|" << setw(20) << "Score: " << grade.getScore() << "          \t|" << endl;
			cout << "|" << setw(20) << "Weight: " << grade.getWeight() << "           \t|" << endl;
			cout << "|" << setw(20) << "Weighted score: " << grade.getWeightedScore() << "         \t|" << endl;
			cout << "-----------------------------------------" << endl;
		}

		cout << setw(23) << "SUMMARY" << endl;
		cout << "-----------------------------------------" << endl;
		cout << "|" << setw(20) << "TotalWeightedScore: " << this->weightedScore << "        \t|" << endl;
		cout << "|" << setw(20) << "TotalWeight: " << this->totalWeight << "             \t|" << endl;
		cout << "|" << setw(20) << "CWA: " << this->CWA << "        \t|" << endl;
		cout << "-----------------------------------------" << endl;
	}
};

class CWACalculator
{
private:
	Student *student;
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
		return this->totalWeightedScore / this->totalWeight;
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
	// TEST (main function will be developed later)
	Student student("Nathaniel Kwakye", "123456", 3);
	CWACalculator calculator(&student);

	map<string, Grade> userInputedScores; // Dictionary of scores
	userInputedScores["C++"] = Grade("C++", "IT002", 87, 3);
	userInputedScores["Java"] = Grade("Java", "IT003", 71, 2);
	userInputedScores["Python"] = Grade("Python", "IT005", 76, 4);
	userInputedScores["Bilibili"] = Grade("Bilibili", "IT006", 71, 2);
	userInputedScores["Tuday"] = Grade("Tuday", "IT007", 76, 4);

	student.setScores(userInputedScores);
	student.setCWA(calculator.getCWA());
	student.setWeightedScore(calculator.getTotalWeightScore());
	student.setTotalWeight(calculator.getTotalWeight());
	student.show();
}
