#include"Human.h"
#include"Student.h"
#include"Graduate.h"

const std::string& Graduate::get_subject()const
{
	return subject;
}
void Graduate::set_subject(const std::string& subject)
{
	this->subject = subject;
}
Graduate::Graduate(HUMAN_TAKE_PARAMETRS, STUDENT_TAKE_PARAMETRS, const std::string& subject
) :Student(HUMAN_GIVE_PARAMETRS, STUDENT_GIVE_PARAMETRS)
{
	set_subject(subject);
	cout << "GConstructor:\t" << this << endl;
}
Graduate::~Graduate()
{
	cout << "GDestructor:\t" << this << endl;
}
std::ostream& Graduate::print(std::ostream& os)const
{
	return Student::print(os) << " " << subject;
}
std::ofstream& Graduate::print(std::ofstream& ofs)const
{
	Student::print(ofs);
	ofs << subject;
	return ofs;
}
std::ifstream& Graduate::scan(std::ifstream& ifs)
{
	Student::scan(ifs);
	std::getline(ifs, subject);
	return ifs;
}