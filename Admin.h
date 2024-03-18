#pragma once

#include "CAR.h"
#include <vector>


void printStruct(const std::vector<CAR>& cars);  //функция печати массива
void deletePosition(std::vector<CAR>& cars, int index); //удаление позиции
void addPosition (std::vector<CAR>& cars);//добавление позиции
void editPrice (std::vector<CAR>& cars, int index, int new_price); //изменение стоимости позиции