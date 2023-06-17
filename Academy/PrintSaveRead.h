#pragma once
#include"stdafx.h"

void print(Human** group, const int n);
void save(Human** group, const int n, const char* filename);

Human* HumanFactory(const std::string& type);
Human** load(const std::string& filename, int& n);
