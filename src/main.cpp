#include <iostream>
#include "my_array.h"

using namespace lab_13;

static void test() {
    std::cout << "Default array:\n";
    bool x[2]{};
    x[0] = false;
    x[1] = false;
    (x[0] = x[1]) = true;
    std::cout << x[0] << ' ' << x[1] << '\n';
    x[0] = false;
    x[1] = true;
    (x[0] = x[1]) = true;
    std::cout << x[0] << ' ' << x[1] << '\n';
    x[0] = true;
    x[1] = false;
    (x[0] = x[1]) = true;
    std::cout << x[0] << ' ' << x[1] << '\n';
    x[0] = true;
    x[1] = true;
    (x[0] = x[1]) = true;
    std::cout << x[0] << ' ' << x[1] << '\n';
    std::cout << "///////////////////////////////////\n";
    std::cout << "My array:\n";
    my_array<bool, 2> a;
    a[0] = false;
    a[1] = false;
    (a[0] = a[1]) = true;
    std::cout << a[0] << ' ' << a[1] << '\n';
    a[0] = false;
    a[1] = true;
    (a[0] = a[1]) = true;
    std::cout << a[0] << ' ' << a[1] << '\n';
    a[0] = true;
    a[1] = false;
    (a[0] = a[1]) = true;
    std::cout << a[0] << ' ' << a[1] << '\n';
    a[0] = true;
    a[1] = true;
    (a[0] = a[1]) = true;
    std::cout << a[0] << ' ' << a[1] << '\n';
    std::cout << "///////////////////////////////////\n";
}

int main() {
    test();
    my_array<bool, 15> a;
    a.at(0) = true;
    a.at(14) = true;
    a.at(1) = a.at(2) = true;
    (a.at(3) = a.at(4)) = true;
    a.at(5) = a.at(6) = a.at(0);
    (a.at(7) = a.at(8)) = a.at(0);
    a.at(9) = !a.at(10);
    a.at(10) = !a.at(10);
    a.at(11) = true;
    a.at(11) = false;
    a.at(12) = true;
    for (std::size_t i = 0; i < 15; ++i) {
        std::cout << a.at(i) << ' ';
    }
    std::cout << '\n';
    const my_array<bool, 15> b = a;
    for (std::size_t i = 0; i < 15; ++i) {
        std::cout << b.at(i) << ' ';
    }
    std::cout << '\n';
    try {
        b.at(15);
    } catch (std::exception &e) {
        std::cout << e.what() << '\n';
    }
    std::cout << sizeof(a) << ' ' << sizeof(my_array<bool, 1>) << ' ' <<  sizeof(my_array<bool, 8>) << '\n';
    my_array<bool, 15> c;
    c.fill(true);
    for (std::size_t i = 0; i < 15; ++i) {
        std::cout << c[i] << ' ';
    }
    std::cout << '\n';
    c.fill(false);
    for (std::size_t i = 0; i < 15; ++i) {
        std::cout << c[i] << ' ';
    }
    return 0;
}
