#include<iostream>

int foo(int* arr,const int size ,const int key)
{
	if(key > size){return -1;}
	int max[key] {};

	for(int i = 0 ; i < size ; ++i)
	{
		for(int j = 0;j<key;++j)
		{
			if(arr[i]>max[j])
			{
				for(int k = key-1;k != j ;--k)
				{
					max[k] = max[k-1];
				}
				max[j] = arr[i];
				break;
			}
		}
	}

	return max[key-1];
}


int main()
{
	const int size = 15 ;
	int arr[size]{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	std::cout<< foo(arr,size,5)<<std::endl;
	return 0;
}
