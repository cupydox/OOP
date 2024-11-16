#include "include/rectangle.h"
#include "include/rhombus.h"
#include "include/trapezoid.h"
#include "include/array.h"

int main() {
    Array<Figure<int>*> figures(3);
    figures[0] = new Rectangle<int>(5, 10);
    figures[1] = new Rhombus<int>(4, 6);
    figures[2] = new Trapezoid<int>(3, 5, 7);

    for (size_t i = 0; i < figures.Size(); ++i) {
        std::cout << *figures[i] << ", Area = " << static_cast<double>(*figures[i]) << std::endl;
    }

    delete figures[0];
    delete figures[1];
    delete figures[2];

    return 0;
}
