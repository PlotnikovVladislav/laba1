#pragma once
#include <string>
class Tree
{
protected:
	std::string FIO, parents, spouse, children, birth, death;
	int age;
public:
	virtual std::string data() = 0;
};

