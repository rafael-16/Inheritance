#pragma once

#define STUDENT_TAKE_PARAMETRS const std::string& speciality, const std::string& group, double rating, double attendance
#define STUDENT_GIVE_PARAMETRS speciality, group, rating, attendance

class Student :public Human
{
	static const int SPECIALITY_WIDTH = 22;
	static const int GROUP_WIDTH = 8;
	static const int RATING_WIDTH = 8;
	static const int ATTENDANCE_WIDTH = 8;

	std::string speciality;
	std::string group;
	double rating;
	double attendance;

public:
	const std::string& get_speciality()const;
	const std::string& get_group()const;
	double get_rating()const;
	double get_attendance()const;
	void set_speciality(const std::string& speciality);
	void set_group(const std::string& group);
	void set_rating(double rating);
	void set_attendance(double attendance);
	Student(HUMAN_TAKE_PARAMETRS, STUDENT_TAKE_PARAMETRS);
	~Student();
	std::ostream& print(std::ostream& os)const;
	std::ofstream& print(std::ofstream& ofs)const;
	std::ifstream& scan(std::ifstream& ifs);
};
