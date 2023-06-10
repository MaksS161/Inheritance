#include"Human.h"


//#define HUMAN_TAKE_PARAMETERS const std::string& last_name, const std::string& first_name, int age
//#define HUMAN_GIVE_PARAMETERS last_name, first_name,  age

//public:
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
