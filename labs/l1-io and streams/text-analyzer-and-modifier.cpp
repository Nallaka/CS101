//
// Created by mithu on 1/23/2021.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//Returns the number of characters in usrStr
int GetNumOfCharacters(const string usrStr) {

    int chars = 0;

    for (char i : usrStr) {
        chars++;
    }
    return chars;
}

int main() {
    cout << "Enter a sentence or phrase:" << endl;
    string str;
    getline(cin, str);

    cout << endl << "You entered: " << str << endl;

    cout << endl << "Number of characters: " << GetNumOfCharacters(str) << endl;

    int num = 0;

    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    cout << "String with no whitespace: " << str << endl;
}