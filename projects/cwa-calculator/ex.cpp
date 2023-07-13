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

	void setNumCourses(unsigned int numCourses)
	{
		this->numCourses = numCourses;
	}

	void setScores(map<string, Grade> scores)
	{
		this->scores = scores;
	}

	map<string, Grade>& getScores()
	{
		return scores;
	}

	unsigned int getNumCourses()
	{
		return numCourses;
	}

	void show()
	{
		cout << "\n-----------------------------------------" << endl;
		cout << "|" << setw(20) << "ID:\t"<< id << "     \t|" <<endl;
		cout << "|" << setw(20) << "Name:\t" << name << "\t|" <<endl;
		cout << "|" << setw(20) << "Courses:\t" << numCourses << "       \t|" <<endl;
		cout << "-----------------------------------------" << endl;

		cout << setw(23) << "SCORES" << endl;
		cout << "-----------------------------------------" << endl;
		for (const auto& pair : scores)
		{
			const Grade& grade = pair.second;
			cout << "|" << setw(20) << "CourseID:\t"<< grade.getCourseID()<< endl;
			cout << "|" << setw(20) << "Course name:\t"<< grade.getCourseName()<< endl;
			cout << "|" << setw(20) << "Score:\t"<< grade.getScore()<< endl;
			cout << "|" << setw(20) << "Weight:\t"<< grade.getWeight()<< endl;
			cout << "|" << setw(20) << "Weighted score:\t"<< grade.getWeightedScore()<< endl;
			cout << "-----------------------------------------" << endl;
		}
	}
};

class CWACalculator
{
private:
    Student* student;

public:
    CWACalculator(Student* student) : student(student) {}

    float calculate()
    {
        float totalWeightedScore = 0;
        unsigned int totalWeight = 0;
        map<string, Grade> scores = student->getScores();

        for (const auto& pair : scores)
        {
            const Grade& grade = pair.second;
            totalWeightedScore += grade.getWeightedScore();
            totalWeight += grade.getWeight();
        }

        return totalWeightedScore / totalWeight;
    }
};



int main()
{
	Student student("Nathaniel Kwakye", "123456", 3);
	CWACalculator calculator(&student);

	map<string, Grade> scores; // Dictionary of scores
	scores["C++"] = Grade("C++", "IT002", 8.0, 3);
	scores["Java"] = Grade("Java", "IT003", 7.0, 2);
	scores["Python"] = Grade("Python", "IT004", 9.0, 4);

	student.setScores(scores);
	student.show();
}
