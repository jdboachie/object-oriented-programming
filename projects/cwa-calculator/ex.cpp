#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <map>

using namespace std;

class Utils
{
public:

	static void waitStart()
	{
		cout << "\033[44m"; // Set the BG TO BLUE
		cout << "Press enter to continue...";
		cin.get();

		cout << "\033[0m"; // Reset the color to the default
		system("cls");
	}

	static void splash()
	{
		cout << "\033[0m"; // Reset the color to the default
		const char *asciiArt = R"(
			 __ .  ..__.   __ .__..    __ .  ..   .__..___..__..__
			/  `|  |[__]  /  `[__]|   /  `|  ||   [__]  |  |  |[__)
			\__.|/\||  |  \__.|  ||___\__.|__||___|  |  |  |__||  \
		)";

		cout << asciiArt << endl;
	}

	static void waitAnimation()
	{
		// Define the loading animation frames
		const char *loadingFrames[] = {"-", "\\", "|", "/"};
		const int numFrames = sizeof(loadingFrames) / sizeof(loadingFrames[0]);

		// Define the duration for each frame in milliseconds
		const int frameDuration = 150;

		// Define the number of iterations for the loading animation
		const int numIterations = 25;

		// Display the loading screen
		for (int i = 0; i < numIterations; ++i)
		{
			std::cout << loadingFrames[i % numFrames] << "          ";
			std::cout.flush(); // Flush the output to ensure immediate display
			std::this_thread::sleep_for(std::chrono::milliseconds(frameDuration));
			// Move the cursor back to the beginning of the line
			std::cout << "\r";
		}

		cout << "\033[0m"; // Reset the color to the default
	}

	static void loadingAnimation()
	{
		cout << "\033[42m"; // Set the bg color to blue

		for (int i = 0; i <= 100; i++)
		{
			cout << " ";
			cout.flush();
			this_thread::sleep_for(chrono::milliseconds(7));
		}
		cout << "\n\n\n";
		cout << "\033[0m"; // Reset the color to the default
	}

	template<typename T>
	static bool isValidType(const T& value)
	{
		if (typeid(value) == typeid(unsigned int) || typeid(value) == typeid(float) || typeid(value) == typeid(double) || typeid(value) == typeid(int))
		{
			return true;
		}
		return false;
	}

	static void userValidateInput()
	{
		while (true)
		{
			cout << "\033[41m"; // Set the background color to magenta
			cout << "Is this information correct? (y/n) ";
			cout << "\033[0m"; // Reset the color to the default
			char confirm;
			cin >> confirm;
			if (confirm == 'n')
			{
				cout << "Please restart the program and enter the correct information.\n";
				exit(0);
			}
			else if ((confirm != 'y') && (confirm != 'Y'))
			{
				cout << "Invalid input\n";
				continue;
			}
			cin.ignore();	   // Ignore the newline character left by cin
			break;
		}
	}

	static bool isValidScore(float score)
	{
		if (score < 0 || score > 100)
		{
			cout << "Invalid score. Please enter a score between 0 and 100.\n";
			return false;
		}
		return true;
	}

	static bool isValidWeight(unsigned int weight)
	{
		if (weight < 1 || weight > 4)
		{
			cout << "Invalid weight. Please enter a weight between 1 and 4.\n";
			return false;
		}
		return true;
	}

	static bool isValidCourseCount(unsigned int numCourses)
	{
		if (numCourses < 1)
		{
			cout << "Invalid number of courses. Please enter a number greater than 0.\n";
			return false;
		}
		return true;
	}

	static void courseInputInfo()
	{
		cout << "\033[34m"; // Set the text color to blue
		cout << endl
			 << "********************** ! **********************" << endl;
		cout << "Enter course information.\nFormat:\n\ncoursename courseID score weight\n\n(Remember not to add spaces between the courseName and courseID)\nEg. OOP COE254 80 3\n";
		cout << "***********************************************" << endl
			 << endl;
		cout << "\033[0m"; // Reset the color to the default
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

	void setCourseName(string courseName)
	{
		this->courseName = courseName;
	}

	void setCourseID(string courseID)
	{
		this->courseID = courseID;
	}

	void setWeightedScore(float weightedScore)
	{
		if (Utils::isValidType(weightedScore))
		{
			this->weightedScore = weightedScore;
		}
		else
		{
			cout << "\033[41m"; // Set the background color to magenta
			cout << "Invalid type. Please enter a valid type.\n";
			cout << "\033[0m"; // Reset the color to the default
		}
	}

	void setScore(float score)
	{
		if (Utils::isValidType(score) && Utils::isValidScore(score))
		{
			this->score = score;
		}
	}

	void setWeight(unsigned int weight)
	{
		if (Utils::isValidType(weight) && Utils::isValidWeight(weight))
		{
			this->weight = weight;
		}
		else
		{
			cout << "\033[41m"; // Set the background color to magenta
			cout << "Invalid weight. Please enter a valid weight.\n";
			cout << "\033[0m"; // Reset the color to the default
		}
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
		// cout << "\033[34m";
		cout << setw(26) << "STUDENT INFO" << setw(16) << " " << endl;
		cout << "------------------------------------------" << endl;
		cout << "|" << setw(20) << "ID: " << setw(20) << id << "|" << endl;
		cout << "|" << setw(20) << "Name: " << setw(20) << name << "|" << endl;
		cout << "|" << setw(20) << "Courses: " << setw(20) << numCourses << "|" << endl;
		cout << "------------------------------------------" << endl;

		cout << setw(23) << "SCORES" << setw(19) << " " << endl;
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

		cout << setw(23) << "SUMMARY" << setw(19) << " " << endl;
		cout << "------------------------------------------" << endl;
		cout << "|" << setw(20) << "TotalWeightedScore: " << setw(20) << this->weightedScore << "|" << endl;
		cout << "|" << setw(20) << "TotalWeight: " << setw(20) << this->totalWeight << "|" << endl;
		cout << "|" << setw(20) << "CWA: " << setw(20) << this->CWA << "|" << endl;
		cout << "------------------------------------------" << endl;
		// cout << "\033[0m"; // Reset the color to the default
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
	system("cls");
	cout << "\033[0m"; // Reset the color to the default
	Utils::waitStart();
	Utils::splash();
	Utils::loadingAnimation();
	cout << "\033[0m"; // Reset the color to the default

	start:
	cout << "\033[0m"; // Reset the color to the default
	// Input student information
	string name, id;
	string numCourses;

	cout << "Student name:\t";
	getline(cin, name);

	cout << "Student ID:\t";
	getline(cin, id);

	cout << "No of courses:\t";
	getline(cin, numCourses);
	int num = stoi(numCourses);

	if (!Utils::isValidCourseCount(num))
	{
		goto start;
	};

	// Utils::userValidateInput();
	while (true)
	{
		cout << "\033[41m"; // Set the background color to magenta
		cout << "Is this information correct? (y/n) ";
		cout << "\033[0m"; // Reset the color to the default
		char confirm;
		cin >> confirm;
		if (confirm == 'n')
		{
			goto start;
			exit(0);
		}
		else if ((confirm != 'y') && (confirm != 'Y'))
		{
			cout << "Invalid input\n";
			continue;
		}
		cin.ignore();	   // Ignore the newline character left by cin
		break;
	}
	// system("cls");

	// Create student object
	Student student(name, id, num);
	CWACalculator calculator(&student);

	// Input grades for each course
	map<string, Grade> userInputedScores; // Dictionary of scores

	Utils::courseInputInfo();

	for (unsigned int i = 0; i < num; i++)
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

		userInputedScores[courseName] = Grade();
		userInputedScores[courseName].setCourseName(courseName);
		userInputedScores[courseName].setCourseID(courseID);
		userInputedScores[courseName].setScore(score);
		userInputedScores[courseName].setWeight(weight);
		userInputedScores[courseName].setWeightedScore(score * weight);
	}

	Utils::userValidateInput();

	Utils::waitAnimation();
	// Clear the screen
	system("cls");
	student.setScores(userInputedScores);
	student.setCWA(calculator.getCWA());
	student.setWeightedScore(calculator.getTotalWeightScore());
	student.setTotalWeight(calculator.getTotalWeight());
	student.show();

	cout << "\n|  Thanks for using our CWA Calculator! :)" << endl;
	return 0;
}
