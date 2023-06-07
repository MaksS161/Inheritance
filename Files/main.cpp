#include<iostream>
#include<fstream>
using namespace std;

//#define WRITE_TO_FILE
#define READ_FROM_FILE


void main()
{
	setlocale(LC_ALL, "");

#ifdef WRITE_TO_FILE
	cout << "Hello World!";
	ofstream fout;			// 1. Создаем поток  Output File Stream
	fout.open("File.txt", std::ios_base::app);	//2. Открываем поток
	//Флаг 'std::ios_base::app' (append) - дописывает вывод в конец файла 
	fout << "Hello World!" << endl;	//3. Выполняем запись в файл
	fout.close();			//4. Когда поток уже не нужен его ОБЯЗАТЕЛЬНО нужно закрыть
	system("notepad File.txt");//Открыте файла при запуске

#endif // WRITE_TO_FILE

#ifdef READ_FROM_FILE  // Чтение файла 
	char filename[_MAX_FNAME] = {};
	cout << "Введите имя файла: ";
	cin.getline(filename, _MAX_FNAME);

	ifstream fin;//Открытие потока
	//fin.open("File.txt");// открытие файла
	fin.open(filename);// ввод имени файла 
	if (fin.is_open())
	{
		//TODO: read file
		//1) Создаем буфер, в который будем выполнять чтение:
		const int SIZE = 256;
		char buffer[SIZE] = {};//Создаем буфер который сразу обнуляем '{}'
		//2) Запускаем цикл, который читает файл до конца:
		while (!fin.eof())
		{
			//fin >> buffer;// не корректно считывает, до пробела
			fin.getline(buffer, SIZE); //Используем 'fin.getline' 
			cout << buffer << endl;
		}
		fin.close();	//Закрываем поток только в том случае, если он открыт
	}
	else
	{
		cout << "Error: File not found" << endl;
	}
#endif // READ_FROM_FILE  
	
}