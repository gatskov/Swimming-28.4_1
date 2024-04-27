#pragma once
#include <string>
#include <map>

class Swimming
{
public:
    std::string name1, name2, name3, name4, name5, name6;
    int v1, v2, v3, v4, v5, v6;

    std::map<std::string, int> Mp;
    void InputDadeTreck();

    void sort_map();

    void sum(std::string a, int &b);

    void swimming();

    std::string CheckingLineEntry();

    int validateInputSpeed();
};
