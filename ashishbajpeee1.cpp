#include <iostream>

using namespace std;

class Complex {
private:
    double real;
    double imaginary;

public:
    // Constructors
    Complex() : real(0.0), imaginary(0.0) {}
    Complex(double r, double i) : real(r), imaginary(i) {}

    // Overload operator+ to add two complex numbers
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imaginary + other.imaginary);
    }

    // Overload operator* to multiply two complex numbers
    Complex operator*(const Complex& other) const {
        double result_real = real * other.real - imaginary * other.imaginary;
        double result_imaginary = real * other.imaginary + imaginary * other.real;
        return Complex(result_real, result_imaginary);
    }

    // Overload operators << and >> to print and read Complex Numbers
    friend ostream& operator<<(ostream& os, const Complex& complex) {
        os << complex.real << "+" << complex.imaginary << "i";
        return os;
    }

    friend istream& operator>>(istream& is, Complex& complex) {
        cout << "Enter real part: ";
        is >> complex.real;
        cout << "Enter imaginary part: ";
        is >> complex.imaginary;
        return is;
    }
};

int main() {
    Complex c1(2.0, 3.0);
    Complex c2(1.0, 4.0);

    // Addition
    Complex sum = c1 + c2;
    cout << "Sum: " << sum << endl;

    // Multiplication
    Complex product = c1 * c2;
    cout << "Product: " << product << endl;

    // Read complex number from user
    Complex c3;
    cout << "Enter a complex number:" << endl;
    cin >> c3;
    cout << "You entered: " << c3 << endl;

    return 0;
}

