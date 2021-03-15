#ifndef __DLL_H__
#define __DLL_H__

#include "exceptions.h"

class DllNode {
public:
    int value;
    DllNode *prev;
    DllNode *next;
};

class Dll {
private:
    DllNode *head;
    int _size;
public:
    Dll(); // create an empty list
    Dll(const Dll &src); // create a deep copy of the src list
    Dll(const int arr[], int size); // create a linked list containing the elements of the array
    Dll &operator=(const Dll &src); // create a deep copy of the src list
    ~Dll(); // free all memory

    bool empty() const; // return if the list is empty in O(1)
    int size() const; // return how many items are in the list in O(1)

    int &at(int rank); // return a reference to the value of the list at a rank/index
    DllNode * ptrAt(int rank) const;
    void insert(int rank, int value); // insert a value at the rank/index
    int remove(int rank); // remove the node at the rank/index and return its value

    void clear(); // reset the list to an empty list
    void display(ostream &os) const; // write the contents of the list to the ostream
};

Dll::Dll() {
    this->head = nullptr;
    this->_size = 0;
}

Dll::Dll(const Dll &src) {
    head = nullptr;
    auto* tail = head;
    _size = src.size();
    for (int i = 0; i < _size; i++) {
        auto* newNode = new DllNode();
        newNode->value = src.ptrAt(i)->value;
        if (head == nullptr) {
            head = newNode;
            newNode->prev = nullptr;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
}

Dll::Dll(const int *arr, int size) {
    head = nullptr;
    auto* tail = head;
    _size = size;
    for (int i = 0; i < size; i++) {
        auto* newNode = new DllNode();
        newNode->value = arr[i];
        if (head == nullptr) {
            head = newNode;
            newNode->prev = nullptr;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
}

Dll &Dll::operator=(const Dll &src) {
    this->clear();
    auto* tail = head;
    _size = src.size();
    for (int i = 0; i < _size; i++) {
        auto* newNode = new DllNode();
        newNode->value = src.ptrAt(i)->value;
        if (head == nullptr) {
            head = newNode;
            newNode->prev = nullptr;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    return *this;
}

Dll::~Dll() {
    this->clear();
    head = nullptr;
}

bool Dll::empty() const {
    return head == nullptr;
}

int Dll::size() const {
    return _size;
}

int &Dll::at(int rank) {
    auto* curr = new DllNode;
    if (rank > this->size()-1 || rank < 0) {
        throw IndexOutOfRangeException("at(): Indec was outside the bounds of the linked list.", rank);
    }
    for (int i = 0; i <= rank; i++) {
        if (i == 0) {
            curr = head;
        } else {
            curr = curr->next;
        }
    }
    return curr->value;
}

DllNode * Dll::ptrAt(int rank) const {
    auto* curr = new DllNode;
    for (int i = 0; i <= rank; i++) {
        if (i == 0) {
            curr = head;
        } else {
            curr = curr->next;
        }
    }
    return curr;
}

void Dll::insert(int rank, int value) {
   if (rank > this->size() || rank < 0) {
       throw IndexOutOfRangeException("insert(): Index was outside the bounds of the linked list.", rank);
   }


    auto* newNode = new DllNode();
    newNode->value = value;

    /*if (rank == 0 && this->size() == 0) {
        this->head = newNode;
        newNode->prev = nullptr;
        newNode->next = nullptr;
        _size++;
        return;
    }*/

    if (head == nullptr) {
        this->head = newNode;
        newNode->prev = nullptr;
        newNode->next = nullptr;
    } else if (rank == size()) {
        auto* prevNode = this->ptrAt(rank-1);
        prevNode->next = newNode;
        newNode->prev = prevNode;
        newNode->next = nullptr;
    } else if(this->ptrAt(rank)->prev == nullptr) {
        this->ptrAt(rank)->prev = newNode;
        newNode->next = this->ptrAt(rank);
        newNode->prev = nullptr;
        this->head = newNode;
    }  else if (rank < size()) {
        auto* currNode = this->ptrAt(rank);
        auto* prevNode = this->ptrAt(rank-1);
        prevNode->next = newNode;
        newNode->prev = prevNode;
        newNode->next = currNode;
        currNode->prev = newNode;
    }

    _size++;
}

/*When inserting into a dll, rank 0 inserts at the front of the list and rank size()
 * inserts at the back of the list. If you have the list 0 -> 10 -> 30, then after insert(2, 20)
 * , the list should be 0 -> 10 -> 20 -> 30.

When removing from a dll, rank 0 removes from the front of the list and rank size() - 1 removes from the back of the list. If you have the list 0 -> 10 -> 20 -> 30, then after remove(2), the list should be 0 -> 10 -> 30.

When building a dll from an array, the array [ 0 1 2 ] should create the list 0 -> 1 -> 2.
*/
int Dll::remove(int rank) {
    if (rank > this->size()-1 || rank < 0) {
        throw IndexOutOfRangeException("remove(): Index was outside the bounds of the linked list", rank);
    }

    auto* currNode = ptrAt(rank);
    int val = currNode->value;

    if (rank == 0 && this->size() == 1) {
        head = nullptr;
        delete currNode;
        _size--;
        return val;
    }

    if (head == currNode) {
        head = currNode->next;
        currNode->next->prev = nullptr;
    } else if (currNode->next == nullptr) {
        currNode->prev->next = nullptr;
    } else {
        currNode->prev->next = currNode->next;
        currNode->next->prev = currNode->prev;
    }
    int value = currNode->value;
    _size--;
    delete currNode;
    return value;
}

void Dll::clear() {
    while (head != nullptr) {
        this->remove(0);
    }
    head = nullptr;
}

void Dll::display(ostream &os) const {
    os << "[ ";
    if (!this->empty()) {
        for (int i = 0; i < _size; i++) {
            os << this->ptrAt(i)->value << " ";
        }
    }
    os << "]";
}

//ostream &operator<<(ostream &os, const Dll &list); // write the contents of the list to the ostream
ostream &operator<<(ostream &os, const Dll &list) {
    list.display(cout);
    return os;
}

#endif
