#include <iostream>

using namespace std;

class MyDynamicArray {
private:
    int size, capacity, error, *a;
public:
    MyDynamicArray() {
        size = 0;
        capacity = 2;
        a = new int[capacity];
        /* Your code goes here */
    }

    MyDynamicArray(int s) {
        size = s;
        capacity = s;
        a = new int[capacity];
        /* Your code goes here */
    }

    int &operator[](int i) {
        /* Your code goes here */
        if (i >= size || i < 0) {
            cout << "Out of bounds reference : " << i << endl;
            return error;
        }
        return *(a + i);
    }

    void add(int v) {
        /* Your code goes here */
        size++;
        if (size > capacity) {
            capacity *= 2;
            cout << "Doubling to : " << capacity << endl;
            int *newArray = new int[capacity];
            for (int i = 0; i < size - 1; i++) {
                newArray[i] = a[i];
                //cout << a[i] << endl;
            }
            newArray[size-1] = v;
            delete[] a;
            a = newArray;

        } else {
            *(a + size - 1) = v;
        }


    }

    void del() {
        /* Your code goes here */
        size--;
        if (size <= capacity / 4) {
            capacity /= 2;
            cout << "Reducing to : " << capacity << endl;
            int *newArray = new int[capacity];
            for (int i = 0; i < size - 1; i++) {
                newArray[i] = a[i];
                //cout << a[i] << endl;
            }

            delete[] a;
            a = newArray;
        }
    }

    int length() { return size; }

    void clear() {
        delete a;
        a = new int[capacity = 2];
        size = 0;
    }
};

