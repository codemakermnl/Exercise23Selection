//Name :	Surname, Firstname MI.	Date : Date of deadline
//Surname, Firstname MI.
//Section / Schedule : section / Schedule Instructor : Engr. Jaypee F. Pineda
#include <iostream>
#include <string>
#include <stdexcept>
#include <math.h>
#include <cmath>
#define _USE_MATH_DEFINES
#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif
#define SENTINEL 10

using namespace std;

void displayMenuProgram() {
    cout << "\t\t\tSELECTION STRUCTURE [IF ELSE]" << endl << "To start the program, please enter: " << endl << "[1] Student number computation"
        << endl << "[2] Solid Geometry (Volume)" << endl << "[3] Info" << endl;
}

string getInput(string prompt) {
    string input;
    cout << prompt;
    getline(cin, input);
    return input;
}

int getAndValidateIntegerInput(string prompt) {
    string input = getInput(prompt);
    bool isValid = false;
    int val;
    do {
        try {
          val = stoi(input);
          isValid = true;
        }
        catch(invalid_argument& e){
          // if no conversion could be performed
          cout << "\n\tInvalid input. Please input a positive integer.\n" << endl;
          input = getInput(prompt);
        }
        catch(out_of_range& e){
          // if the converted value would fall out of the range of the result type
          // or if the underlying function (std::strtol or std::strtoull) sets errno
          // to ERANGE.
            cout << "\n\tInteger input is out of range. Please input within the given range.\n" << endl;
            input = getInput(prompt);
        }

    }while( !isValid );

    return val;
}

string toCardinalString( int number ) {
	if( number == 1 ) {
		return "1st";
	}else if(number > 1 && number < 4) {
		return to_string(number) + "nd";
	}
	
	return to_string(number) + "th";
}

// student number: 2085 7691
void studentNumberComputation() {
	int numbers[SENTINEL];
	string tenNumbers = "";
	int total = 0;
	for( int index = 0; index < SENTINEL; index++ ) {
		numbers[index] = getAndValidateIntegerInput("Enter your " + toCardinalString(index+1) + " number: ");
		tenNumbers += to_string(numbers[index]) + " ";
		total += numbers[index];
	}
	
	cout << "The " << SENTINEL << " numbers are " << tenNumbers << "." << endl;
	cout << "The sum of 7th, 6th, 9th and 1st number : " << numbers[6] + numbers[5] + numbers[8] + numbers[0] << endl;
	cout << "The product of 9th and 1st number : " << numbers[8] * numbers[0] << endl;
	cout << "The average of all " << SENTINEL << " numbers : " << (total/SENTINEL) << endl;
	
}

void solidGeometryComputation(){
	cout << "Computing for volume of Cylinder" << endl;
	double radius;
	double height;
	cout << "Enter radius: ";
	cin >> radius;
	cout << "Enter height: ";
	cin >> height;
	cout << "The Volume of the cylinder is " << M_PI * radius * radius * height << endl;
}

void displayInfo(string name, string studentNumber, string course, string favorite1, string favorite2, string favoriteQuotation) {
	cout << "Name: " << name << endl;
	cout << "Student Number: " << studentNumber << endl;
	cout << "Course: " << course << endl;
	cout << "Favorite : " << favorite1 << endl;
	cout << "Favorite : " << favorite2 << endl;
	cout << "Favorite Quotation: " << favoriteQuotation << endl;
	cout << endl;
}

void info() {
	displayInfo("John Doe", "1234", "BS CS", "1", "2", "Time is money");
	displayInfo("Jane Doe", "1234", "BS CS", "1", "2", "Time is money");
}


int main()
{
	displayMenuProgram();
	int choice = getAndValidateIntegerInput("\nEnter choice: ");
	
	switch(choice) {
		case 1:
			studentNumberComputation();
			break;
		case 2:
			solidGeometryComputation();
			break;
		case 3:
			info();
			break;
	}
	
    return 0;
}



