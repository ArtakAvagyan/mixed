#include <iostream>
#include "shared_ptr.h"
int main()
{
        Shared_ptr<int> a(new int);
	*a = 18;
        Shared_ptr<int> b;
        b = a;
	std::cout<< *a <<std::endl;
}
