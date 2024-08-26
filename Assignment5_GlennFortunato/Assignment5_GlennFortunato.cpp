#include "rationalsGF.h"
#include <cmath>

namespace {
    int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    GF::RationalNumber simplify(int numerator, int denominator) {
        int common_factor = gcd(numerator, denominator);
        return GF::RationalNumber(numerator / common_factor, denominator / common_factor);
    }
} // unnamed namespace

namespace GF {
    using std::istream;
    using std::ostream;

    RationalNumber::RationalNumber(int numerator, int denominator) {
        if (denominator == 0) {
            throw std::invalid_argument("Denominator cannot be zero.");
        }
        RationalNumber simplified = simplify(numerator, denominator);
        this->numerator = simplified.numerator;
        this->denominator = simplified.denominator;
    }

    RationalNumber::RationalNumber(int value) : numerator(value), denominator(1) {}

    RationalNumber::RationalNumber() : numerator(0), denominator(1) {}

    // ... (implementation of other member functions)
} // namespace GF
