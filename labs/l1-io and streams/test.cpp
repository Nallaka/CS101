//
// Created by mithu on 2/17/2021.
//
#include <iostream>
#include <string>
#include <sstream>

class MyClass {
private:
    int x;
public:
    MyClass() { x = 5; }
    int getX() { return x; }
    void setX(int a) { x = a; }
};
void modify(MyClass m1, MyClass & m2) {
    int a = m1.getX() * 2;
    int b = m2.getX() * 2;
    m1.setX(a);
    m2.setX(b);
}
int main() {
    MyClass a, b;
    modify(a, b);
    std::cout << a.getX() << ',' << b.getX() << std::endl;
    return 0;
}