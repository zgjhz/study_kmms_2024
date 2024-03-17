#pragma once

#include <iostream>

namespace GGolub {
    class LongNumber {
        static const char END = '\0';
        static const char MINUS = '-';
        static const int NEGATIVE = -1;
        static const int POSITIVE = 1;

        int* numbers;
        int length;
        int sign;

    public:
        LongNumber();
        LongNumber(const char* const str);
        LongNumber(const LongNumber& x);
        LongNumber(LongNumber&& x);

        ~LongNumber();

        LongNumber& operator = (const char* const str);
        LongNumber& operator = (const LongNumber& x);
        LongNumber& operator = (LongNumber&& x);

        bool operator == (const LongNumber& x) const;
        bool operator > (const LongNumber& x) const;
        bool operator < (const LongNumber& x) const;

        LongNumber operator + (const LongNumber& x) const;
        LongNumber operator - (const LongNumber& x) const;
        LongNumber operator * (const LongNumber& x) const;
        LongNumber operator / (const LongNumber& x) const;
        LongNumber operator % (const LongNumber& x) const;

        int get_digits_number() const;
        bool is_positive() const;

        friend std::ostream& operator << (std::ostream &os, const LongNumber& x);

    private:
        int get_length(const char* const str) const;
        LongNumber abs(const LongNumber& x) const;
    };
}
