#include <iostream>

int main() {
    std::cout << "=== Taschenrechner ===" << std::endl;

    int a = 10;
    int b = 3;

    std::cout << a << " + " << b << " = " << a + b << std::endl;
    std::cout << a << " - " << b << " = " << a - b << std::endl;
    std::cout << a << " * " << b << " = " << a * b << std::endl;
    std::cout << a << " / " << b << " = " << a / b << std::endl;
    std::cout << a << " % " << b << " = " << a % b << std::endl;

    std::cout << "\n--- Schleife ---" << std::endl;
    for (int i = 1; i <= 5; i++) {
        std::cout << "Zeile " << i << std::endl;
    }

    return 0;
}
