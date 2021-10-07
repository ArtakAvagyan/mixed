#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<map>
#include<utility>
class FakeDB
{
	std::vector<std::string>vec;
	std::vector<std::vector<std::string>>db;
	std::map<std::string,std::vector<std::string>>meta;
	std::string str ;
	public:
	void entity(const std::vector<std::string>& in_vec)
	{
		std::vector<std::string>tmpe;
		for(int i =2;i < in_vec.size();++i)
		{
			tmpe.push_back(in_vec[i]);
		}
		meta.insert(std::make_pair(in_vec[1],tmpe));
	}
	void add (const std::vector<std::string>& in_vec)
	{
		auto it = meta.find(in_vec[1]);
		if(it!= meta.end())
		{
			vec.push_back(in_vec[1]);
			for(int i=0;i < it->second.size();++i)
			{
				std::cout << " Enter the " << it->second[i] << std::endl ;
				std::cin >> str ;
				vec.push_back(str);
			}
			db.push_back(vec);
		}
		else
		{
			std::cout << "you dont heva a dis struct" << std::endl ;
		}
	}
	void Print (const std::vector<std::string>& in_vec)
	{
		for(int i=0;i<db.size();++i)
		{
			if(in_vec[1]==db[i][0] && in_vec[2]==db[i][1])
			{
				for(int j=0;j<db[i].size();++j)
				{
					std::cout<< db[i][j] << "  ";
				}
				std::cout<<std::endl ;
				break;	
			}
		}
	}
	void Edit (const std::vector<std::string>& in_vec)
	{
		auto it = meta.find(in_vec[1]);
		for(int i=0;i<db.size();++i)
		{
			if(in_vec[1]==db[i][0] && in_vec[2]==db[i][1])
			{
				for(int j=0;j<db[i].size()-1;++j)
				{
					std::cout << " Enter the " << it->second[j] << std::endl ;
					std::cin >> str ;
					db[i][j] = str ;
				}
				std::cout<<std::endl;
				break ;	
			}
		}
	}
	void Dellete(const std::vector<std::string>& in_vec)
	{
		for(int i=0;i<db.size();++i)
		{
			if(in_vec[1]==db[i][0] && in_vec[2]==db[i][1])
			{
				db.erase(db.begin()+i);
				break;
			}
		}
	}
	~FakeDB()
	{
		std::ofstream f_meta ;
		std::ofstream f_info ;
		f_meta.open("meta_info.txt");
		f_info.open("info.txt");
		if(f_meta.is_open() && f_info.is_open())
		{
			for(int i=0;i<db.size();++i)
			{
				for(int j=0;j<db[i].size();++i)
				{
					f_info << db[i][j] << "  " ;
				}
				f_info << ";\n";
			}
			for(auto i: meta)
			{
				f_meta << i.first << "/  " ;
				for(int j=0;j<i.second.size();++j)
				{
					f_meta << i.second[j] << "  ";
				}
				std::cout << std::endl; 
			}
		}
	}

};
int main()
{
	FakeDB db;
	while(1)
	{
		std::vector<std::string>vec;
		std::string tmp;
		std::string str;
		std::getline(std::cin,str,';');
		for(int i=0;i<str.size();++i)
		 {
			if(str[i]!= '\n' && str[i]!= ' ' ){tmp += str[i];}	
			if(str[i]==' ' or str[i]==';')
			{
				if(tmp != ";"){vec.push_back(tmp);}
				tmp.clear();
			}
		}
		if(vec[0]=="entity")
		{
			db.entity(vec);
		}
		else if(vec[0]=="add")
		{
			db.add(vec);
		}
		else if(vec[0]=="print")
		{
		db.Print(vec);
		}
		else if(vec[0]=="edit")
		{
		db.Edit(vec);
		}
		else if(vec[0]=="delete")
		{
		db.Dellete(vec);
		}
		else if(vec[0]=="exit")
		{
			break;
		}
	}
return 0;
}
