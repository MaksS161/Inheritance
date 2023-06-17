#pragma once
#include"stdafx.h"

class Graduate :public Student
{
	std::string subject;
public:
	const std::string& get_subject()const;
	void set_subject(const std::string& subject);

	Graduate(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS, const std::string& subject) :Student(HUMAN_GIVE_PARAMETERS, STUDENT_GIVE_PARAMETERS);
	~Graduate();

	std::ostream& print(std::ostream& os)const;
	std::ofstream& print(std::ofstream& ofs)const;
	std::ifstream& scan(std::ifstream& ifs);
};
