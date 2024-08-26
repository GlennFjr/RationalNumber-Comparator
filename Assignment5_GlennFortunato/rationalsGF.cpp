#include "rationalsGF.h"
#include <cmath>

// unnamed namespace
namespace {
    int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    rationals_GlennFortunato::RationalNumber simplify(int numerator, int denominator) {
        int common_factor = gcd(numerator, denominator);
        return rationals_GlennFortunato::RationalNumber(numerator / common_factor, denominator / common_factor);
    }
} 


namespace rationals_GlennFortunato {
    using namespace std;

    // Constructor

    RationalNumber::RationalNumber(int numerator, int denominator) {
        while (denominator == 0) {
            cout << "0 is an invalid denominator, please enter a valid denominator only: ";
            cin >> denominator;
        }

        int common_factor = gcd(numerator, denominator);
        this->numerator = numerator / common_factor;
        this->denominator = denominator / common_factor;
    }

    // Getter
    int RationalNumber::getNum() const {
        return numerator;
    }

    RationalNumber::RationalNumber(int value) : numerator(value), denominator(1) {}

    RationalNumber::RationalNumber() : numerator(0), denominator(1) {}

    // In/Out operators

    std::ostream& operator<<(std::ostream& os, const RationalNumber& rational) {
        
        os << rational.numerator << '/' << rational.denominator;
        return os;
    }

    std::istream& operator>>(std::istream& is, RationalNumber& rational) {
        
        char slash;

        if (is >> rational.numerator >> slash >> rational.denominator && slash == '/') {
            rational = simplify(rational.numerator, rational.denominator);
        }

        return is;
    }

    // Comparison operators

    bool RationalNumber::operator==(const RationalNumber& other) const {
        return (this->numerator == other.numerator) && (this->denominator == other.denominator);
    }

    bool RationalNumber::operator<(const RationalNumber& other) const {
        return (this->numerator * other.denominator) < (other.numerator * this->denominator);
    }

    bool RationalNumber::operator<=(const RationalNumber& other) const {
        return (*this < other) || (*this == other);
    }

    bool RationalNumber::operator>(const RationalNumber& other) const {
        return !(*this <= other);
    }

    bool RationalNumber::operator>=(const RationalNumber& other) const {
        return !(*this < other);
    }

    bool RationalNumber::operator!=(const RationalNumber& other) const {
        return !(*this == other);
    }

    // Algebra

    RationalNumber RationalNumber::operator+(const RationalNumber& other) const {
        // Addition
        int resultNumerator = (this->numerator * other.denominator) + (other.numerator * this->denominator);
        int resultDenominator = this->denominator * other.denominator;
        return RationalNumber(resultNumerator, resultDenominator);
    }

    RationalNumber RationalNumber::operator-(const RationalNumber& other) const {
        // Subtraction
        int resultNumerator = (this->numerator * other.denominator) - (other.numerator * this->denominator);
        int resultDenominator = this->denominator * other.denominator;
        return RationalNumber(resultNumerator, resultDenominator);
    }

    RationalNumber RationalNumber::operator*(const RationalNumber& other) const {
        // Multiplication
        int resultNumerator = this->numerator * other.numerator;
        int resultDenominator = this->denominator * other.denominator;
        return RationalNumber(resultNumerator, resultDenominator);
    }

    RationalNumber RationalNumber::operator/(const RationalNumber& other) const {
        // Division
        if (other.numerator == 0) {
            throw std::invalid_argument("Cannot divide by zero.");
        }

        int resultNumerator = this->numerator * other.denominator;
        int resultDenominator = this->denominator * other.numerator;
        return RationalNumber(resultNumerator, resultDenominator);
    }

    RationalNumber RationalNumber::operator-() const {
        // Negation
        return RationalNumber(-this->numerator, this->denominator);
    }
}
