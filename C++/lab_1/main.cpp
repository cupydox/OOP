#include <iostream>
#include "include/turkish.h"

int main()
{
  int number;
  std::cin >> number;
  std::cout << turkish_number(number) << std::endl;

  return 0;
}