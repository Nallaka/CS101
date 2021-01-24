//
// Created by mithu on 1/23/2021.
//

/*
 * 3.27 LAB: Name format
Many documents use a specific format for a person's name. Write a program whose input is:

firstName middleName lastName

and whose output is:

lastName, firstInitial.middleInitial.

Ex: If the input is:

Pat Silly Doe
the output is:

Doe, P.S.
If the input has the form: firstName lastName

the output is:

lastName, firstInitial.

Ex: If the input is:

Julia Clark
the output is:

Clark, J.
 * */
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {

    string fullName;

    getline(cin, fullName);

    //cout << fullName << endl;

    string firstName;
    string middleName;
    string lastName;

    std::istringstream inSS(fullName);

    inSS >> firstName;
    inSS >> middleName;
    inSS >> lastName;

    if (lastName.empty()) {
        cout << middleName << ", " << firstName.at(0) << "." << endl;
    } else {
        cout << lastName << ", " << firstName.at(0) << "." << middleName.at(0) << "." << endl;
    }



}