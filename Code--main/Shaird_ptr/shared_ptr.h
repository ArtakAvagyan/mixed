#ifndef SHARED_PRT
#define SHARED_PRT

#include <iostream>

template<typename T>
void Deletor(T*m_ptr)
{
        delete m_ptr;
}
template<typename T>
struct DataPointer
{
        int count = 0;
        void(*Del_ptr)(T*);
};
template<typename T>
class Shared_ptr
{
private:
        T* m_ptr;
        DataPointer<T>* buf;
public:
        Shared_ptr();
        Shared_ptr(T*);
        Shared_ptr(const Shared_ptr&);
        Shared_ptr(Shared_ptr &&);
        ~Shared_ptr();
        T& operator[](int);
        T& operator*();
        Shared_ptr<T> operator=(const Shared_ptr<T>&);
};
#include"shared_ptr.hpp"
#endif   //SHARED_PTR
