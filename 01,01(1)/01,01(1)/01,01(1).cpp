#include <iostream>

class Fraction {
private:
    int numerator;
    int denominator;

public:
    Fraction(int num, int denom) : numerator(num), denominator(denom) {
        if (denominator == 0) {
            std::cerr << "Error: Denominator cannot be zero." << std::endl;
            exit(1);
        }
    }

    int getNumerator() const {
        return numerator;
    }

    int getDenominator() const {
        return denominator;
    }

    Fraction operator+(const Fraction& other) const {
        int newNumerator = numerator * other.denominator + denominator * other.numerator;
        int newDenominator = denominator * other.denominator;
        return Fraction(newNumerator, newDenominator);
    }

    Fraction operator-(const Fraction& other) const {
        int newNumerator = numerator * other.denominator - denominator * other.numerator;
        int newDenominator = denominator * other.denominator;
        return Fraction(newNumerator, newDenominator);
    }

    Fraction operator*(const Fraction& other) const {
        int newNumerator = numerator * other.numerator;
        int newDenominator = denominator * other.denominator;
        return Fraction(newNumerator, newDenominator);
    }

    Fraction operator/(const Fraction& other) const {
        if (other.numerator == 0) {
            std::cerr << "Error: Division by zero." << std::endl;
            exit(1);
        }
        int newNumerator = numerator * other.denominator;
        int newDenominator = denominator * other.numerator;
        return Fraction(newNumerator, newDenominator);
    }

    int gcd(int a, int b) const {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    void print() const {
        int gcdVal = gcd(numerator, denominator);
        int simplifiedNumerator = numerator / gcdVal;
        int simplifiedDenominator = denominator / gcdVal;

        if (simplifiedDenominator == 1)
            std::cout << simplifiedNumerator;
        else
            std::cout << simplifiedNumerator << "/" << simplifiedDenominator;
    }
};

int main() {
    Fraction frac1(3, 4);
    Fraction frac2(2, 5);

    Fraction sum = frac1 + frac2;
    Fraction difference = frac1 - frac2;
    Fraction product = frac1 * frac2;
    Fraction division = frac1 / frac2;

    std::cout << "Sum: ";
    sum.print();
    std::cout << std::endl;

    std::cout << "Difference: ";
    difference.print();
    std::cout << std::endl;

    std::cout << "Product: ";
    product.print();
    std::cout << std::endl;

    std::cout << "Division: ";
    division.print();
    std::cout << std::endl;

    return 0;
}
