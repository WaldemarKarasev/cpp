#if 0
#include <iostream>
#include <exception>

using namespace std;

void myunexpected()
{
	cout << "unexpected handler caller\n";
	throw;
}

void myfunction() throw	(int, bad_exception)
{
	throw 'x';
}

int main()
{
	set_unexpected(myunexpected);
	try
	{
		myfunction();
	}
	catch(int)
	{
		cout << "int\n";
	}
	catch(bad_exception be)
	{
		cout << "be\n";
	}
	catch (...)
	{
	cout << "all\n";}
}
#endif

#include <vector>
#include <iostream>

class A
{
private:
public:
	A(){std::cout << "A()" << std::endl;};
	A(const A& a) {std::cout << "copy A()" << std::endl;}
	A(A&& a) {std::cout << "move A()" << std::endl;}
	~A(){std::cout << "~A()" << std::endl;}
};




int main()
{
	std::vector<A> vec;
	std::cout << sizeof(A) << std::endl;

	vec.reserve(2);
	vec.push_back(A());
	vec.push_back(A());
	vec.push_back(A());

}




