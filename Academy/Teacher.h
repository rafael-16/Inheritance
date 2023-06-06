#pragma once

#define TEACHER_TAKE_PARAMETRS const std::string& speciality, int experience
#define TEACHER_GIVE_PARAMETRS speciality, experience

class Teacher :public Human
{
	static const int SPECIALITY_WIDTH = 22;
	static const int EXPERIENCE_WIDTH = 3;


	std::string speciality;
	int experience;
public:
	const std::string& get_speciality()const;
	int get_experience()const;
	void set_speciality(const std::string& speciality);
	void set_experience(int experience);
	Teacher(HUMAN_TAKE_PARAMETRS, TEACHER_TAKE_PARAMETRS);
	~Teacher();
	std::ostream& print(std::ostream& os)const;
	std::ofstream& print(std::ofstream& ofs)const;
	std::ifstream& scan(std::ifstream& ifs);
};

