#include<iostream>
int* del_ind (int*arr,const int size,const int caunt)
	
{
	int* arrey = new int [size-1];
	int j = 0;
	for(int i =0;i<size;++i)
	{
		if(caunt != i)
		{
		arrey[j]=arr[i];
		++j;
		}
	}
	return arrey;
}


int main()
{
	const int size = 10;
	int arr[size]{0,1,2,3,4,5,6,7,8,9};
	int num;
	std::cin >> num ;
	int*arrey=del_ind(arr,size,num);
	for(int i = 0;i<size-1;++i)
	{
		std::cout<<arrey[i]<<std::endl;
	}
	return 0;
}
