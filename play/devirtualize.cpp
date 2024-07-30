#include <iostream>

// Laundry problem
// On launder Nicolai Josuntis


struct A {
    virtual int f();
};

struct B : A {
    int f() override { new (this) A; return 1; }
};

int A::f() { new (this) B; return 2; }

int h() {
    A a;
    int n = a.f();
    int m = a.f(); // std::launder
    return n + m;
}

int main()
{
    h();
}