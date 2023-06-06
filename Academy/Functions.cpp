#include"Human.h"
#include"Student.h"
#include"Teacher.h"
#include"Graduate.h"
#include"Functions.h"

#define tab "\t"
#define delimiter "\n-------------------------------------\n"

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