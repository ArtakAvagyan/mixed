#include<iostream>
#include<string>
#include<fstream>
#include<vector>
std::vector <std::vector<std::string> > vec_2;
std::vector <std::string> vec;
std::fstream fs;
std::ofstream fout;
std::string tmp;
void foo()                           // function for oll
{	
	while(1){	
		std::cout << "for Writ (w) :" <<std::endl;
		std::cout << "for Riad (r) :" <<std::endl;
		std::cout << "for edit (e) :" <<std::endl;
		std::cout << "for Save (s) :" <<std::endl;
		char ch ;
		std::cin >> ch ;
		if(ch == 'w') 							// Write new Number
		{
			std::cout << "enter a name" << std::endl;
			std::cin >> tmp ;
			vec.push_back(tmp);
			std::cout << "enter a Sirname" << std::endl;
			std::cin >> tmp ;
			vec.push_back(tmp);
			std::cout << "enter a Addres" << std::endl;
			std::cin >> tmp ;
			vec.push_back(tmp);
			std::cout << "enter a number" << std::endl;
			std::cin >> tmp ;
			vec.push_back(tmp);
			vec.push_back(";");
			vec_2.push_back(vec);
			vec.clear();
		}
		else if(ch == 'r')			// Read oll Number
		{
			for(int i=0;i<vec_2.size();++i)
			{
				for(int j=0;j<vec_2[i].size();++j)
				{
					std::cout << vec_2[i][j] << "\t";
				}
				std::cout << std::endl ;
			}
		}
		else if(ch =='e')                      // Edit
		{
			std::cout << "Enter the name for edit" << std::endl;
			std::cin >> tmp ;
			std::cout << "whot do yow whont you cheng ??" << std::endl;
			int f = 0 ;
			for(int i = 0; i < vec_2.size();++i)
			{
				if(tmp == vec_2[i][0])
				{
					f = i;
					break;
				}
			}
			std::cout << "Suername(S) Addres (A) Number(N)" << std::endl;
			std::cin >> ch ;
			if(ch == 'S'){std::cin>>vec_2[f][1];}
			else if(ch == 'A'){std::cin>>vec_2[f][2];}
			else if(ch == 'N'){std::cin>>vec_2[f][3];}
			std::cout << "your excheng is Saving ... Plize save " << std::endl ;
		}
		else if(ch =='s')                    // Save and push oll Data
		{
			for(int i=0;i < vec_2.size();++i)
			{
				for(int j=0; j < vec_2[i].size();++j)
				{
					fout << vec_2[i][j] << " ";
				}
				fout << "\n";
			}
			break;
		}
	}	
}

int main()
{
	std::string text = "text.txt";
			fs.open(text,std::fstream::in | std::fstream::out );  // open File for Read
			if(fs.is_open())
			{
				while(!fs.eof())
				{
					while(tmp != ";")
					{
						fs >> tmp ;
						vec.push_back(tmp);
					}
					vec_2.push_back(vec);
					vec.clear();
					if(tmp == ";")
					{
						fs >> tmp;
						vec.push_back(tmp);
					}
					tmp = " ";
				}
				fs.close();
				fout.open(text);         // open File for Write
				if(fout.is_open())
				{
					foo();
				}
			}
			else
			{
				std::cout << "My Text_Redactor can not open your file :" <<std::endl;
			}
			fs.close();
}
