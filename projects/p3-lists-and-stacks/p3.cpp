#include <iostream>

#include "exceptions.h"
#include "dll.h"
#include "stack.h"

using namespace std;

int main() {
    try {
        int array[5] = {1, 2, 3, 4, 5};

        Dll* dll = new Dll(array, 5);

        dll->insert(3, 2);
        cout << dll->at(1);
        dll->display(cout);
    }
    catch (InvalidOperationException &e) {
        cout << e.getMessage() << endl;
    }
    catch (IndexOutOfRangeException &e) {
        cout << e.getMessage() << " Index=" << e.getIndex() << endl;
    }

    return 0;
}
