#include"Human.h"
#include"Student.h"

const std::string& Student::get_speciality()const
{
	return speciality;
}
const std::string& Student::get_group()const
{
	return group;
}
double Student::get_rating()const
{
	return rating;
}
double Student::get_attendance()const
{
	return attendance;
}
void Student::set_speciality(const std::string& speciality)
{
	this->speciality = speciality;
}
void Student::set_group(const std::string& group)
{
	this->group = group;
}
void Student::set_rating(double rating)
{
	this->rating = rating;
}
void Student::set_attendance(double attendance)
{
	this->attendance = attendance;
}
Student::Student(HUMAN_TAKE_PARAMETRS, STUDENT_TAKE_PARAMETRS) :Human(HUMAN_GIVE_PARAMETRS)
{
	set_speciality(speciality);
	set_group(group);
	set_rating(rating);
	set_attendance(attendance);
	cout << "SConstructor:\t" << this << endl;
}
Student::~Student()
{
	cout << "SDestructor:\t" << this << endl;
}
std::ostream& Student::print(std::ostream& os)const
{
	return Human::print(os) << " " << speciality << " " << group << " " << rating << " " << attendance;
}
std::ofstream& Student::print(std::ofstream& ofs)const
{
	Human::print(ofs);
	ofs.width(SPECIALITY_WIDTH);
	ofs << speciality;
	ofs.width(GROUP_WIDTH);
	ofs << group;
	ofs.width(RATING_WIDTH);
	ofs << rating;
	ofs.width(ATTENDANCE_WIDTH);
	ofs << attendance;
	return ofs;
}
std::ifstream& Student::scan(std::ifstream& ifs)
{
	Human::scan(ifs);
	char buffer[SPECIALITY_WIDTH + 1] = {};
	ifs.read(buffer, SPECIALITY_WIDTH);
	for (int i = strlen(buffer) - 1; buffer[i] == ' '; i--)
		buffer[i] = 0;
	while (buffer[0] == ' ')
		for (int i = 0; buffer[i]; i++)
			buffer[i] = buffer[i + 1];
	speciality = buffer;
	ifs >> group >> rating >> attendance;
	return ifs;
}