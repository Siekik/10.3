#include <iostream>
using namespace std;
const int STUDENTS = 5;
const int QUIZZES = 3;

int quizTotal (int scores[STUDENTS][QUIZZES], int st);
int main() {
	string first[5];
	string last[5];
	for (int i = 0; i <= 4; i++) {
		cout << "Enter first and last name for student #" << i+1 << " ";
		cin >> first[i] >> last[i];
	}

	// create 2-D array with 4 rows of students having taken 2 quizzes...
	int scores[STUDENTS][QUIZZES];
	// Get the quiz data
	for (int qz = 0; qz < QUIZZES; qz++) {
		for (int st = 0; st < STUDENTS; st++) {
			cout << "Quiz " << (qz + 1) << " score for " << last[st] << ", " << first[st] << ": ";
			cin >> scores[st][qz];
		}
	}
	cout << endl;
	// calculate the average for each quiz
	for (int qz = 0; qz < QUIZZES; qz++) {
		int sum = 0;
		for (int st = 0; st < STUDENTS; st++) {
			sum += scores[st][qz];
		}
		cout << "Quiz " << (qz + 1) << " average: " << (double)sum / STUDENTS << endl;
	}
	cout << endl;
	// calculate the total score for each student
	for (int st = 0; st < STUDENTS; st++) {
		cout << last[st] << ", " << first[st] << " total score: " << quizTotal(scores,st) << endl;
	}
	cout << endl;
	// display contents of array in sequential order
	// Using concepts from Chapter 7 - pointers
	// Don't worry about not understanding this code at this time...
	// but we're definitely not in Kansas anymore, Toto...
	int* ptr = &scores[0][0];
	for (int i = 0; i < STUDENTS * QUIZZES; i++) {
		cout << "Cell " << i << ": " << *ptr++ << endl;
	}
	return 0;
}
int quizTotal(int scores[STUDENTS][QUIZZES], int st) {
	int total = 0;
	for (int qz = 0; qz < QUIZZES; qz++) {
		total += scores[st][qz];
	}
	return total;
}