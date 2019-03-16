

#include <iostream>
#include <iomanip>
#include <random> // contains C++11 random number generation features
#include <ctime>
#include <cstdlib>
using namespace std;

void askQuestion();

int main() {
	while (1) {
		askQuestion();
	}
	system("pause");
	return 0;
} // end main

void askQuestion() {
	// use the default random-number generation engine to
	// produce uniformly distributed pseudorandom int values from 1 to 9
	static default_random_engine engine(static_cast<unsigned int>(time(0)));
	static uniform_int_distribution<unsigned int> randomInt(1, 9);

	// pick two random numbers from 1 to 9
	int operand1 = randomInt(engine); // first operand
	int operand2 = randomInt(engine); // second operand
	int response = 0; // student's response to question

	cout << "How much is " << operand1 << " times " << operand2 << "? ";
	cin >> response;

	while (response != operand1 * operand2) {
		cout << "No. Please try again." << endl;
		cout << "How much is " << operand1 << " times " << operand2 << "? ";
		cin >> response;
	}
	cout << "Very good!" << endl;
}
