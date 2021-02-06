//
// Created by mithu on 1/27/2021.
//
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <math.h>

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
       cout << "Failed to open \"" << path << "\"" << endl;
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
    int entries = 1;
    while (getline(ifstream1, line)) {
        if (!line.empty()) {
            entries++;
        }
    }

    //Data Array
    string data[entries][columns];

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
        i++;
    }

    //Assign Fields
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
            field++;
        }
        entry++;
    }

    //Commands
    bool quit = false;

    while (!quit) {
        cout << "Enter a command or \"help\" for a command list:" << endl;

        string commandLine;
        getline(cin, commandLine);
        stringstream commandStream(commandLine);

        string command;
        commandStream >> command;

        //quit
        if (command == "quit") {
            quit = true;
        }

        //help
        if (command == "help") {
            cout << "command list:\n"
                    "        print\n"
                    "        cols\n"
                    "        search *|col_name val\n"
                    "        min col_name\n"
                    "        max col_name\n"
                    "        avg col_name" << endl;
            cout << endl;
            continue;
        }

        //cols
        if (command == "cols") {
            for (int c = 0; c < columns; c++) {
                cout << data[0][c] << endl;
            }
            cout << endl;
            continue;
        }

        //print
        if (command == "print") {
            for (int e = 0; e < entries; e++) {
                for (int c = 0; c < columns; c++) {
                    cout << setw(colWidth) << data[e][c];
                }
                cout << endl;
            }
            cout << endl;
            continue;
        }

        //min
        if (command == "min") {
            string col;
            double min = 1.79769e+308;
            int minC = 0;
            int minE = 0;
            string out = "N/A";
            commandStream >> quoted(col);
            for (int c = 0; c < columns; c++) {
                if (data[0][c] == col) {
                    for (int e = 1; e < entries; e++) {
                        if (!data[e][c].empty()) {
                            if (stod(data[e][c]) < min) {
                                min = stod(data[e][c]);
                                minC = c;
                                minE = e;
                            }
                        }
                    }
                }
            }

            if (minE != 0) {
                out = data[minE][minC];
            }
            cout << "The min for col \"" << col << "\" = " << out << endl << endl;
            continue;
        }

        //max
        if (command == "max") {
            string col;
            double max = 2.22507e-308;
            int maxC = 0;
            int maxE = 0;
            string out = "N/A";
            commandStream >> quoted(col);
            for (int c = 0; c < columns; c++) {
                if (data[0][c] == col) {
                    for (int e = 1; e < entries; e++) {
                        if (!data[e][c].empty()) {
                            if (stod(data[e][c]) > max) {
                                max = stod(data[e][c]);
                                maxC = c;
                                maxE = e;
                            }
                        }
                    }
                }
            }

            if (maxE != 0) {
                out = data[maxE][maxC];
            }

            cout << "The max for col \"" << col << "\" = " << out << endl << endl;
            continue;
        }

        //avg
        if (command == "avg") {
            string col;
            double total = 0;
            double count = 0;
            string out = "N/A";
            bool colFound = false;
            commandStream >> quoted(col);
            for (int c = 0; c < columns; c++) {
                if (data[0][c] == col) {
                    colFound = true;
                    for (int e = 1; e < entries; e++) {
                        if (!data[e][c].empty()) {
                            total += stod(data[e][c]);
                            count++;
                        }
                    }
                }
            }

            if (colFound) {
                if (!isnan(total / count)) {
                    cout << "The avg for col \"" << col << "\" = " << total / count << endl << endl;
                    continue;
                } else {
                    cout << "The avg for col \"" << col << "\" = N/A" << endl << endl;
                    continue;
                }
            } else {
                cout << "Invalid column \"" << col << "\"" << endl << endl;
                continue;
            }
        }

        cout << "Invalid command" << endl << endl;
    }
}