//#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

#define tab "\t"
#define delimiter "\n-------------------------------------\n"

#define HUMAN_TAKE_PARAMETRS const std::string& last_name, const std::string& first_name, int age
#define HUMAN_GIVE_PARAMETRS last_name, first_name, age

class Human
{
private:
	std::string last_name;
	std::string first_name;
	int age;
public:
	const std::string& get_last_name()const
	{
		return last_name;
	}
	const std::string& get_first_name()const
	{
		return first_name;
	}
	int get_age()const
	{
		return age;
	}
	void set_last_name(const std::string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const std::string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(int age)
	{
		this->age = age;
	}
	Human(HUMAN_TAKE_PARAMETRS);
	virtual~Human();

	virtual void print()const;

};

std::ostream& operator<<(std::ostream& os, const Human& obj)
{
	return os << obj.get_last_name() << " " << obj.get_first_name() << " " << obj.get_age();
}

#define STUDENT_TAKE_PARAMETRS const std::string& speciality, const std::string& group, double rating, double attendance
#define STUDENT_GIVE_PARAMETRS speciality, group, rating, attendance

class Student :public Human
{
private:
	std::string speciality;
	std::string group;
	double rating;
	double attendance;
public:
	const std::string& get_speciality()const
	{
		return speciality;
	}
	const std::string& get_group()const
	{
		return group;
	}
	double get_rating()const
	{
		return rating;
	}
	double get_attendance()const
	{
		return attendance;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_group(const std::string& group)
	{
		this->group = group;
	}
	void set_rating(double rating)
	{
		this->rating = rating;
	}
	void set_attendance(double attendance)
	{
		this->attendance = attendance;
	}
	Student(HUMAN_TAKE_PARAMETRS, STUDENT_TAKE_PARAMETRS) :Human(HUMAN_GIVE_PARAMETRS)
	{
		set_speciality(speciality);
		set_group(group);
		set_rating(rating);
		set_attendance(attendance);
		cout << "SConstructor:\t" << this << endl;
	}
	~Student()
	{
		cout << "SDestructor:\t" << this << endl;
	}
	void print()const
	{
		Human::print();
		cout << speciality << " " << group << " " << rating << " " << attendance << endl;
	}
};

#define TEACHER_TAKE_PARAMETRS const std::string& speciality, int experience
#define TEACHER_GIVE_PARAMETRS speciality, experience

class Teacher :public Human
{
private:
	std::string speciality;
	int experience;
public:
	const std::string& get_speciality()const
	{
		return speciality;
	}
	int get_experience()const
	{
		return experience;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_experience(int experience)
	{
		this->experience = experience;
	}
	Teacher(HUMAN_TAKE_PARAMETRS, TEACHER_TAKE_PARAMETRS) :Human(HUMAN_GIVE_PARAMETRS)
	{
		set_speciality(speciality);
		set_experience(experience);
		cout << "TConstructor:\t" << this << endl;
	}
	~Teacher()
	{
		cout << "TDestructor:\t" << this << endl;
	}
	void print()const
	{
		Human::print();
		cout << speciality << " " << experience << endl;
	}
};

class Graduate :public Student
{
private:
	std::string subject;
public:
	const std::string& get_subject()const
	{
		return subject;
	}
	void set_subject(const std::string& subject)
	{
		this->subject = subject;
	}
	Graduate(HUMAN_TAKE_PARAMETRS, STUDENT_TAKE_PARAMETRS, const std::string& subject
	) :Student(HUMAN_GIVE_PARAMETRS, STUDENT_GIVE_PARAMETRS)
	{
		set_subject(subject);
		cout << "GConstructor:\t" << this << endl;
	}
	~Graduate()
	{
		cout << "GDestructor:\t" << this << endl;
	}
	void print()const
	{
		Student::print();
		cout << subject << endl;
	}

};

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

void Human::print()const
{
	cout << last_name << " " << first_name << " " << age << " y/o" << endl;
}

void print(Human** group, const int n)
{
	cout << delimiter << endl;
	for (int i = 0; i < n; i++)
	{
		group[i]->print();
		cout << delimiter << endl;
	}
}

void save(Human** group, const int n, const char* filename)
{
	ofstream fout(filename);
	fout << delimiter << endl;
	for (int i = 0; i < n; i++)
	{
		fout << *group[i] << endl;
		fout << delimiter << endl;
	}
	fout.close();
	char command[FILENAME_MAX] = "start notepad ";
	strcat_s(command, filename);
	system(command);
}

//#define INHERITANCE_CHECK
#define POLYMORPHISM

void main()
{
	setlocale(LC_ALL, "");

#ifdef INHERITANCE_CHECK
	cout << delimiter << endl;
	Human human("Vercitty", "Tomas", 31);
	human.print();
	cout << delimiter << endl;
	Student student("Pinkman", "Jessie", 25, "Chemistry", "WW_220", 98, 95);
	student.print();
	cout << delimiter << endl;
	Teacher teacher("White", "Walter", 52, "Chemistry", 20);
	teacher.print();
	cout << delimiter << endl;
	Graduate graduate("Shreder", "Hank", 40, "Criminalistic", "OBN", 90, 70, "How to catch Heisenberg?");
	graduate.print();
#endif // INHERITANCE_CHECK

#ifdef POLYMORPHISM

	Human* group[] =
	{
		new Student("Pinkman", "Jessie", 25, "Chemistry", "WW_220", 98, 95),
		new Teacher("White", "Walter", 52, "Chemistry", 20),
		new Graduate("Shreder", "Hank", 40, "Criminalistic", "OBN", 90, 70, "How to catch Heisenberg?"),
		new Student("Vercitty", "Tomas", 31, "Theft","Vice",98,99),
		new Teacher("Diaz","Ricardo", 50,"Weapons Distribution",25)
	};

	print(group, sizeof(group) / sizeof(group[0]));
	save(group, sizeof(group) / sizeof(group[0]), "Group.txt");

	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		delete group[i];
	}

#endif // POLYMORPHISM

}