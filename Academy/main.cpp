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
	static const int LAST_NAME_WIDTH = 15;
	static const int FIRST_NAME_WIDTH = 10;

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
	Human(HUMAN_TAKE_PARAMETRS)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HConstructor:\t" << this << endl;
	}

	virtual~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}

	virtual std::ostream& print(std::ostream& os)const
	{
		return os << last_name << " " << first_name << " " << age << " y/o";
	}

	virtual ofstream& print(std::ofstream& ofs)const
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
	virtual std::ifstream& scan(std::ifstream& ifs)
	{
		ifs >> last_name >> first_name >> age;
		return ifs;
	}
};

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
	std::ostream& print(std::ostream& os)const
	{
		return Human::print(os) << " " << speciality << " " << group << " " << rating << " " << attendance;
	}
	std::ofstream& print(std::ofstream& ofs)const
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
	std::ifstream& scan(std::ifstream& ifs)
	{
		Human::scan(ifs);
		char buffer[SPECIALITY_WIDTH+1] = {};
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
};



#define TEACHER_TAKE_PARAMETRS const std::string& speciality, int experience
#define TEACHER_GIVE_PARAMETRS speciality, experience

class Teacher :public Human
{
	static const int SPECIALITY_WIDTH = 22;
	static const int EXPERIENCE_WIDTH = 3;


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
	std::ostream& print(std::ostream& os)const
	{
		return Human::print(os) << " " << speciality << " " << experience;
	}
	std::ofstream& print(std::ofstream& ofs)const
	{
		Human::print(ofs);
		ofs.width(SPECIALITY_WIDTH);
		ofs << speciality;
		ofs.width(EXPERIENCE_WIDTH);
		ofs << experience;
		return ofs;
	}
	std::ifstream& scan(std::ifstream& ifs)
	{
		Human::scan(ifs);
		char buffer[SPECIALITY_WIDTH+1] = {};
		ifs.read(buffer, SPECIALITY_WIDTH);
		speciality = buffer;
		ifs >> experience;
		return ifs;
	}
};

class Graduate :public Student
{
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
	std::ostream& print(std::ostream& os)const
	{
		return Student::print(os) << " " << subject;
	}
	std::ofstream& print(std::ofstream& ofs)const
	{
		Student::print(ofs);
		ofs << subject;
		return ofs;
	}
	std::ifstream& scan(std::ifstream& ifs)
	{
		Student::scan(ifs);
		std::getline(ifs, subject);
		return ifs;
	}
};


void print(Human** group, const int n)
{
	cout << delimiter << endl;
	for (int i = 0; i < n; i++)
	{
		//group[i]->print();
		cout << *group[i] << endl;
		cout << delimiter << endl;
	}
}

void save(Human** group, const int n, const char* filename)
{
	ofstream fout(filename);
	for (int i = 0; i < n; i++)
	{
		fout << typeid(*group[i]).name() << ":\t";
		fout << *group[i] << endl;
	}
	fout.close();
	char command[FILENAME_MAX] = "start notepad ";
	strcat_s(command, filename);
	system(command);
}
Human* HumanFactory(const std::string& type)
{
	if (type.find("Student") != std::string::npos) return new Student("", "", 0, "", "", 0, 0);
	if (type.find("Graduate") != std::string::npos) return new Graduate("", "", 0, "", "", 0, 0, "");
	if (type.find("Teacher") != std::string::npos) return new Teacher("", "", 0, "", 0);
}
Human** load(const std::string& filename, int& n)
{
	std::ifstream fin(filename);
	Human** group = nullptr;
	if (fin.is_open())
	{
		std::string buffer;
		for (n = 0; !fin.eof(); n++)//		определяем кол-во участников группы
		{
			std::getline(fin, buffer);
			if (buffer.empty())n--;
		}
		group = new Human * [n] {};//		выделяем память

		fin.clear();//						очищаем поток
		fin.seekg(0);//						возвращаемся в начало файла
		for (int i = 0; i < n; i++) //		Записываем участников из файла в выделенную память
		{
			std::getline(fin, buffer, ':');
			group[i] = HumanFactory(buffer);
			fin.ignore();
			fin >> *group[i];
		}
		fin.close();
	}
	else
		cout << "Error: file not found!" << endl;
	return group;
}

//#define INHERITANCE_CHECK
//#define POLYMORPHISM
#define LOAD_TO_FILE

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
		new Teacher("Diaz","Ricardo", 50,"Weapons Distribution",25),
		new Graduate("Rosenberg","Ken", 27, "Lower", "Vice", 75,20,"Get money back")
	};

	print(group, sizeof(group) / sizeof(group[0]));
	save(group, sizeof(group) / sizeof(group[0]), "Group.txt");



	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		delete group[i];
	}

#endif // POLYMORPHISM

#ifdef LOAD_TO_FILE

	int n = 0;
	Human** group = load("group.txt", n);
	print(group, n);

	for (int i = 0; i < n; i++)
		delete group[i];
	delete[] group;
	group = nullptr;
#endif // LOAD_TO_FILE


}