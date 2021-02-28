//
// Created by mithu on 2/28/2021.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
#include <algorithm>

using namespace std;

void mergeCall(int array[], int left, int middle, int right) {
    int num1 = middle - left + 1;
    int num2 = right - middle;

    int L[num1], R[num2];

    for (int i = 0; i < num2; i++) {
        R[i] = array[middle + 1 + i];
    }
    for (int j = 0; j < num1; j++) {
        L[j] = array[left + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < num1 && j < num2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < num1) {
        array[k] = L[i];
        i++;
        k++;
    }

    while (j < num2) {
        array[k] = R[j];
        j++;
        k++;
    }

}

void mergeSort(int array[], int left, int right) {
    if (left >= right) {
        return;
    }
    int m = left + (right - left) / 2;
    mergeSort(array, left, m);
    mergeSort(array, m + 1, right);
    mergeCall(array, left, m, right);
}

int binarySearch(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        return binarySearch(arr, mid + 1, r, x);
    }

    return -1;
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
}

void mergeCall(string array[], int left, int middle, int right) {
    int num1 = middle - left + 1;
    int num2 = right - middle;

    string L[num1], R[num2];

    for (int i = 0; i < num2; i++) {
        R[i] = array[middle + 1 + i];
    }
    for (int j = 0; j < num1; j++) {
        L[j] = array[left + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < num1 && j < num2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < num1) {
        array[k] = L[i];
        i++;
        k++;
    }

    while (j < num2) {
        array[k] = R[j];
        j++;
        k++;
    }

}

void mergeSort(string array[], int left, int right) {
    if (left >= right) {
        return;
    }
    int m = left + (right - left) / 2;
    mergeSort(array, left, m);
    mergeSort(array, m + 1, right);
    mergeCall(array, left, m, right);
}

int binarySearch(string arr[], int l, int r, string x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        return binarySearch(arr, mid + 1, r, x);
    }

    return -1;
}

void printArray(string array[], int size) {
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
}
//Test Main
int main() {
    int arr2[] = {12, 11, 13, 5, 6, 7};
    int arr[] = {12, 10, 13, 5, 6, 9, 25, 16};

    int arr_size = sizeof(arr) / sizeof(arr[0]);
    int arr2_size = sizeof(arr2) / sizeof(arr2[0]);


    cout << "Given array is \n";
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    cout << "\nSorted array is \n";
    printArray(arr, arr_size);

    cout << endl << "Given array is \n";
    printArray(arr2, arr2_size);

    mergeSort(arr2, 0, arr2_size - 1);

    cout << "\nSorted array is \n";
    printArray(arr2, arr2_size);

    cout << endl << "Numbers in Both: " << endl;

    if (arr_size < arr2_size) {
        for (int i: arr) {
            if (binarySearch(arr2, 0, arr2_size, i) != -1) {
                cout << arr[binarySearch(arr2, 0, arr2_size, i)] << endl;
            }
        }
    } else if (arr2_size < arr_size) {
        for (int i: arr2) {
            if (binarySearch(arr, 0, arr_size, i) != -1) {
                cout << arr2[binarySearch(arr, 0, arr_size, i)] << endl;
            }
        }
    } else if (arr_size == arr2_size) {
        for (int i: arr) {
            if (binarySearch(arr2, 0, arr2_size, i) != -1) {
                cout << arr[binarySearch(arr2, 0, arr2_size, i)] << endl;
            }
        }
    }

    return 0;
}


/* File Reading Logic Main
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
        //printArray(file1, file1Lines);

        int n = file1Lines / 2;

        //sort(file1, file1Lines);
        //printArray(file1, file1Lines);

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

        int arr_size = sizeof(file1) / sizeof(file1[0]);

        cout << "Given array is \n";
        printArray(file1, arr_size);

        mergeSort(file1, 0, arr_size - 1);

        cout << "\nSorted array is \n";
        printArray(file1, arr_size);
        return 0;

    }

}
*/
