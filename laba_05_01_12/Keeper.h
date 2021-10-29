#pragma once
#include <fstream>
#include <string>
#include "Tree.h"
#include "List.h"
class Keeper
{
private:
	List<Tree*> figures;

public:
	void deleteElem(size_t position);
	void addElem(Tree* elem);
	int saveToFile(std::string file);
	int loadFromFile(std::string file);
	void printAll();
};
