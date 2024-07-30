#include <algorithm>
#include <iostream>
#include <vector>

// Output iterators and stream iterators


template <typename Container>
class back_insert_iterator
{
    Container& container;

public:
    back_insert_iterator(Container& container) : container(container) {}

    back_insert_iterator& operator=(const typename Container::value_type& value)
    {
        std::cout << "push_back" << std::endl;
        container.push_back(value);
        return *this;
    }
    
    back_insert_iterator& operator=(const typename Container::value_type&& value)
    {
        std::cout << "push_back" << std::endl;
        container.push_back(std::move(value));
        return *this;
    }



    back_insert_iterator& operator++()
    {
        std::cout << "operator++" << std::endl;
        return *this;
    }

    back_insert_iterator& operator++(int)
    {
        std::cout << "++operator" << std::endl;
        return *this;
    }

    back_insert_iterator& operator*()
    {
        std::cout << "operator*" << std::endl;
        return *this;
    }
};

// *b_i_it++ = *it++ ==> b_i_it.container.push_back(*it++);
template <typename Container>
back_insert_iterator<Container> back_inserter(Container& container)
{
    return {container};
}

bool even(int x)
{
    return x % 2 == 0;
}

int main()
{
    int a[10] = {1, 2, 3, 4, 5};
    std::vector<int> v;

    //std::copy_if(a, a + 10, std::back_insert_iterator<std::vector<int>>(v), &even);
    std::copy_if(a, a + 10, ::back_inserter(v), &even);
}