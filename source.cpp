#include "Guest.h"
#include "User.h"
#include "Admin.h"
#include "Server.h"
#include "CAR.h"

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>


using namespace std;

void Sort(std::vector<CAR>& cars)
{
  sort(cars.begin(), cars.end(),
  [](const CAR p1, const CAR p2)
  {
    return p1.CUI > p2.CUI;
  });
}

void printStruct(const std::vector<CAR>& cars)
{
  for (const CAR& carr : cars)
  {
  std::cout << "Mark: " << carr.mark << std::endl;
  std::cout << "Model: " << carr.model << std::endl;
  std::cout << "Colour: " << carr.colour << std::endl;
  std::cout << "Numowners: " << carr.numowners << std::endl;
  std::cout << "Price: " << carr.price << std::endl;
  std::cout << "VIN_number: " << carr.VIN_number << std::endl;
  std::cout << "Year: " << carr.year << std::endl;
  std::cout << "Mileage: " << carr.mileage << std::endl;
  std::cout << "CUI: " << carr.CUI << std::endl << std::endl;
  }
}

void addPosition (std::vector<CAR>& cars)
{
  CAR car;
  std::cout << "Enter mark: ";
  std::cin >> car.mark;

  std::cout << "Enter model: ";
  std::cin >> car.model;

  std::cout << "Enter colour: ";
  std::cin >> car.colour;

  std::cout << "Enter number of owners: ";
  std::cin >> car.numowners;

  std::cout << "Enter price: ";
  std::cin >> car.price;

  std::cout << "Enter VIN: ";
  std::cin >> car.VIN_number;

  std::cout << "Enter year: ";
  std::cin >> car.year;

  std::cout << "Enter mileage: ";
  std::cin >> car.mileage;

  std::cout << "Enter CUI: ";
  std::cin >> car.CUI;

  cars.push_back(car);
}

void editPrice (std::vector<CAR>& cars, int index, int new_price)
{
  int old_ptice = cars[index].price;
  cars[index].price = new_price;

  if (new_price > old_ptice)
  {
    cars[index].CUI -= 0.3;
  }
  else if (new_price < old_ptice)
  {
    cars[index].CUI += 0.3;
  }
}

void deletePosition(std::vector<CAR>& cars, int index)
{
  cars.erase(cars.begin() + index);
}

void File(const std::string& FNAME, std::vector<CAR>& cars)
{
  std::ifstream file(FNAME); 

  CAR car;

  int length;

  if (!file.is_open())
  {  //входная проверка
    std::cout << "Error 101 - FILE NOT EXIST" << std::endl;
    return;
  }

  file >> length;


  for (int i = 0; i < length; i++)
  {
      file >> car.mark >> car.model >> car.colour >> car.numowners >> car.price >> car.VIN_number >> car.year >> car.mileage >> car.CUI;
      cars.push_back(car);
  }
}