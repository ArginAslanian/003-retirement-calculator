/**
 * Programmer: Argin Aslanian
 * Purpose: This program will ask for current age and retirement age from
 *          the user and compute how many years the user has until retirement,
 *          and in what year will they retire.
 */

#include <iostream>
#include <ctime>
#include <limits>
using namespace std;

//Function declarations.
int getCurrentYear();
int getUserValidatedInput();
int getYearsToRetirement(int retirementAge, int currentAge);
int getRetirementYear(int currentYear, int retirementAge, int currentAge);

int main() {

    //Declare variables.
    int currentYear = getCurrentYear();
    int currentAge;
    int retirementAge;

    //Instructions.
    cout << "1. Enter your age. Round your age up, no decimals. [ 25 ] " << endl;
    cout << "2. Enter the age you would like to retire. Round up, no decimals. [ 65 ] " << endl << endl;

    //Get user's current age.
    cout << "Current age? ";
    currentAge = getUserValidatedInput();

    //Get user's desired retirement age.
    cout << "Retirement age? ";
    retirementAge = getUserValidatedInput();

    //Display appropriate message based on the user's age and retirement age.
    if (getYearsToRetirement(retirementAge, currentAge) > 0) {
        cout << "You have " << getYearsToRetirement(retirementAge, currentAge) << " year(s) left until retirement. " << endl;
        cout << "It's " << currentYear << ", so you will retire in " << getRetirementYear(currentYear, retirementAge, currentAge) << "." << endl;
    } else {
        cout << "You can retire NOW!" << endl;
    }

    return 0;
}

//Get current year.
int getCurrentYear() {
    time_t t = time(NULL);
    tm* timePtr = localtime(&t);
    return timePtr->tm_year + 1900;
}

//Validate user inputs.
//NOTE: RECURSIVE FUNCTION!
int getUserValidatedInput() {
    int retVal = 0;

    //Input has to be int.
    while(!(cin >> retVal)) {
        cout << "Error: Enter age again: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    //Input cannot less than 1.
    if (retVal < 1) {
        cout << "Error: Age cannot be less than 1. Try again.";
        retVal = getUserValidatedInput();
    }

    return retVal;
}

//Calculate years left until retirement.
int getYearsToRetirement(int retirementAge, int currentAge) {
    if (retirementAge - currentAge > 0) {
        return retirementAge - currentAge;
    } else {
        return 0;
    }
}

//Calculate retirement year.
int getRetirementYear(int currentYear, int retirementAge, int currentAge) {
    return currentYear + (retirementAge - currentAge);
}