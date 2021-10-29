#pragma once
#include "Tree.h"
#include <string>
class Member :
    public Tree
{
public:
    std::string data() override;
};

