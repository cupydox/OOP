#include <iostream>
#include "include/three.h"


int main() {
    std::string s1, s2;
    
    std::cout << "Введите первое число" << std::endl;
    std::cin >> s1;
    std::cout << "Введите второе число" << std::endl;
    std::cin >> s2;

    Three num1(s1);
    Three num2(s2);
    Three sum = num1 + num2;

    if (num1 == num2) {
        std::cout << "Числа равны" << std::endl;
    } else {
        std::cout << "Числа не равны" << std::endl;
    }
    
    return 0;
}
