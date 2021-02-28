//
// Created by mithu on 2/17/2021.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
#include <algorithm>

using namespace std;
void quickSort(int* array, int left, int right, int length);
void quickSort(int* array, int left, int right, int length) {

    if (left == right) {
        for (int i = 0; i < length; i++)
            cout << array[i] << " ";

        cout << endl;
        return;
    }
    int i = left, j = right, tmp;

    int pivot = array[(left+right)/2];


    while (i <= j) {
        while (array[i] < pivot) {
            i++;
        }

        while (array[j] > pivot) {
            j--;
        }

        tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
        i++;
        j--;

        /*if (array[i] <= array[j]) {
            tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
            i++;
            j++;
        }*/
    }

    if (left < j) {

    }
    quickSort(array, left, (left+right)/2, length);

    quickSort(array, pivot, right, length);
    if (i < right) {

    }

}


void printArray(int array[], int size) {
    int i;
    for (i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

void printArray(string array[], int size) {
    int i;
    for (i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

int main(int argc, char* argv[]) {
    string type = argv[1];

    string path1 = argv[2];
    string path2 = argv[3];

    int file1Lines = 0;
    int file2Lines = 0;

    std::ifstream ifstream1(path1);
    std::ifstream ifstream2(path2);

    if (type == "s") {
        string word;
        while (ifstream1 >> word) {
            if (!word.empty()) {
                file1Lines++;
            }
        }

        string word2;
        while (ifstream2 >> word) {
            if (!word.empty()) {
                file2Lines++;
            }
        }

        string file1[file1Lines];
        string file2[file2Lines];

        ifstream1.clear();
        ifstream1.seekg(0,std::ios::beg);

        ifstream2.clear();
        ifstream2.seekg(0,std::ios::beg);

        for(int i = 0; i < file1Lines - 1; i++) {
            ifstream1 >> word;
            if (!word.empty()) {
                file1[i] = word;
            }
        }

        for(int i = 0; i < file2Lines - 1; i++) {
            ifstream2 >> word;
            if (!word.empty()) {
                file2[i] = word;
            }
        }

        cout << "Before sort" << endl;
        printArray(file1, file1Lines);

        int n = file1Lines / 2;

        //sort(file1, file1Lines);
        printArray(file1, file1Lines);

    } else if (type == "i") {
        int num;
        while (ifstream1 >> num) {
            file1Lines++;
        }

        int num2;
        while (ifstream2 >> num2) {
            file2Lines++;
        }

        int file1[file1Lines];
        int file2[file2Lines];

        ifstream1.clear();
        ifstream1.seekg(0,std::ios::beg);

        ifstream2.clear();
        ifstream2.seekg(0,std::ios::beg);

        for(int i = 0; i < file1Lines - 1; i++) {
            ifstream1 >> num;
            file1[i] = num;
        }

        for(int i = 0; i < file2Lines - 1; i++) {
            ifstream2 >> num2;
            file2[i] = num2;
        }

        cout << "Before sort i" << endl;
        printArray(file1, file1Lines);

        quickSort(file1, 1, file1Lines, file1Lines);
        printArray(file1, file1Lines);

    }

}
