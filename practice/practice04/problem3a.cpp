//used chat gpt to help with this one to
#include <iostream>

template <typename T>
T calculate(T num1, T num2, char opr) {
    T result;

    if (opr == '+') {
        result = num1 + num2;
    }
    else if (opr == '-') {
        result = num1 - num2;
    }
    else if (opr == '') {
        result = num1 num2;
    }
    else if (opr == '/') {
        if (num2 != 0) {
            result = num1 / num2;
        }
        else {
            std::cout << "Can't divide by zero\n";
            return T(0);
        }
    }
    else {
        std::cout << "Invalid input\n";
        return T(0);
    }

    return result;
}

int main() {
    double num1, num2;
    char opr;

    std::cout << "Enter first number: ";
    std::cin >> num1;
    std::cout << "Enter second number: ";
    std::cin >> num2;
    std::cout << "Enter operator (+, -, *, /): ";
    std::cin >> opr;

    if (static_cast<int>(num1) == num1 && static_cast<int>(num2) == num2) {
        int intNum1 = static_cast<int>(num1);
        int intNum2 = static_cast<int>(num2);

        int result = calculate(intNum1, intNum2, opr);
        std::cout << "Result: " << result << "\n";
    }
    else {
        double result = calculate(num1, num2, opr);
        std::cout << "Result: " << result << "\n";
    }

    return 0;
}
