#pragma once

class Graduate :public Student
{
	std::string subject;
public:
	const std::string& get_subject()const;
	void set_subject(const std::string& subject);
	Graduate(HUMAN_TAKE_PARAMETRS, STUDENT_TAKE_PARAMETRS, const std::string& subject);
	~Graduate();
	std::ostream& print(std::ostream& os)const;
	std::ofstream& print(std::ofstream& ofs)const;
	std::ifstream& scan(std::ifstream& ifs);
};
