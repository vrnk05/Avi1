#ifndef STRUCT_H
#define STRUCT_H

#include <string>

struct CAR
{
    std::string mark;
    std::string model;
    std::string colour;
    std::string numowners; //количество бывших владельцев
    int price;
    std::string VIN_number;
    std::string year;
    std::string mileage;
    float CUI; //коэффициент интереса пользователей
    struct CAR * next;
};

#endif