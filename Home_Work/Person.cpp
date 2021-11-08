#include <iostream>
struct Person
{
	char* name;
	char* Email;
	int age ;
};

void Person_def (Person* p) // defolut constructor 
{
	p->name =(char*)std::malloc(sizeof(char)*20);
	p->Email =(char*)std::malloc(sizeof(char)*40);
}
void Person_copy (Person* p ,Person* other) //copy constructor
{
	p->name = (char*)std::malloc(sizeof(char)*20);
	p->Email =(char*)std::malloc(sizeof(char)*40);
	for(int i = 0; i<20;++i)
		p->name[i] = other->name[i];
	for(int i = 0; i<40;++i)
		p->name[i] = other->Email[i];
	p->age = other->age;
}
void Person_par (Person* p ,const char* ot_name = nullptr ,const char* ot_Em = nullptr ,int ot_age = 0 ,int size_name = 0 ,int size_Email = 0) // Parametr constructor
{
	p->name =(char*)std::malloc(sizeof(char)*20);
	p->Email =(char*)std::malloc(sizeof(char)*40);
	for(int i = 0; i<size_name;++i)
		p->name[i] = ot_name[i];
	for(int i = 0; i<size_Email;++i)
		p->name[i] = ot_Em[i];
	if(ot_age<150 && ot_age >= 0)
		p->age = ot_age;
}
void Person_dtor(Person* p) //Destructor
{
	delete[] p->name;
	delete[] p->Email;
}

Person* Veragrum(Person* p , const Person * oth)
{
	if(&p == &oth){return p;}
	for(int i = 0 ; i < 20;++i)
	p->name[i] = oth->name[i];
	for(int i = 0 ; i < 20;++i)
	p->Email[i] = oth->Email[i];
	p->age = oth->age;
	return p;
}
void set_age(Person* p,int in_age){p->age = in_age;}
int get_age(const Person* p){return p->age;}


int main()
{
	Person tmp;
	char Name[20]= {"Artak"};
	char Email[40]={"avagyanartak44@gamil.com"};
	Person_par(&tmp,Name,Email,23,20,40);
	std::cout<< get_age(&tmp);

}

