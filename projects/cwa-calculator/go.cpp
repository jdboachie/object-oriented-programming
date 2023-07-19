#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	string studentName;
	string studentID;
	string courseID;
	string courseName;
	float score;
	float weightedScore;
	float totalWeightedScore = 0;
	double CWA;
	int weight;
	int totalWeight = 0;
	int numCourses;

	cout << setw(26) << "STUDENT INFO" << endl;
	cout << "------------------------------------------" << endl;
	cout << setw(20) << "ID: " << setw(20);
	getline(cin, studentID);
	cout << setw(20) << "Name: " << setw(20);
	getline(cin, studentName);
	cout << setw(20) << "Courses: " << setw(20);
	cin >> numCourses;
	cin.ignore();
	cout << "------------------------------------------" << endl;

	cout << endl << setw(23) << "SCORES" << endl;
	cout << "------------------------------------------" << endl;
	for (int i = numCourses; i != 0; i--)
	{
		cout << setw(20) << "CourseID: ";
		getline(cin, courseID);
		cout << setw(20) << "Course name: ";
		getline(cin, courseName);
		cout << setw(20) << "Score: ";
		cin >> score;
		cin.ignore();
		cout << setw(20) << "Weight: ";
		cin >> weight;
		totalWeight += weight;
		cin.ignore();
		weightedScore = weight * score;
		totalWeightedScore += weightedScore;
		cout << setw(20) << "Weighted Score: " << weightedScore << endl;
		cout << "------------------------------------------" << endl;
	}

	CWA = totalWeightedScore / totalWeight;

	cout << endl << setw(23) << "SUMMARY" << endl;
	cout << "------------------------------------------" << endl;
	cout << setw(20) << "TotalWeightedScore: " << totalWeightedScore << endl;
	cout << setw(20) << "Total Weight: " << totalWeight << endl;
	cout << "------------------------------------------" << endl;
	cout << setw(20) << "CWA: " << CWA << endl;
	cout << "------------------------------------------" << endl;
}