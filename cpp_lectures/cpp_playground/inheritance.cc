#include <iostream>

class A
{
private:
public:
	A(){std::cout << "A()" << std::endl;};
	A(const A& a) {std::cout << "copy A()" << std::endl;}
	A(A&& a) {std::cout << "move A()" << std::endl;}
    virtual void print() { std::cout << "A::print()" << std::endl; }
	~A(){std::cout << "~A()" << std::endl;}
};

class B : public A
{
private:
public:
	B(){std::cout << "B()" << std::endl;};
	B(const B& b) {std::cout << "copy B()" << std::endl;}
	B(B&& b) {std::cout << "move B()" << std::endl;}
    virtual void print() { std::cout << "B::print()" << std::endl; }
	~B(){std::cout << "~B()" << std::endl;}
};

class C : public A
{
private:
public:
	C(){std::cout << "C()" << std::endl;};
	C(const C& c) { std::cout << "copy C()" << std::endl;}
	C(C&& c) { std::cout << "move C()" << std::endl;}
    virtual void print() { std::cout << "C::print()" << std::endl; }
	~C(){ std::cout << "~C()" << std::endl;}
};

class D : public B, public C
{
private:
public:
	D(){std::cout << "D()" << std::endl;};
	D(const D& d) {std::cout << "copy D()" << std::endl;}
	D(D&& d) {std::cout << "move D()" << std::endl;}
    void print() { std::cout << "D::print()" << std::endl; }
	~D(){std::cout << "~D()" << std::endl;}
};

void print_obj_ptr(A* a)
{
    a->print();
}

void print_obj_val(A a)
{
    a.print();
}

void print_obj_ref(A& a)
{
    a.print();
}

int main()
{
    #if 0
    A* a = new A();
    A* ab = new B();

    std::cout << "pass by ptr\n";
    print_obj_ptr(a);
    print_obj_ptr(ab);

    std::cout << "pass by val\n";
    print_obj_val(*a);
    print_obj_val(*ab);

    std::cout << "pass by ref\n";
    print_obj_ref(*a);
    print_obj_ref(*ab);
    #endif
    
    D* d = new D();
    d->B::print();

}