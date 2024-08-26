#pragma once

#ifndef RationalsGF_H
#define RationalsGF_H

#include <iostream>

namespace rationals_GlennFortunato {
    class RationalNumber {
    private:
        int numerator;
        int denominator;

    public:
        RationalNumber(int numerator, int denominator);
        RationalNumber(int value);
        RationalNumber();

        int getNum() const;

        // Overloaded operators
        bool operator==(const RationalNumber& other) const;
        bool operator<(const RationalNumber& other) const;
        bool operator<=(const RationalNumber& other) const;
        bool operator>(const RationalNumber& other) const;
        bool operator>=(const RationalNumber& other) const;
        bool operator!=(const RationalNumber& other) const;

        RationalNumber operator+(const RationalNumber& other) const;
        RationalNumber operator-(const RationalNumber& other) const;
        RationalNumber operator*(const RationalNumber& other) const;
        RationalNumber operator/(const RationalNumber& other) const;
        RationalNumber operator-() const;

        // Input and output operators
        friend std::ostream& operator<<(std::ostream& os, const RationalNumber& rational);
        friend std::istream& operator>>(std::istream& is, RationalNumber& rational);
    };
} 

#endif
