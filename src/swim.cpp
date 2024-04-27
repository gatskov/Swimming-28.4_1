#include <iostream>
#include <map>
#include "swim.h"
#include <chrono>
#include <thread>
#include <string>
#include <algorithm>



void Swimming::InputDadeTreck()
{
    std::cout << "\033[2J\033[1;1H";
    std::cout << "Waterway->1 enter Name: ";
    name1 = CheckingLineEntry();
    std::cout << "enter speed: ";
    v1 = validateInputSpeed();
    std::cout<< "~~~~~~~~~~~~~~~~~~~~~~~~\n";
    std::cout << "Waterway->2 enter Name: ";
    name2 = CheckingLineEntry();
    std::cout << "enter speed: ";
    v2 = validateInputSpeed();
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~\n";
    std::cout << "Waterway->3 enter Name: ";
    name3 = CheckingLineEntry();
    std::cout << "enter speed: ";
    v3 = validateInputSpeed();
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~\n";
    std::cout << "Waterway->4 enter Name: ";
    name4 = CheckingLineEntry();
    std::cout << "enter speed: ";
    v4 = validateInputSpeed();
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~\n";
    std::cout << "Waterway->5 enter Name: ";
    name5 = CheckingLineEntry();
    std::cout << "enter speed: ";
    v5 = validateInputSpeed();
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~\n";
    std::cout << "Waterway->6 enter Name: ";
    name6 = CheckingLineEntry();
    std::cout << "enter speed: ";
    v6 = validateInputSpeed();
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~\n";
    std::cout << "        = START=\n";
}

void Swimming::sort_map()
{
    std::multimap<int, std::string> MM;
    for (auto &it : Mp)
    {
        MM.insert({it.second, it.first});
    }
    std::cout << " -== The Result of the Swim ==--\n";
    for (auto &it : MM)
    {
        std::cout << it.second << ' '
                  << it.first << std::endl;
    }
    std::cout << "     +--------+\n";
    std::cout << "     | FINISH |\n";
    std::cout << "     +--------+\n";
    std::cin.get();
}

void Swimming::swimming()
{

    std::thread d1([&]()
              { sum(name1, v1); });
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::thread d2([&]()
                   { sum(name2, v2); });
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::thread d3([&]()
                   { sum(name3, v3); });
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::thread d4([&]()
                   { sum(name4, v4); });
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::thread d5([&]()
                   { sum(name5, v5); });
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::thread d6([&]()
                   { sum(name6, v6); });
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    d1.join();
    d2.join();
    d3.join();
    d4.join();
    d5.join();
    d6.join();
}

void Swimming::sum(std::string a, int &b)
{
    int t = 100 / b;
    Mp.insert(std::make_pair(a, t));
    int s = 0;
    for (int i(0); i < t; i++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        s += b;
        std::cout << a << "-> - " << s << " -- m.\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(1500));
    }
    std::cout << a << " --> Finish\n";
}

std::string Swimming::CheckingLineEntry()
{
    std::string t;
    std::cin >> t;
    while (!std::all_of(t.begin(), t.end(),
                        [](char c)
                        { return std::isalpha(c); }))
    {
        std::cout << "Enter the string correctly -> " << std::endl;
        std::cin >> t;
    }
    return t;
}

int Swimming::validateInputSpeed()
{
    int a;
    std::cin >> a;
    while (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Please re-enter the value:";
        std::cin >> a;
    }
    return a = abs(a);
}
