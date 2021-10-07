#ifendes Interpretator
#define Interpretator
#include<iostream>
#include<string>
#include<map>
#include<fstream>
#include<sstream>
#include<vector>
class Inter 
{
	public:
		Inter(std::string file_name)
		{
			std::fstream fin ;
			fin.open(file_name);
			if(fin.is_open())
			{
				while(!fin.eof())
				{

					std::string tmp;
					while(tmp != ";")
					{
						fin >> tmp ; 	
						vec.push_back(tmp);
					}
					fin >> tmp ;
					if( vec[0] == "number")
					{
						add_number(vec);
					}
					else if ( vec[0] == "dnumber")
					{
						add_dnumber( vec );
					}
					else if ( vec[0] == "text")
					{
						add_text( vec );
					}
					else if (  vec[0] == "print"){ print ( vec );}
					else {for_oll( vec );}	
					vec.clear() ;	
					vec.push_back(tmp);
					if(tmp == "condition")
					{
						while(tmp != "}")
						{
							if(tmp == ";"){fin >> tmp ; vec.push_back(tmp);}
							while(tmp != ";")
							{
								fin >> tmp ; 	
								vec.push_back(tmp);
								if(tmp == "}"){break;}
							}
							vec_2.push_back(vec);
							vec.clear();
						}

						for_condition();
						vec.clear() ;
						vec_2.clear() ;	
						if(tmp == "}" ){fin >> tmp;}
						if(tmp == ";" ){fin >> tmp;}
						vec.push_back(tmp);
					}
					if(tmp == "loop")
					{
						while(tmp != "$")
						{

							if(tmp == ";"){fin >> tmp ; vec.push_back(tmp);}
							while(tmp != ";")
							{

								fin >> tmp ; 	
								vec.push_back(tmp);
								if(tmp == "$"){break;}
							}
							vec_2.push_back(vec);
							vec.clear();
						}
						for_loop();
						vec.clear() ;
						vec_2.clear() ;	
						if(tmp == "$" ){fin >> tmp;}
						if(tmp == ";" ){fin >> tmp;}
						vec.push_back(tmp);

					}
				}
				fin.close();

			}else{std::cout << "Fils can't open" << std::endl;}
		}
	private:
		std::vector <std::vector <std::string> > vec_2;
		std::vector <std::string> vec;
		std::map<std::string,int>num_map ;
		std::map<std::string,double>dnum_map ;
		std::map<std::string,std::string>text_map ;
	private:
		void for_loop()
		{
			while(1)
			{
				bool tmp ;
				auto it_1 = num_map.find(vec_2[0][2]);
				auto it_2 = num_map.find(vec_2[0][4]);
				int tmp_2;
				int tmp_4;
				std::istringstream(vec_2[0][2]) >> tmp_2;
				std::istringstream(vec_2[0][4]) >> tmp_4;

				if(vec_2[0][3] == ">")
				{
					if(it_1 != num_map.end() && it_2 != num_map.end())
					{
						tmp = it_1->second > it_2->second;
					}
					else if(it_1 != num_map.end() && it_2 == num_map.end())
					{
						tmp = it_1->second > tmp_4;
					}
					else if(it_1 == num_map.end() && it_2 != num_map.end())
					{
						/*	if (tmp_2 > it_2->second){
							tmp = 1  ;
							}else
							{
							tmp = 0 ;
							}*/
						tmp = tmp_2 > it_2->second;
					}
					else if(it_1 == num_map.end() && it_2 == num_map.end())
					{
						tmp =  tmp_2 > tmp_4;
					}
					if(tmp)
					{
						for(int i = 1;i < vec_2.size();++i)
						{
							if( vec_2[i][0] == "number"){add_number( vec_2[i] );}
							else if ( vec_2[i][0] == "dnumber"){add_dnumber( vec_2[i] );}
							else if ( vec_2[i][0] == "text"){ add_text( vec_2[i] );}
							else if (  vec_2[i][0] == "print"){ print ( vec_2[i] );}
							else {for_oll( vec_2[i] );}	
						}
					}else
					{
						std::cout << __LINE__ << std::endl;
						break;
					}
				}
				else if(vec_2[0][3]== "<")
				{
					if(it_1 != num_map.end() && it_2 != num_map.end())
					{
						tmp =  it_1->second < it_2->second;
					}
					else if(it_1 != num_map.end() && it_2 == num_map.end())
					{
						tmp = it_1->second < tmp_4;
					}
					else if(it_1 == num_map.end() && it_2 != num_map.end())
					{
						tmp = tmp_2 < it_2->second;
					}
					else if(it_1 == num_map.end() && it_2 == num_map.end())
					{
						tmp =  tmp_2 < tmp_4;
					}
					if(tmp)
					{
						for(int i = 1;i < vec_2.size();++i)
						{
							if( vec_2[i][0] == "number"){add_number( vec_2[i] );}
							else if ( vec_2[i][0] == "dnumber"){add_dnumber( vec_2[i] );}
							else if ( vec_2[i][0] == "text"){ add_text( vec_2[i] );}
							else if ( vec_2[i][0] == "print"){ print ( vec_2[i] );}
							else {for_oll( vec_2[i] );}	
						}
					}else
					{
						std::cout << __LINE__ << std::endl;
						break;
					}
				}
				else if(vec_2[0][3]== "==")
				{
					if(it_1 != num_map.end() && it_2 != num_map.end())
					{
						tmp =  it_1->second == it_2->second;
					}
					else if(it_1 != num_map.end() && it_2 == num_map.end())
					{
						tmp = it_1->second == tmp_4;
					}
					else if(it_1 == num_map.end() && it_2 != num_map.end())
					{
						tmp =  tmp_2 == it_2->second;
					}
					else if(it_1 == num_map.end() && it_2 == num_map.end())
					{
						tmp = tmp_2 == tmp_4;
					}
					if(tmp)
					{
						for(int i = 1;i < vec_2.size();++i)
						{
							if( vec_2[i][0] == "number"){add_number( vec_2[i] );}
							else if ( vec_2[i][0] == "dnumber"){add_dnumber( vec_2[i] );}
							else if ( vec_2[i][0] == "text"){ add_text( vec_2[i] ); }
							else if (  vec_2[i][0] == "print"){ print ( vec_2[i] );}
							else {for_oll( vec_2[i] );}	
						}
					}else
					{

						std::cout << __LINE__ << std::endl;
						break;
					}
				}
			}
		}
		void for_condition()
		{
			bool tmp ;
			auto it_1 = num_map.find(vec_2[0][2]);
			auto it_2 = num_map.find(vec_2[0][4]);
			int tmp_2;
			int tmp_4;
			std::istringstream(vec_2[0][2]) >> tmp_2;
			std::istringstream(vec_2[0][4]) >> tmp_4;

			if(vec_2[0][3] == ">")
			{
				if(it_1 != num_map.end() && it_2 != num_map.end())
				{
					tmp = it_1->second > it_2->second;
				}
				else if(it_1 != num_map.end() && it_2 == num_map.end())
				{
					tmp = it_1->second > tmp_4;
				}
				else if(it_1 == num_map.end() && it_2 != num_map.end())
				{
					tmp =  tmp_2 > it_2->second;
				}
				else if(it_1 == num_map.end() && it_2 == num_map.end())
				{
					tmp =  tmp_2 > tmp_4;
				}
				if(tmp)
				{
					for(int i = 1;i < vec_2.size();++i)
					{
						if( vec_2[i][0] == "number"){add_number( vec_2[i] );}
						else if ( vec_2[i][0] == "dnumber"){add_dnumber( vec_2[i] );}
						else if ( vec_2[i][0] == "text"){ add_text( vec_2[i] );}
						else if (  vec[0] == "print"){ print ( vec );}
						else {for_oll( vec_2[i] );}	
					}
				}
			}
			else if(vec_2[0][3]== "<")
			{
				if(it_1 != num_map.end() && it_2 != num_map.end())
				{
					tmp =  it_1->second < it_2->second;
				}
				else if(it_1 != num_map.end() && it_2 == num_map.end())
				{
					tmp = it_1->second < tmp_4;
				}
				else if(it_1 == num_map.end() && it_2 != num_map.end())
				{
					tmp = tmp_2 < it_2->second;
				}
				else if(it_1 == num_map.end() && it_2 == num_map.end())
				{
					tmp = tmp_2 < tmp_4;
				}
				if(tmp)
				{
					for(int i = 1;i < vec_2.size();++i)
					{
						if( vec_2[i][0] == "number"){add_number( vec_2[i] );}
						else if ( vec_2[i][0] == "dnumber"){add_dnumber( vec_2[i] );}
						else if ( vec_2[i][0] == "text"){ add_text( vec_2[i] );}
						else if (  vec[0] == "print"){ print ( vec );}
						else {for_oll( vec_2[i] );}	
					}
				}
			}
			else if(vec_2[0][3]== "==")
			{
				if(it_1 != num_map.end() && it_2 != num_map.end())
				{
					tmp =  it_1->second == it_2->second;
				}
				else if(it_1 != num_map.end() && it_2 == num_map.end())
				{
					tmp =  it_1->second == tmp_4;
				}
				else if(it_1 == num_map.end() && it_2 != num_map.end())
				{
					tmp = tmp_2 == it_2->second;
				}
				else if(it_1 == num_map.end() && it_2 == num_map.end())
				{
					tmp =  tmp_2 == tmp_4;
				}
				if(tmp)
				{
					for(int i = 1;i < vec_2.size();++i)
					{
						if( vec_2[i][0] == "number"){add_number( vec_2[i] );}
						else if ( vec_2[i][0] == "dnumber"){add_dnumber( vec_2[i] );}
						else if ( vec_2[i][0] == "text"){ add_text( vec_2[i] ); }
						else if (  vec[0] == "print"){ print ( vec );}
						else {for_oll( vec_2[i] );}	
					}
				}
			}

		}
		void add_number(std::vector < std::string > vec)
		{
			if(num_map.find(vec[1]) != num_map.end()){std::cout << "number error  " << std::endl;}
			else
			{
				if(vec[2] == "=" )
				{
					int tmp_i;
					std::istringstream(vec[3]) >> tmp_i;
					num_map.emplace(vec[1],tmp_i);
				}
				else{num_map.emplace(vec[1],NULL);}
			}
		}
		void add_dnumber(std::vector < std::string > vec)
		{
			if(dnum_map.find(vec[1]) != dnum_map.end()){std::cout << "double error" << std::endl;}
			else
			{
				if(vec[2] == "=" )
				{
					double tmp_d;
					std::istringstream(vec[3]) >> tmp_d;
					dnum_map.emplace(vec[1],tmp_d);
				}
				else{dnum_map.emplace(vec[1],NULL);}
			}
		}
		void add_text(std::vector<std::string> vec)
		{
			if( text_map.find(vec[1]) != text_map.end()){std::cout << "text  error" << std::endl;}
			else
			{
				if(vec[2] == "=" )
				{
					std::string Text = vec[3];
					for (int i = 4; vec[i] != ":";++i){ Text += " "; Text += vec[i]; }
					text_map.emplace(vec[1],vec[3]);
				}
				else{text_map.emplace(vec[1],nullptr);}
			}
		}
		void for_oll(std::vector<std::string> vec)
		{
			if(num_map.find(vec[0]) != num_map.end())
			{
				auto it = num_map.find(vec[0]);
				auto it_1 = num_map.find(vec[2]);
				auto it_2 = num_map.find(vec[4]);
				int tmp_2;
				int tmp_4;
				std::istringstream(vec[2]) >> tmp_2;
				std::istringstream(vec[4]) >> tmp_4;
				if(vec[3] == "+" ){
					if(it_1 != num_map.end() && it_2 != num_map.end())
					{
						it->second =  it_1->second + it_2->second;
					}
					else if(it_1 != num_map.end() && it_2 == num_map.end())
					{
						it->second =  it_1->second + tmp_4;
					}
					else if(it_1 == num_map.end() && it_2 != num_map.end())
					{
						it->second =  tmp_2 + it_2->second;
					}
					else if(it_1 == num_map.end() && it_2 == num_map.end())
					{
						it->second =  tmp_2 + tmp_4;
					}
				}
				else if(vec[3] == "-" ){
					if(it_1 != num_map.end() && it_2 != num_map.end()){ it->second =  it_1->second - it_2->second;}
					else if(it_1 != num_map.end() && it_2 == num_map.end()){ it->second =  it_1->second - tmp_4;}
					else if(it_1 == num_map.end() && it_2 != num_map.end()){ it->second =  tmp_2 - it_2->second;}
					else if(it_1 == num_map.end() && it_2 == num_map.end()){ it->second =  tmp_2 - tmp_4;}
				}
				else if(vec[3] == "*" ){
					if(it_1 != num_map.end() && it_2 != num_map.end()){ it->second =  it_1->second * it_2->second;}
					else if(it_1 != num_map.end() && it_2 == num_map.end()){ it->second =  it_1->second * tmp_4;}
					else if(it_1 == num_map.end() && it_2 != num_map.end()){ it->second =  tmp_2 * it_2->second;}
					else if(it_1 == num_map.end() && it_2 == num_map.end()){ it->second =  tmp_2 * tmp_4;}
				}
				else if(vec[3] == "/" ){
					if(it_1 != num_map.end() && it_2 != num_map.end()){ it->second =  it_1->second / it_2->second;}
					else if(it_1 != num_map.end() && it_2 == num_map.end()){ it->second =  it_1->second / tmp_4;}
					else if(it_1 == num_map.end() && it_2 != num_map.end()){ it->second =  tmp_2 / it_2->second;}
					else if(it_1 == num_map.end() && it_2 == num_map.end()){ it->second =  tmp_2 / tmp_4;}
				}
				num_map[vec[0]]= it->second ;
				return ;
			}
			else if(dnum_map.find(vec[0])!=dnum_map.end())
			{

				auto it = dnum_map.find(vec[0]);
				auto it_1 = dnum_map.find(vec[2]);
				auto it_2 = dnum_map.find(vec[4]);
				double tmp_2;
				double tmp_4;
				std::istringstream(vec[2]) >> tmp_2;
				std::istringstream(vec[4]) >> tmp_4;
				if(vec[3] == "+" ){
					if(it_1 != dnum_map.end() && it_2 != dnum_map.end()){ it->second =  it_1->second + it_2->second;}
					else if(it_1 != dnum_map.end() && it_2 == dnum_map.end()){ it->second =  it_1->second + tmp_4;}
					else if(it_1 == dnum_map.end() && it_2 != dnum_map.end()){ it->second =  tmp_4 + it_2->second;}
					else if(it_1 == dnum_map.end() && it_2 == dnum_map.end()){ it->second =  tmp_2 + tmp_4;}
				}
				else if(vec[3] == "-" ){
					if(it_1 != dnum_map.end() && it_2 != dnum_map.end()){ it->second =  it_1->second - it_2->second;}
					else if(it_1 != dnum_map.end() && it_2 == dnum_map.end()){ it->second =  it_1->second - tmp_4;}
					else if(it_1 == dnum_map.end() && it_2 != dnum_map.end()){ it->second =  tmp_2 - it_2->second;}
					else if(it_1 == dnum_map.end() && it_2 == dnum_map.end()){ it->second =  tmp_2 - tmp_4;}
				}
				else if(vec[3] == "*" ){
					if(it_1 != dnum_map.end() && it_2 != dnum_map.end()){ it->second =  it_1->second * it_2->second;}
					else if(it_1 != dnum_map.end() && it_2 == dnum_map.end()){ it->second =  it_1->second * tmp_4;}
					else if(it_1 == dnum_map.end() && it_2 != dnum_map.end()){ it->second =  tmp_2 * it_2->second;}
					else if(it_1 == dnum_map.end() && it_2 == dnum_map.end()){ it->second =  tmp_2 * tmp_4;}
				}
				if(vec[3] == "/" ){
					if(it_1 != dnum_map.end() && it_2 != dnum_map.end()){ it->second =  it_1->second / it_2->second;}
					else if(it_1 != dnum_map.end() && it_2 == dnum_map.end()){ it->second =  it_1->second / tmp_4;}
					else if(it_1 == dnum_map.end() && it_2 != dnum_map.end()){ it->second =  tmp_2 / it_2->second;}
					else if(it_1 == dnum_map.end() && it_2 == dnum_map.end()){ it->second =  tmp_2 / tmp_4;}
				}	
				dnum_map[vec[0]] = it->second ;
				return ; 
			}
			else {std::cout << "my Inter dont undersdend you" << std::endl; abort() ;}
		}
		void print(std::vector <std::string> vec)
		{
			if(num_map.find(vec[2]) != num_map.end())
			{
				auto it = num_map.find(vec[2]);
				std::cout << it->second <<std::endl;
			}
			else if(dnum_map.find(vec[2]) != dnum_map.end() ){
				auto it = dnum_map.find(vec[2]);
				std::cout << it->second <<std::endl;
			}
			else if( text_map.find(vec[2])!= text_map.end()){
				auto it = text_map.find(vec[2]);
				std::cout << it->second <<std::endl;
			}
		}
};

#endif

int main()
{
	std::string name = "text.txt";
	Inter a ( name );
	return 0 ;
}
