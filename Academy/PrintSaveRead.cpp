#include"stdafx.h"
#include"PrintSaveRead.h"

void print(Human** group, const int n)
{
	cout << delimiter << endl;
	for (int i = 0; i < n; i++)
	{
		//group[i]->print();
		cout << typeid(*group[i]).name() << endl;
		cout << *group[i] << endl;
		cout << delimiter << endl;
	}
}
void save(Human** group, const int n, const char* filename)
{
	ofstream fout(filename);//Открываем поток 
	for (int i = 0; i < n; i++)
	{
		fout << typeid(*group[i]).name() << ":\t";
		fout << *group[i] << endl;
	}
	fout.close();//закрываем поток
	char command[FILENAME_MAX] = "notepad ";
	strcat(command, filename);
	system(command);
}

Human* HumanFactory(const std::string& type)
{
	if (type.find("Student") != std::string::npos) return new Student("", "", 0, "", "", 0, 0);
	if (type.find("Graduate") != std::string::npos)return new Graduate("", "", 0, "", "", 0, 0, "");
	if (type.find("Teacher") != std::string::npos) return new Teacher("", "", 0, "", 0);
}
Human** load(const std::string& filename, int& n)
{
	std::ifstream fin(filename);
	Human** group = nullptr;
	if (fin.is_open())
	{
		//TODO: read file//Чтение файла
		//1) Опредляем количество участников группы:
		std::string buffer;
		for (n = 0; !fin.eof(); n++)
		{
			std::getline(fin, buffer);
			if (buffer.empty())n--;
		}

		//2) Выделяем память:
		group = new Human * [n] {};

		//3) Возвращаемся в начало файла:
		fin.clear();
		fin.seekg(0);

		//4) Загружаем учасников группы из файл в выделенную память:
		for (int i = 0; i < n; i++)
		{
			std::getline(fin, buffer, ':');
			group[i] = HumanFactory(buffer);
			fin.ignore();
			fin >> *group[i];
		}
		fin.close();
	}
	else
	{
		cout << "Error: file not found" << endl;
	}
	return group;
}
