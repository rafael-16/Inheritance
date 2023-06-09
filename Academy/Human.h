#pragma once
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

#define HUMAN_TAKE_PARAMETRS const std::string& last_name, const std::string& first_name, int age
#define HUMAN_GIVE_PARAMETRS last_name, first_name, age

class Human
{
	static const int LAST_NAME_WIDTH = 15;
	static const int FIRST_NAME_WIDTH = 10;

	std::string last_name;
	std::string first_name;
	int age;
public:
	const std::string& get_last_name()const;
	const std::string& get_first_name()const;
	int get_age()const;

	void set_last_name(const std::string& last_name);
	void set_first_name(const std::string& first_name);
	void set_age(int age);

	Human(HUMAN_TAKE_PARAMETRS);
	virtual~Human();
	virtual std::ostream& print(std::ostream& os)const;
	virtual ofstream& print(std::ofstream& ofs)const;
	virtual std::ifstream& scan(std::ifstream& ifs);
};

std::ostream& operator<<(std::ostream& os, const Human& obj);
std::ofstream& operator<<(std::ofstream& ofs, const Human& obj);
std::ifstream& operator>>(std::ifstream& ifs, Human& obj);
