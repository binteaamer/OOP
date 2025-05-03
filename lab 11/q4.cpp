/*Write a template function sqrt(T num) that computes the square root. Throw:

NegativeNumberException (class) if num is negative (for integers/doubles).

InvalidTypeException (class) if T is not numeric (e.g., string).

Requirements:
Use type traits or template specialization for type checks.

Handle both exceptions in main().*/


#include <iostream>
#include <exception>
#include <string>
using namespace std;
class NegativeNumberException : public exception {
    string message;
public:
    NegativeNumberException(const string& msg) : message(msg) {}
    const char* what() const noexcept override { return message.c_str(); }
};

class InvalidTypeException : public exception {
    string message;
public:
    InvalidTypeException(const string& msg) : message(msg) {}
    const char* what() const noexcept override { return message.c_str(); }
};

template <typename T>
T sqrt(T num) {
    throw InvalidTypeException("Non-numeric type detected!");
}
template <>
double sqrt<double>(double num) {
    if (num < 0) throw NegativeNumberException("Input must be non-negative!");
    // Newton-Raphson approximation
    double guess = num;
    for (int i = 0; i < 10; ++i) {
        guess = (guess + num / guess) / 2.0;
    }
    return guess;
}

template <>
int sqrt<int>(int num) {
    if (num < 0) throw NegativeNumberException("Input must be non-negative!");
    return static_cast<int>(sqrt(static_cast<double>(num)));
}

int main() {
    try {
        cout << "sqrt(16.0): " << sqrt(16.0) << endl;  // 4
        cout << "sqrt(-4): " << sqrt(-4) << endl;      // Throws
    } catch (const NegativeNumberException& e) {
        cerr << "Error: " << e.what() << endl;
    }

    try {
        cout << sqrt("hello") << endl;  // Throws
    } catch (const InvalidTypeException& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
