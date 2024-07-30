#include <iostream>



// CRTP - curiously recursive template pattern
template <class T>
struct Base
{
	void interface()
	{
		//...
		static_cast<T*>(this)->implementaion();
		//...
	}	

	static void static_func()
	{
		T::static_sub_func():
	}
};

struct Derived : Base<Derived>
{
	void implementaion();
	static void static_sub_func();
};




int main()
{
	
}
