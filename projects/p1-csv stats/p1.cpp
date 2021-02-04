//
// Created by mithu on 1/27/2021.
//
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>

using namespace std;

int main(int argc, char* argv[]) {
    //Check Command line arguments
    if (argc != 3) {
        cout << "Usage: ./a database.csv #col_width" << endl ;
        return 0;
    }

    //Assign path and colWidth
    string path = argv[1];

    std::istringstream ss(argv[2]);
    int colWidth;

    ss >> colWidth;

    //Open and check file stream
    std::ifstream ifstream1(path);

    if (!ifstream1.is_open()) {
       cout << "Failed to open " << path << endl;
       return 0;
    }

    string columnNames;
    getline(ifstream1, columnNames);

    stringstream columnNameStream(columnNames);
    int columns = 0;

    while (columnNameStream.good()) {
        string columnName;
        getline(columnNameStream, columnName, ',');
        columns++;
    }

    string line;
    int entires = 0;
    while (getline(ifstream1, line)) {
        stringstream string_stream(line);
        entires++;
    }

    string data[entires+1][columns];

    ifstream1.clear();
    ifstream1.seekg(0,std::ios::beg);

    columnNameStream.clear();
    columnNameStream.seekg(0,std::ios::beg);

    //Assign Column Names
    int i = 0;
    while (columnNameStream.good()) {
        string columnName;
        getline(columnNameStream, columnName, ',');
        data[0][i] = columnName;
        columns++;
    }

    string temp;
    getline(ifstream1, temp);

    string newline;
    int entry = 1;
    while (getline(ifstream1, newline)) {
        stringstream stringstream1(newline);
        int field = 0;
        while (stringstream1.good()) {
            string new_sub_string;
            getline(stringstream1, new_sub_string, ',');
            data[entry][field] = new_sub_string;
        }
    }

}