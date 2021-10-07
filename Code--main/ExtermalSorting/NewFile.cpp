#include<iostream>
#include<fstream>
int main()
{
	std::ofstream fout("NoSort.txt");
	if(fout.is_open())
	{
		for(int i = 1; i < 20000;++i)
		{
			fout<< i << " ";
			fout<< i*15 << " ";
			fout<< i+35 << " ";
			fout<< i*56 << " ";
			fout<< i*3 << " ";
		}
	}
	else
	{
		std::cout<<"File is dont open !!!" <<std::endl;
	}
}
