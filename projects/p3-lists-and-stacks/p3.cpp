#include <iostream>

#include "exceptions.h"
#include "dll.h"
#include "stack.h"

using namespace std;

int main() {
    try {
        Dll dll;
        cout << "Default Constructor" << endl;
        cout << "Empty" << boolalpha << dll.empty() << endl;
        cout << "Size" << dll.size() << endl;
        cout << dll << endl << endl;

        dll.insert(0, 10);
        dll.insert(0, 20);
        dll.insert(0, 30);

        cout << "Copy" << endl;
        Dll newDll = Dll(dll);
        cout << dll << endl;
        cout << newDll << endl;
        dll.remove(0);
        cout << dll << endl;
        cout << newDll << endl;

        int testarr[5] = {1, 2, 3, 4, 5};

        Dll newDll1 = Dll(testarr, 5);
        cout << "Array"<< endl;
        cout << newDll1 << endl;
        cout << newDll1.size() << endl;

        cout << "Assignment Operator" << endl;
        cout << "newDll1 before " << newDll1 << " Size: " << newDll1.size() << endl;
        newDll1 = newDll;
        cout << "newDll " << newDll << endl;
        cout << "newDll1 After " << newDll1 << " Size: " << newDll1.size() << endl;

    }
    catch (InvalidOperationException &e) {
        cout << e.getMessage() << endl;
    }
    catch (IndexOutOfRangeException &e) {
        cout << e.getMessage() << " Index=" << e.getIndex() << endl;
    }

    return 0;
}
