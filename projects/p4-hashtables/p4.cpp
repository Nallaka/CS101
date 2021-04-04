#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

class HashTable {
    public:
        vector<vector<string>>* table;
};

unsigned long djb2(string str) {
    const char *ptr = str.c_str();
    unsigned long hash = 5381;
    int c;
    while ((c = *ptr++)) {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }
    return hash;
}

void getVal(istream &is, string &str) {
    char ch;
    string line;

    is >> ch;
    getline(is, line);

    str = ch + line;
}

bool isValidKey(const string &key) {
    string validKeys[8] = { "Id", "FirstName", "LastName", "Email", "Phone", "City", "State", "PostalCode" };
    for (int i = 0; i < 8; i++) {
        if (key == validKeys[i]) {
            return true;
        }
    }
    return false;
}

int main(int argc, char **argv) {
    if (argc != 4) {
        cout << "Usage: ./a.out filename.txt table_size key" << endl;
        return 1;
    }

    string filename = argv[1];
    int tableSize = stoi(argv[2]);
    string key = argv[3];

    ifstream file(filename);
    if (!file) {
        cout << "Unable to open " << filename << endl;
        return 2;
    }

    if (!isValidKey(key)) {
        cout << "Invalid key: " << key << endl;
        return 3;
    }
   
    // This is an example of how to retreive the tokens from the input file
    // You will need to modify this to fit your needs to build the hash table
    string line, token;

    //Column Names
    vector< string > columms;
    string columnline;
    getline(file, columnline);
    istringstream iss(columnline);
    while (getline(iss, token, '\t')) {
        columms.push_back(token);
    }

    auto it = find(columms.begin(), columms.end(), "Id");
    int idIndex = it - columms.begin();
    //cout << idIndex << endl;

    it = find(columms.begin(), columms.end(), "FirstName");
    int firstNameIndex = it - columms.begin();
    //cout << firstNameIndex << endl;

    it = find(columms.begin(), columms.end(), "LastName");
    int lastNameIndex = it - columms.begin();
    //cout << lastNameIndex << endl;

    it = find(columms.begin(), columms.end(), "Email");
    int emailIndex = it - columms.begin();
    //cout << emailIndex << endl;

    it = find(columms.begin(), columms.end(), "Phone");
    int phoneIndex = it - columms.begin();
    //cout << phoneIndex << endl;

    it = find(columms.begin(), columms.end(), "City");
    int cityIndex = it - columms.begin();
    //cout << cityIndex << endl;

    it = find(columms.begin(), columms.end(), "State");
    int stateIndex = it - columms.begin();
    //cout << stateIndex << endl;

    it = find(columms.begin(), columms.end(), "PostalCode");
    int postalCodeIndex = it - columms.begin();
    //cout << postalCodeIndex << endl;

    it = find(columms.begin(), columms.end(), key);
    int keyIndex = it - columms.begin();
    //cout << keyIndex << endl;

    HashTable table =  HashTable();

    //cout << table.table->size();

    vector<vector<string>> t[tableSize*2];
    table.table = t;

    //Elements
    while (getline(file, line)) {
        istringstream iss(line);
        vector<string> personData;
        while (getline(iss, token, '\t')) {
            personData.push_back(token);
        }

        string toKey = personData.at(keyIndex);
        //cout << toKey << endl;
        unsigned long hash = djb2(toKey) % (tableSize);
        int hashInt = (int) hash;
        //cout << hashInt << endl;
        table.table[hashInt].push_back(personData);

    }

    for (auto p: table.table[38]) {
        for (auto q: p) {
            cout << q << " ";
        }
        cout << endl;
    }

    /*for (auto p: table.table[7]) {
        for (auto q: p) {
            cout << q << " ";
        }
        cout << endl;
    }*/

    cout << "Commands:" << endl << "\tprint" << endl << "\tlookup <key>" << endl << "\tquit" << endl;
    string cmd, val;
    while (1) {
        cout << endl << "Enter a command:" << endl;
        cin >> cmd;
        if (cmd == "quit") {
            break;
        }
        else if (cmd == "print") {
        }
        else if (cmd == "lookup") {
            getVal(cin, val);

        }
        else {
            getline(cin, val);
            cout << "Invalid command" << endl;
        }
    }

    return 0;
}
