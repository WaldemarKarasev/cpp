#include <iostream>


template <typename Alloc>
struct scoped_allocator_adaptor
{
    Alloc alloc;

    template <typename T, typename... Args>
    void construct(T* ptr, const Args&... args)
    {
        if constexpr (std::uses_allocator_v<T, Alloc>)
        {
            using InnerAlloc = typename T::allocator_type;
            alloc.construct(ptr, args..., InnerAlloc(alloc));
        } else 
        {
            alloc.construct(ptr, args...);
        }
    }

};

int main()
{

}