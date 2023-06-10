#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define tab "\t"
#define delimiter "\n-------------------------------------\n"

#define HUMAN_TAKE_PARAMETERS const std::string& last_name, const std::string& first_name, int age
#define HUMAN_GIVE_PARAMETERS last_name, first_name,  age

class Human
{
	//Статические переменные и константы принадлежат классу, а не объектам, и соответственно, занимают память в классе, а не в объектах.
	//Статические члены являются общими для всех объектов класса, все объекты имеют равноправный доступ к статическим полям.
	static const int LAST_NAME_WIDTH = 15;// 'static const' - статическа константа 
	static const int FIRST_NAME_WIDTH = 10;
	//В классе можно проинициализировать статическую, только константу и только типа 'int'
	//все остальные статические переменные и константы могу быть проинициализированы только за классом
	//------------------------------------------------------------------------------------//
	//------------------------------------------------------------------------------------//
	//Нестатические переменные и константы пренадлежат своим объектам, и следовательно хранятся и занимают память в объектах.
	std::string last_name;
	std::string first_name;
	int age;
public:
	const std::string& get_last_name()const
	{
		return last_name;
	}
	const std::string& get_frist_name()const
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

	//			Constructors:
	Human(HUMAN_TAKE_PARAMETERS)
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

#define STUDENT_TAKE_PARAMETERS const std::string& speciality, const std::string& group, double rating, double attendance
#define STUDENT_GIVE_PARAMETERS speciality, group, rating, attendance
class Student :public Human
{
	static const int SPECIALITY_WIDTH = 22;
	static const int GROUP_WIDTH = 8;
	static const int RATING_WIDTH = 8;
	static const int ATTTENDANCE_WIDTH = 8;

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
	//				Constructors:
	Student(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS) :Human(HUMAN_GIVE_PARAMETERS)
	{
		set_speciality(speciality);
		set_group(group);
		set_rating(rating);
		set_attendance(attendance);
		cout << "SCostructor:\t" << this << endl;
	}
	~Student()
	{
		cout << "SDestructor:\t" << this << endl;
	}

	std::ostream& print(std::ostream& os)const
	{
		return Human::print(os) << " " << speciality << ", " << group << " " << rating << " " << attendance;
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
		ofs.width(ATTTENDANCE_WIDTH);
		ofs << attendance;
		return ofs;
	}
	std::ifstream& scan(std::ifstream& ifs)
	{
		Human::scan(ifs);
		char buffer[SPECIALITY_WIDTH + 1] = {};
		ifs.read(buffer, SPECIALITY_WIDTH);
		for (int i = strlen(buffer) - 1; buffer[i] == ' '; i--)			buffer[i] = 0;
		while (buffer[0] == ' ')for (int i = 0; buffer[i]; i++)		buffer[i] = buffer[i + 1];
		speciality = buffer;
		ifs >> group;
		ifs >> rating >> attendance;
		return ifs;
	}
};

#define TEACHER_TAKE_PARAMETERS	const std::string& speciality, int experience
#define TEACHER_GIVE_PARAMETERS	speciality, experience
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

	Teacher(HUMAN_TAKE_PARAMETERS, TEACHER_TAKE_PARAMETERS) :Human(HUMAN_GIVE_PARAMETERS)
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
		char buffer[SPECIALITY_WIDTH + 1] = {};
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

	Graduate(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS, const std::string& subject) :Student(HUMAN_GIVE_PARAMETERS, STUDENT_GIVE_PARAMETERS)
	{
		this->subject = subject;
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
//#define INHERITANCE_CHECK
//#define POLYMORPHISM
#define LOAD_FROM_FILE

void main()
{
	setlocale(LC_ALL, "");
#ifdef INHERITANCE_CHECK
	Human human("Vercetty", "Tomas", 30);
	human.print();

	Student student("Pinkman", "Jessie", 25, "Chemistry", "WW_220", 98, 95);
	student.print();

	Teacher teacher("White", "Walter", 50, "Chemistry", 20);
	teacher.print();

	Graduate graduate("Schreder", "Hank", 40, "Criminalistic", "OBN", 90, 70, "How to catch Heizenberg");
	graduate.print();
#endif // INHERITANCE_CHECK

#ifdef POLYMORPHISM

	//Generalisation (Обобщили) :
	Human* group[] =
	{
		new Student("Pinkman", "Jessie", 25, "Chemistry", "WW_220", 98, 95),
		new Teacher("White", "Walter", 50, "Chemistry", 20),
		new Graduate("Schreder", "Hank", 40, "Criminalistic", "OBN", 90, 70, "How to catch Heizenberg"),
		new Student("Vercetty", "Tomas", 30, "Theft", "Vice", 98, 99),
		new Teacher("Diaz", "Ricardo", 50, "Weapons distribution", 25),
		new Graduate("Rosenberg", "Ken", 27, "Lower", "Vice", 75, 20, "Get money back")
	};
	//Specialisation (уточнение):
	print(group, sizeof(group) / sizeof(group[0]));
	save(group, sizeof(group) / sizeof(group[0]), "group.txt");

	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		delete group[i];
	}

#endif // POLYMORPHISM

#ifdef LOAD_FROM_FILE
	int n = 0;	//размер группы
	Human** group = load("group.txt ", n);
	print(group, n);
	for (int i = 0; i < n; i++)
	{
		delete group[i];
	}
	delete[] group;
	group = nullptr;
#endif // LOAD_FROM_FILE

}