#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#include<sstream>
void SortsByFils()
{
	
	std::ifstream fin("NoSort.txt",std::ios::in);
	if(fin.is_open())
	{
		for(char i = 'a';i !='f'; ++i)
		{	
			std::string tmp;
			tmp += i ;
			tmp += ".txt";
			std::ofstream fout(tmp,std::ios::out);
				if(fout.is_open())
				{
					std::vector<int>vec;
					for(int i = 0;i<20000;++i)
					{
						int val;
						std::string str;
						fin >> str;
						std::istringstream(str) >> val;
						vec.push_back(val);
					}
					std::sort(vec.begin(),vec.end());
					for(int i = 0;i<20000;++i)
					{
						fout << vec[i] << " ";
					}
					fout.close();
				}
				else
				{
					std::cout<<"mi tpi"<<std::endl;
				}
				
		}
	}
	else
	{
		std::cout<<"Can't open this file !!!!" << std::endl;
	}
	fin.close();
}
int main()
{
	SortsByFils();
	std::ofstream fin("Sort.txt",std::ios::out);
	if(fin.is_open())
	{
		std::ifstream a_out("a.txt",std::ios::in);
		std::ifstream b_out("b.txt",std::ios::in);
		std::ifstream c_out("c.txt",std::ios::in);
		std::ifstream d_out("d.txt",std::ios::in);
		std::ifstream e_out("e.txt",std::ios::in);
		if(a_out.is_open() && b_out.is_open() && c_out.is_open() && d_out.is_open() && e_out.is_open())
		{
			int val[5];
			std::string tmp;
			a_out >> tmp;
			std::istringstream(tmp) >> val[0];
			tmp =" ";
			b_out >> tmp;
			std::istringstream(tmp) >> val[1];
			tmp =" ";
			c_out >> tmp;
			std::istringstream(tmp) >> val[2];
			tmp =" ";
			d_out >> tmp;
			std::istringstream(tmp) >> val[3];
			tmp =" ";
			e_out >> tmp;
			std::istringstream(tmp) >> val[4];
			tmp =" ";
			while(!a_out.eof() || !b_out.eof() || !c_out.eof() || !d_out.eof() || !e_out.eof())
			{
				if(val[0] < val[1] && val[0] < val[2] && val[0] < val[3] && val[0] < val[4])
				{
					fin<< val[0] << " ";
					a_out >> tmp;
					std::istringstream(tmp) >> val[0];
					tmp =" ";
				}
				else if(val[1] < val[0] && val[1] < val[2] && val[1] < val[3] && val[1] < val[4])
				{
					fin<< val[1] << " ";
					b_out >> tmp;
					std::istringstream(tmp) >> val[1];
					tmp =" ";
				}
				else if(val[2]<val[0] && val[2]<val[1] && val[2]<val[3] && val[2]<val[4])
				{
					fin<< val[2] << " ";
					c_out >> tmp;
					std::istringstream(tmp) >> val[2];
					tmp =" ";
				}
				else if(val[3]<val[0] && val[3]<val[1] && val[3]<val[2] && val[1]<val[4])
				{
					fin<< val[3] << " ";
					d_out >> tmp;
					std::istringstream(tmp) >> val[3];
					tmp =" ";
				}
				else if(val[4]<val[0] && val[4]<val[1] && val[4]<val[2] && val[4]<val[3])
				{
					fin<< val[4] << " ";
					e_out >> tmp;
					std::istringstream(tmp) >> val[4];
					tmp =" ";
				}
			}
		}
	}
}
