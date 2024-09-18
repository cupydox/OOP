#include <iostream>
#include <map>
#include <string>
std::string turkish_number(int number)
{
    std::map<int, std::string>dict;
    std::string result;
    dict[0] = "sifir";
    dict[1] = "bir";
    dict[2] = "iki";
    dict[3] = "üç";
    dict[4] = "dört";
    dict[5] = "beş";
    dict[6] = "alti";
    dict[7] = "yedi";
    dict[8] = "sekiz";
    dict[9] = "dokuz";
    dict[10] = "on";
    dict[20] = "yirmi";
    dict[30] = "otuz";
    dict[40] = "kirk";
    dict[50] = "elli";
    dict[60] = "altmış";
    dict[70] = "yetmiş";
    dict[80] = "seksen";
    dict[90] = "doksan";
    
    if (number % 10 != 0 && number > 9)
        return dict[number / 10 * 10] + " " + dict[number % 10];
    return dict[number];
}
