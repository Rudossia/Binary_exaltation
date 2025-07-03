#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>
#include "pow.h"

bool readInteger(const std::string& prompt, int64_t& value) {
    std::string input;
    while (true) {
        std::cout << prompt;
        std::cin >> input;

        if (input == "exit" || input == "выход") {
            return false;
        }

        try {
            size_t idx;
            value = std::stoll(input, &idx);
            if (idx != input.size()) throw std::invalid_argument("Недопустимые символы");
            return true;
        } catch (const std::exception& e) {
            std::cerr << "Ошибка ввода: " << e.what() << ". Повторите попытку.\n";
        }
    }
}

int main() {
    std::cout << "Добро пожаловать! Чтобы выйти, введите 'exit' или 'выход'.\n";

    int64_t base, exponent;

    while (true) {
        if (!readInteger("Введите основание (целое число): ", base)) {
            std::cout << "Завершение программы.\n";
            break;
        }

        if (!readInteger("Введите степень (неотрицательное целое число): ", exponent)) {
            std::cout << "Завершение программы.\n";
            break;
        }

        if (exponent < 0) {
            std::cerr << "Ошибка: степень не может быть отрицательной.\n";
            continue;
        }

        try {
            auto result = power(base, exponent);
            std::cout << "Результат: " << result << "\n";
        } catch (const std::exception& ex) {
            std::cerr << "Во время вычисления произошла ошибка: " << ex.what() << "\n";
        }

        std::cout << "-----------------------------\n";
    }

    return 0;
}
