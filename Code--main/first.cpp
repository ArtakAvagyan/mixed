#include<iostream>
int rec(int num)
{
	if(num==0){return num;}
	else if (num==1){return num;}
	else {return rec(num-1)+rec(num-2);}
}

int main()
{
	int num;
	std::cin >> num ;
	std::cout << rec(num);
	return 0;
}
