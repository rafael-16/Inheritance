//#define _CRT_SECURE_NO_WARNINGS
#include"Human.h"
#include"Student.h"
#include"Teacher.h"
#include"Graduate.h"
#include"Functions.h"


//#define INHERITANCE_CHECK
#define POLYMORPHISM
//#define LOAD_TO_FILE

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