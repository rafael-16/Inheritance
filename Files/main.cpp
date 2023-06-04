#include<iostream>
#include<fstream>

using namespace std;

//#define WRITE_TO_FILE
#define READ_FROM_FILE

void main()
{
	setlocale(LC_ALL, "");

#ifdef WRITE_TO_FILE
	cout << "Hello Word!" << endl;
	std::ofstream fout;						// 1). Создаем поток (Output File Stream)
	fout.open("File.txt", std::ios::app);	// 2). Открываем поток, флаг std::ios_base::app дописывает вывод в конец файла
	fout << "Hello, Word!" << endl;			// 3). Запись в файл
	fout.close();							// 4). После использования потока, обязательно закрываем!
	system("notepad File.txt");
#endif // WRITE_TO_FILE

	char filename[_MAX_FNAME]{};
	cout << "Введите имя файла: ";
	cin.getline(filename, _MAX_FNAME);

	std::ifstream fin;
	fin.open(filename);
	if (fin.is_open())
	{
		// 1. Создаем буфер в котором выполним чтение
		const int SIZE = 256;
		char buffer[SIZE] = {};
		// 2. Запускаем цикл чтения файла до конца
		while (!fin.eof())
		{
			fin.getline(buffer, SIZE);
			cout << buffer << endl;
		}
		fin.close();
	}
	else
		cout << "Error: File not found!"<<endl;
}