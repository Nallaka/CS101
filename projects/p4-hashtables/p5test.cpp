#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <list>

using namespace std;

class Person {
public:
    string firstName;
    string lastName;
    string Id;
    string email;
    string city;
    string state;
    string zipCode;
    string phonenumber;
    Person *nextPerson;
    Person() {
        nextPerson=nullptr;
    }
};

class Key {
public:
    Person *headPerson;
    Key *nextKey;
    int numPeople;
    string val;
    Key () {
        headPerson = new Person;
        nextKey = nullptr;
        numPeople=1;
    }
};

class hashbucket {
public:
    Key *headKey;
    hashbucket *nextBucket;
    hashbucket() {
        headKey = new Key;
        nextBucket = nullptr;
        // headKey = new Key;
    }
};

class HashTable {
public:
    int buckets;           // number of bucks to store elements
    //list <int> *table;

    hashbucket *table;
    HashTable () {
        //table=new hashbucket[buckets];
        buckets =8;
        table= new hashbucket[buckets];
    }
    HashTable(int b, hashbucket* h) {
        buckets = b;            //FIX ME?
        table = h;
    }


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

    hashbucket* h = new hashbucket[tableSize];

    cout << "before here" << endl;
    HashTable *ourtable = new HashTable(tableSize, h);
    cout << "here";
    int id;
    int firstName;
    int lastName;
    int phoneNumber;
    int city;
    int state;
    int zipcode;
    int email;

    int indexKey; // key that is used to group, provided by command line, is same as key
    int count=0;


    // This is an example of how to retreive the tokens from the input file
    // You will need to modify this to fit your needs to build the hash table
    string line, token;

    getline(file, line);

    istringstream iss(line);
    //while (getline(file, line,)) {
    //istringstream iss(line);
    while (getline(iss, token, '\t')) {
        cout << token << "\t";

        if (token =="Id") {
            id= count;
            if (key == token) {
                indexKey= count;
            }
        }

        else if( token == "FirstName") {
            firstName = count;
            if (key ==token) {
                indexKey= count;
            }
        }

        else if (token =="LastName") {
            lastName = count;
            if (key ==token) {
                indexKey= count;
            }
        }

        else if(token == "Email") {
            email=count;
            if (key ==token) {
                indexKey= count;
            }
        }

        else if (token =="Phone") {
            phoneNumber = count;
            if (key ==token) {
                indexKey= count;
            }
        }

        else if (token =="State") {
            state=count;
            if (key ==token) {
                indexKey= count;
            }
        }
        else if (token =="PostalCode") {
            zipcode=count;
            if (key ==token) {
                indexKey= count;
            }
        }
        else if (token =="City") {
            city = count;
            if (key ==token) {
                indexKey= count;
            }
        }
        count++;
    }
    //cout << endl;


    // read entire file;

    //count=0;
    string index;
    //count=0;
    while(getline(file, line)) {
        Person *newperson = new Person;
        count=0;

        istringstream iss(line);
        while (getline(iss, token,'\t')) {

            if (count == id) {
                newperson->Id = token;

            }
            else if( count == firstName) {
                newperson->firstName = token;       //create new person 
            }

            else if (count == lastName) {
                newperson->lastName = token;
            }

            else if(count == email) {
                newperson->email=token;
            }

            else if (count == phoneNumber) {
                newperson-> phonenumber = token;
            }

            else if (count == state) {
                newperson->state=token;
            }
            else if (count == zipcode) {
                newperson->zipCode=token;
            }
            else if (count == city) {
                newperson->city = token;
            }

            if (count== indexKey) {     // marks key as the one from command line
                index = token;
            }
            count++;
        }



        unsigned long hash=djb2(index);
        int bucketIndex= hash % tableSize;

        if (ourtable->table[bucketIndex].headKey == nullptr) {      // if table is empty
            Key *newKey = new Key;
            newKey->headPerson = newperson;
            newKey->nextKey= nullptr;
            newKey->val= index;
            newKey->numPeople= 1;
            ourtable->table[bucketIndex].headKey = newKey;

        }

        else {
            Key *curr= ourtable->table[bucketIndex].headKey;
            int noKey=0;

            while (curr != nullptr) {

                if (curr->val == index) {
                    Person *currPerson = curr->headPerson;

                    while(currPerson->nextPerson != nullptr) {          // loop through to get to end of people list
                        currPerson = currPerson->nextPerson;
                    }

                    currPerson->nextPerson = newperson;
                    //newperson->nextPerson = nullptr;
                    curr->numPeople++;
                    noKey=1;

                }

                curr= curr->nextKey;
            }

            if (noKey==0) {
                Key *newKey = new Key;
                newKey->headPerson= newperson;
                newKey->nextKey= nullptr;
                newKey->val= index;
                newKey->numPeople= 1;

                while(curr->nextKey != nullptr) {          // loop through to get to end of people list
                    curr = curr->nextKey;
                }

                curr->nextKey= newKey;


            }
        }
    }


    cout << "Commands:" << endl << "\tprint" << endl << "\tlookup <key>" << endl << "\tquit" << endl;
    string cmd, val;
    while (1) {
        cout << endl << "Enter a command:" << endl;
        cin >> cmd;
        if (cmd == "quit") {
            break;
        }
        else if (cmd == "print") {
            int i=0;
            while (i< tableSize) {
                //for(int i=0; i<tableSize; i++) {
                if (ourtable->table[i].headKey != nullptr) {
                    cout << i << ": ";

                    Key *ptr = ourtable->table[i].headKey;
                    while( ptr !=nullptr) {
                        cout <<ptr->val << " (" << ptr->numPeople << ")" <<endl;
                    }
                }
                i++;
            }
            // Key *curr= ourtable->table[bucketIndex].headKey;
            //     while(curr !=nullptr) {
            //         cout << curr->headKey->value << " " << numPeople <<
            //     }
            // print code here
        }
        else if (cmd == "lookup") {
            getVal(cin, val);

            int lookup = djb2(val) % tableSize;

            if (ourtable->table[lookup].headKey == nullptr) {  // if lookup key does not exist
                cout << "No results" << endl;

            }
            else {
                Key *currKey= ourtable->table[lookup].headKey;
                Person *currPerson;
                int noKey=0;
                while (currKey != nullptr) {
                    currPerson = currKey->headPerson;
                    if (currKey->val == val) {
                        noKey=1;
                        cout << "Id,FirstName,LastName,Email,Phone,City,State,PostalCode" <<endl;
                        int i=0;
                        while(i< currKey->numPeople) {
                            cout << currPerson->Id <<"," << currPerson->firstName <<"," << currPerson->lastName << "," <<currPerson->email<< "," << currPerson->phonenumber << "," << currPerson->city<<"," << currPerson->state << "," << currPerson->zipCode << endl;
                            currPerson = currPerson->nextPerson;
                            i++;
                        }
                        currKey= currKey->nextKey;
                    }
                    else {
                        currKey=currKey->nextKey;       // iterate throguh first while loop, if no match at that key
                    }
                    if (noKey==0) {
                        cout <<"No results" << endl;
                    }
                }

                // lookup code here
            }
        }
        else {
            getline(cin, val);
            cout << "Invalid command" << endl;
        }
    }

    return 0;
}