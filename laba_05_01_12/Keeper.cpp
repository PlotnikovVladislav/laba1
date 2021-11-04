#include "Keeper.h"

Keeper::Keeper()
{
	std::cout << "Keeper\n";
}

Keeper::~Keeper()
{
	std::cout << "~Keeper\n";
}

void Keeper::deleteElem(size_t position)
{
	delete trees.pop(position);
}

void Keeper::addElem(Tree* elem)
{
	trees.push_back(elem);
}

int Keeper::saveToFile(std::string file)
{
	std::ofstream fout(file);
	if (!fout) return 0;
	fout << to_string(trees.size()) << std::endl;
	for (size_t i = 0; i < trees.size(); ++i)
		fout << trees[i]->data();

	fout.close();
	return 1;
}

int Keeper::loadFromFile(std::string file)
{
	std::ifstream fin(file);
	if (!fin) return 0;
	std::string FIO, parents, lover, children, birth, death;
	int age;
	size_t trees_am;
	fin >> trees_am;
	for (size_t i = 0; i < trees_am; i++)
	{
		if (fin.eof()) return 0;
		getline(fin, FIO);
		getline(fin, FIO);
		getline(fin, parents);
		getline(fin, lover);
		getline(fin, children);
		getline(fin, birth);
		getline(fin, death);
		fin >> age;
		trees.push_back(new Member(FIO, parents, lover, children, birth, death, age));
	}
	return 1;
}

void Keeper::printAll()
{
	for (size_t i = 0; i < trees.size(); i++)
		std::cout << "человек №" << i + 1 << ":\n" << trees[i]->data_print();
}

size_t Keeper::size()
{
	return trees.size();
}
