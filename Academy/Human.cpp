#include"Human.h"


const std::string& Human::get_last_name()const
{
	return last_name;
}
const std::string& Human::get_first_name()const
{
	return first_name;
}
int Human::get_age()const
{
	return age;
}
void  Human::set_last_name(const std::string& last_name)
{
	this->last_name = last_name;
}
void Human::set_first_name(const std::string& first_name)
{
	this->first_name = first_name;
}
void Human::set_age(int age)
{
	this->age = age;
}
Human::Human(HUMAN_TAKE_PARAMETRS)
{
	set_last_name(last_name);
	set_first_name(first_name);
	set_age(age);
	cout << "HConstructor:\t" << this << endl;
}
Human::~Human()
{
	cout << "HDestructor:\t" << this << endl;
}

std::ostream& Human::print(std::ostream& os)const
{
	return os << last_name << " " << first_name << " " << age << " y/o";
}

ofstream& Human::print(std::ofstream& ofs)const
{
	ofs.width(LAST_NAME_WIDTH);
	ofs << std::left;
	ofs << last_name;
	ofs.width(FIRST_NAME_WIDTH);
	ofs << first_name;
	ofs.width(3);
	ofs << age;
	return ofs;
}
std::ifstream& Human::scan(std::ifstream& ifs)
{
	ifs >> last_name >> first_name >> age;
	return ifs;
}

std::ostream& operator<<(std::ostream& os, const Human& obj)
{
	return obj.print(os);
}

std::ofstream& operator<<(std::ofstream& ofs, const Human& obj)
{
	obj.print(ofs);
	return ofs;
}

std::ifstream& operator>>(std::ifstream& ifs, Human& obj)
{
	return obj.scan(ifs);
}
