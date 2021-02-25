//
// Created by mithu on 2/17/2021.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
#include <algorithm>

using namespace std;

void quickSort(int array[], int left, int right, int length) {
    int i = left, j = right, tmp;

    int pivot = array[(left+right) / 2];

    while (i <= j) {
        while (array[i < pivot]) {
            i ++;
        }

        while (array[j] > pivot) {
            j--;
        }

        if (i <= j) {
            tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
            i++;
            j++;
        }
    }

    if (left < j) {
        quickSort(array, left, j, length);
    }

    if (i < right) {
        quickSort(array, i, right, length);
    }

    for (i = 0; i < length; i++)
        cout << array[i] << " ";
    cout << endl;
}

/*
void sort(int array[], int length) {
    if (length <= 1) {
        return;
    }

    int *array1 = new int[length / 2];
    int *array2 = new int[length-(length/2)];

    for (int i = 0; i < length/2; i++) {
        array1[i] = array[i];
    }

    for (int i = length/2; i < length; i++) {
        array2[i-length/2] = array[1];
    }

    sort(array1, length/2);
    sort(array2, length-length/2);

    mergeS(array, array1, array2, length);

}

void mergeS(int &array, int &array1, int &array2, int length) {
    int length1 = length/2;
    int length2 = length-length/2;

    int pos1 = 0;
    int pos2 = 0;
    int i = 0;

    while (pos1 < length1 && pos2 < length2) {
        array[i++] = array1[pos1] < array2[pos2] ? array1[pos1++] : array2[pos2++];
    }

    while (pos1 < length1) {
        array[i++] = array1[pos1++];
    }

    while (pos2 < length2) {
        array[i++] = array2[pos2++];
    }
}
*/


/*void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void swap(string* a, string* b) {
    string t = *a;
    *a = *b;
    *b = t;
}

int partition (int array[], int low, int high) {
    int i = low - 1;
    int pivot = array[high];

    for (int i2 = low; i2 < high; i2++) {
        if (array[i2] < pivot) {
            i2++;
            swap(&array[i], &array[i2]);
        }
    }

    swap(&array[i+1], &array[high]);

    return i + 1;
}

int partition (string array[], int low, int high) {
    int i = low - 1;
    string pivot = array[high];

    for (int i2 = low; i2 < high; i2++) {
        if (array[i2] < pivot) {
            i2++;
            swap(&array[i], &array[i2]);
        }
    }

    swap(&array[i+1], &array[high]);

    return i + 1;
}

void quickSort(int array[], int low, int high) {
    if (low < high) {
        int partitionIndex = partition(array, low, high);

        quickSort(array, low, partitionIndex - 1);
        quickSort(array, partitionIndex + 1, high);
    }
}

void quickSort(string array[], int low, int high) {
    if (low < high) {
        int partitionIndex = partition(array, low, high);

        quickSort(array, low, partitionIndex - 1);
        quickSort(array, partitionIndex + 1, high);
    }
}*/

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

        cout << "Before sort" << endl;
        printArray(file1, file1Lines);

        quickSort(file1, 3, file1Lines, file1Lines);
        printArray(file1, file1Lines);

    }

}
