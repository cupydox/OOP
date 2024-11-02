#include <iostream>
#include <vector>
#include <memory>
#include "include/rectangle.h"
#include "include/rhombus.h"
#include "include/trapezoid.h"

int main() {
    std::vector<std::unique_ptr<Figure>> figures;
    int choice;

    do {
        std::cout << "Выберите фигуру для ввода:\n";
        std::cout << "1. Прямоугольник\n";
        std::cout << "2. Ромб\n";
        std::cout << "3. Трапеция\n";
        std::cout << "4. Вывести геометрические центры и площади фигур\n";
        std::cout << "5. Вычислить общую площадь фигур\n";
        std::cout << "6. Удалить фигуру по индексу\n";
        std::cout << "0. Выход\n";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                double width, height;
                std::cout << "Введите ширину и высоту прямоугольника: ";
                std::cin >> width >> height;
                figures.push_back(std::make_unique<Rectangle>(width, height));
                break;
            }
            case 2: {
                double d1, d2;
                std::cout << "Введите диагонали ромба: ";
                std::cin >> d1 >> d2;
                figures.push_back(std::make_unique<Rhombus>(d1, d2));
                break;
            }
            case 3: {
                double base1, base2, height;
                std::cout << "Введите основания и высоту трапеции: ";
                std::cin >> base1 >> base2 >> height;
                figures.push_back(std::make_unique<Trapezoid>(base1, base2, height));
                break;
            }
            case 4: {
                for (size_t i = 0; i < figures.size(); ++i) {
                    auto center = figures[i]->Center();
                    std::cout << "Фигура " << i << ": Центр = (" << center.first << ", " << center.second 
                              << "), Площадь = " << static_cast<double>(*figures[i]) << "\n";
                }
                break;
            }
            case 5: {
                double totalArea = 0;
                for (const auto& figure : figures) {
                    totalArea += static_cast<double>(*figure);
                }
                std::cout << "Общая площадь фигур = " << totalArea << "\n";
                break;
            }
            case 6: {
                int index;
                std::cout << "Введите индекс фигуры для удаления: ";
                std::cin >> index;
                if (index >= 0 && index < figures.size()) {
                    figures.erase(figures.begin() + index);
                    std::cout << "Фигура удалена.\n";
                } else {
                    std::cout << "Некорректный индекс.\n";
                }
                break;
            }
            case 0:
                std::cout << "Выход из программы.\n";
                break;
            default:
                std::cout << "Некорректный выбор. Пожалуйста, попробуйте снова.\n";
        }
    } while (choice != 0);

    return 0;
}
