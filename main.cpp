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

const std::string FNAME = "A.txt";

int main()
{
  vector<CAR> cars;

  std::string status;

  int index = 0;
  int choose = false;
  int new_price = 0;

  File(FNAME, cars);

  std::cout << "Enter your status: ";
  getline(std::cin, status);

  std::cout << "If you are a guest, you can print" << std::endl;
  std::cout << "If you are an user, you can print, sort and add" << std::endl;
  std::cout << "If you are an admin, you can print, sort, delete, edit and add" << std::endl;

  while (true)
  {
    cout << "\n";
    cout << "1) Exit" << "\n";
    cout << "2) Exit with sort" << "\n";
    cout << "3) Add" << "\n";
    cout << "4) Edit" << "\n";
    cout << "5) Delete" << "\n";
    cout << "Number of choose: ";

    cin >> choose;

    cout << "\n";

    if (choose == 1)
    {
      cout << "Not sorted!" << "\n";
      Sort(cars);
      cout << "Cars: " << "\n" << "\n";
      printStruct(cars);

      return (0);
    }

    else if (choose == 2)
    {
      cout << "Sorted cars: " << "\n" << "\n";
      Sort(cars);
      printStruct(cars);

      return (0);
    }

    else if (choose == 3)
   {
      cout << "Start to add a car!" << "\n";

      addPosition(cars);
    }

    else if (choose == 4)
    {
      printStruct(cars);

      cout << "Index of car: ";
      cin >> index;

      cout << "New price: ";
      cin >> new_price;

      editPrice(cars, index, new_price);
    }

    else if (choose == 5)
    {
      printStruct(cars);

      cout << "Index of car: ";
      cin >> index;

      deletePosition(cars, index);
    }
  }
}