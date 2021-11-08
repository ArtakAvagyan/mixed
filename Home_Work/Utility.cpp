#include <regex>
#include <string>
#include <iostream>
class Utility
{
public:
	static bool isNumber(const std::string& str)
	{
		return isFloat(str) || isInteger(str);
	}
	static bool isFloat(const std::string& str)
	{
		if(str[0] < '0' || str[0] > '9' || str[str.size()-1] < '0' || str[str.size()-1] > '9'){return false;}
		int count = 0;
		for(int i = 1;i<str.size()-1;++i)
		{
			if(str[i]== '.'){count++;}
			else if(str[i]<'0' || str[i] > '9'){return false;}
		}
		if(count == 1){return true;}
		return false ;
	}
	static bool isInteger(const std::string& str)
	{
		if(str[0] == '-' || str[0] > '0' && str[0] <='9')
		{
			for(int i = 1; i < str.size();++i)
			{
				if(str[i]>'9' || str[i]<'0'){return false;}
			}
		}
		else{return false;}
		return true;
	}
	static bool isBoolean(const std::string& str){return str == "true" || str == "false" ;}
	static bool isEmail(const std::string& str)
	{
		std::regex re ("(^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\\.[a-zA-Z0-9-.]+$)");
		return regex_search(str, re);
	}
	static bool isURL(const std::string& str)
	{
		std::regex re ("((http|https)://)(www.)?[a-zA-Z0-9@:%._\\+~#?&//=]{2,256}\\.[a-z]{2,6}\\b([-a-zA-Z0-9@:%._\\+~#?&//=]*)");
		return regex_search(str,re);
	}
};




int main()
{
	std::string str;
	std::cin>>str;
	if(Utility::isBoolean(str)){std::cout<< "ok"<<std::endl;}
	return 0;
}
