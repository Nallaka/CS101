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
    //cout << endl;
    //printArray(array, array->size());
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
int main(int argc, char *argv[]) {

    string type = argv[1];

    string path1 = argv[2];
    string path2 = argv[3];

    //cout << type << endl << path1 << endl << path2 << endl;

    int file1Lines = 0;
    int file2Lines = 0;

    std::ifstream ifstream1(path1);
    std::ifstream ifstream2(path2);

    if (type == "i") {
        int n;

        while (!ifstream1.eof()) {
            ifstream1 >> n;
            //cout << n << endl;
            file1Lines++;
            //cout << "count: " << file1Lines << endl;
        }

        while (!ifstream2.eof()) {
            ifstream2 >> n;
            //cout << n << endl;
            file2Lines++;
            //cout << "count: " << file2Lines << endl;
        }

        int arr[file1Lines];
        int arr2[file2Lines];

        ifstream1.clear();
        ifstream1.seekg(0, std::ios::beg);

        ifstream2.clear();
        ifstream2.seekg(0, std::ios::beg);

        int i = 0;
        while (!ifstream1.eof()) {
            ifstream1 >> n;
            arr[i] = n;
            //cout << arr[i] << " ";
            i++;
        }

        int j = 0;
        while (!ifstream2.eof()) {
            ifstream2 >> n;
            arr2[j] = n;
            //cout << arr2[j] << " ";
            j++;
        }


        int arr_size = sizeof(arr) / sizeof(arr[0]);
        int arr2_size = sizeof(arr2) / sizeof(arr2[0]);


/*        cout << "Given array is \n";
        printArray(arr, arr_size);*/

        mergeSort(arr, 0, arr_size - 1);

        /*cout << "\nSorted array is \n";
        printArray(arr, arr_size);*/

        /*cout << endl << "Given array is \n";
        printArray(arr2, arr2_size);*/
        mergeSort(arr2, 0, arr2_size - 1);

        /*cout << "\nSorted array is \n";
        printArray(arr2, arr2_size);*/

        //cout << endl;

        //cout << endl << "arr size: " << arr_size <<  endl << "arr2 size: " << arr2_size << endl;

        //cout << arr2[binarySearch(arr2, 0, arr2_size, -8)];
        if (arr_size < arr2_size) {
            for (int i = 0; i < arr_size; i++) {
                int w = arr[i];
                if (i == 0 || arr[i] != arr[i-1]) {
                    if (binarySearch(arr2, 0, arr2_size, w) != -1) {
                        cout << arr2[binarySearch(arr2, 0, arr2_size, w)] << endl;
                    }
                }
            }
            /*for (int i: arr) {
                if (binarySearch(arr2, 0, arr2_size, i) != -1) {
                    cout << arr2[binarySearch(arr2, 0, arr2_size, i)] << endl;
                }
            }*/
        } else if (arr2_size < arr_size) {
            for (int i = 0; i < arr2_size; i++) {
                int w = arr2[i];
                if (i == 0 || arr2[i] != arr2[i-1]) {
                    if (binarySearch(arr, 0, arr_size, w) != -1) {
                        cout << arr[binarySearch(arr, 0, arr_size, w)] << endl;
                    }
                }
            }
            /*for (int i: arr2) {
                if (binarySearch(arr, 0, arr_size, i) != -1) {
                    cout << arr[binarySearch(arr, 0, arr_size, i)] << endl;
                }
            }*/
        } else if (arr_size == arr2_size) {
            for (int i = 0; i < arr_size; i++) {
                int w = arr[i];
                if (i == 0 || arr[i] != arr[i-1]) {
                    if (binarySearch(arr2, 0, arr2_size, w) != -1) {
                        cout << arr2[binarySearch(arr2, 0, arr2_size, w)] << endl;
                    }
                }
            }
            /*for (int i: arr) {
                if (binarySearch(arr2, 0, arr2_size, i) != -1) {
                    cout << arr[binarySearch(arr2, 0, arr2_size, i)] << endl;
                }
            }*/
        }
    } else if (type == "s") {
        string n;

        while (ifstream1 >> n) {
            if (!n.empty()) {
                //cout << n << endl;
                file1Lines++;
                //cout << "count: " << file1Lines << endl;
            }
        }

        while (ifstream2 >> n) {
            if (!n.empty()) {
                //cout << n << endl;
                file2Lines++;
                //cout << "count: " << file2Lines << endl;
            }
        }

        string arr[file1Lines];
        string arr2[file2Lines];

        ifstream1.clear();
        ifstream1.seekg(0, std::ios::beg);

        ifstream2.clear();
        ifstream2.seekg(0, std::ios::beg);

        int i = 0;
        while (ifstream1 >> n) {
            arr[i] = n;
            //cout << arr[i] << " ";
            i++;
        }

        //cout << endl;
        int j = 0;
        while (ifstream2 >> n) {
            arr2[j] = n;
            //cout << arr2[j] << " ";
            j++;
        }

        int arr_size = sizeof(arr) / sizeof(arr[0]);
        int arr2_size = sizeof(arr2) / sizeof(arr2[0]);

        /*cout << "\nGiven array is \n";
        printArray(arr, arr_size);*/

        mergeSort(arr, 0, arr_size - 1);

        /*cout << "\nSorted array is \n";
        printArray(arr, arr_size);*/

        /*cout << endl << "Given array is \n";
        printArray(arr2, arr2_size);*/

        mergeSort(arr2, 0, arr2_size - 1);

        /*cout << "\nSorted array is \n";
        printArray(arr2, arr2_size);*/

        //cout << endl;

        //cout << endl << "arr size: " << arr_size <<  endl << "arr2 size: " << arr2_size << endl;

        //cout << arr2[binarySearch(arr2, 0, arr2_size, -8)];
        //cout << endl;
        if (arr_size < arr2_size) {
            for (int x = 0; x < arr_size; x++) {
                string w = arr[x];
                if (x == 0 || arr[x] != arr[x-1]) {
                    //cout << "reaches";
                    if (binarySearch(arr2, 0, arr2_size, w) != -1) {
                        cout << arr2[binarySearch(arr2, 0, arr2_size, w)] << endl;
                    }
                }
            }
            /*for (string i: arr) {
                if (binarySearch(arr2, 0, arr2_size, i) != -1) {
                    cout << arr2[binarySearch(arr2, 0, arr2_size, i)] << endl;
                }
            }*/
        } else if (arr2_size < arr_size) {
            for (int i = 0; i < arr2_size; i++) {
                string w = arr2[i];
                if (i == 0 || arr2[i] != arr2[i-1]) {
                    if (binarySearch(arr, 0, arr_size, w) != -1) {
                        cout << arr[binarySearch(arr, 0, arr_size, w)] << endl;
                    }
                }
            }
            /*for (string i: arr2) {
                if (binarySearch(arr, 0, arr_size, i) != -1) {
                    cout << arr[binarySearch(arr, 0, arr_size, i)] << endl;
                }
            }*/
        } else if (arr_size == arr2_size) {
            for (int i = 0; i < arr_size; i++) {
                string w = arr[i];
                if (i == 0 || arr[i] != arr[i-1]) {
                    if (binarySearch(arr2, 0, arr2_size, w) != -1) {
                        cout << arr2[binarySearch(arr2, 0, arr2_size, w)] << endl;
                    }
                }
            }
        }
    }
    return 0;
}
