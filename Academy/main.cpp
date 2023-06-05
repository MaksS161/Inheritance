#include <iostream>
#include <string>
using namespace std;

#define tab "\t"
#define delimiter "\n-------------------------------------\n"

#define HUMAN_TAKE_PARAMETERS const std::string& last_name, const std::string& first_name, int age
#define HUMAN_GIVE_PARAMETERS last_name, first_name,  age

class Human
{
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

	virtual void print()const
	{
		cout << last_name << " " << first_name << " " << age << " y/o" << endl;
	}
};

#define STUDENT_TAKE_PARAMETRS const std::string& speciality, const std::string& group, double rating, double attendance
#define STUDENT_GIVE_PARAMETRS speciality, group, rating, attendance
class Student :public Human
{
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
	Student(HUMAN_TAKE_PARAMETERS,STUDENT_TAKE_PARAMETRS):Human(HUMAN_GIVE_PARAMETERS)
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

	void print()const
	{
		Human::print();
		cout << speciality << ", " << group << " " << rating << " " << attendance << endl;
	}
};

#define TEACHER_TAKE_PARAMETRS const std:: string& speciality, int experience
#define TEACHER_GIVE_PARAMETRS speciality, experience
class Teacher : public Human
{
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

	Teacher(HUMAN_TAKE_PARAMETERS, TEACHER_TAKE_PARAMETRS) :Human(HUMAN_GIVE_PARAMETERS)
	{
		set_speciality(speciality);
		set_experience(experience);
		cout << "TConstruktor:\t" << this << endl;
	}
	~Teacher()
	{
		cout << "TDestruktor:\t" << this << endl;

	}
	void print()const
	{
		Human::print();
		cout << speciality << " " << experience << endl;
	}
};

class Graduate :public Student
{
	std::string subject;
public:
	const std::string& get_subgect()const
	{
		return subject;
	}
	void set_subgect(const std::string& subject)
	{
		this->subject = subject;
	}
	Graduate(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETRS, const std::string& subject) :Student(HUMAN_GIVE_PARAMETERS, STUDENT_GIVE_PARAMETRS)
	{
		this->subject = subject;
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

//#define INHERITANCE_CHECK
#define POLYMORPHISM

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
		new Teacher("Diaz", "Ricardo", 50, "Weapons distribution", 25)
	};
	//Specialisation (уточнение):
	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		group[i]->print();
		cout << delimiter << endl;
	}

	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		delete group[i];
	}

#endif // POLYMORPHISM

}