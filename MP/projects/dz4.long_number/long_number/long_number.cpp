#include "long_number.hpp"
#include <cstring>
#include <stdexcept>
#include <algorithm>
#include <string>

using biv::LongNumber;

LongNumber::LongNumber() : numbers(new int[1]{0}), length(1), sign(1) {}

LongNumber::LongNumber(const char* const str) {
    if (str == nullptr) {
        numbers = new int[1]{0};
        length = 1;
        sign = 1;
        return;
    }

    int str_len = get_length(str);
    if (str_len == 0) {
        numbers = new int[1]{0};
        length = 1;
        sign = 1;
        return;
    }

    int start = 0;
    if (str[0] == '-') {
        sign = -1;
        start = 1;
    } else if (str[0] == '+') {
        sign = 1;
        start = 1;
    } else {
        sign = 1;
    }

    while (start < str_len && str[start] == '0') {
        start++;
    }

    if (start == str_len) {
        numbers = new int[1]{0};
        length = 1;
        sign = 1;
        return;
    }

    length = str_len - start;
    numbers = new int[length];
    for (int i = 0; i < length; ++i) {
        char c = str[str_len - 1 - i];
        if (c < '0' || c > '9') {
            int* new_numbers = new int[1]{0};
            delete[] numbers;
            numbers = new_numbers;
            length = 1;
            sign = 1;
            return;
        }
        numbers[i] = c - '0';
    }
}

LongNumber::LongNumber(const LongNumber& x) : length(x.length), sign(x.sign) {
    numbers = new int[length];
    std::copy(x.numbers, x.numbers + length, numbers);
}

LongNumber::LongNumber(LongNumber&& x) noexcept
    : numbers(x.numbers), length(x.length), sign(x.sign) {
    x.numbers = nullptr;
    x.length = 0;
    x.sign = 1;
}

LongNumber::~LongNumber() {
    delete[] numbers;
}

// Операторы присваивания
LongNumber& LongNumber::operator=(const char* const str) {
    LongNumber tmp(str);
    *this = std::move(tmp);
    return *this;
}

LongNumber& LongNumber::operator=(const LongNumber& x) {
    if (this != &x) {
        delete[] numbers;
        length = x.length;
        sign = x.sign;
        numbers = new int[length];
        std::copy(x.numbers, x.numbers + length, numbers);
    }
    return *this;
}

LongNumber& LongNumber::operator=(LongNumber&& x) noexcept {
    if (this != &x) {
        delete[] numbers;
        numbers = x.numbers;
        length = x.length;
        sign = x.sign;
        x.numbers = nullptr;
        x.length = 0;
        x.sign = 1;
    }
    return *this;
}

// Операторы сравнения
bool LongNumber::operator==(const LongNumber& x) const {
    if (sign != x.sign || length != x.length) return false;
    for (int i = 0; i < length; ++i) {
        if (numbers[i] != x.numbers[i]) return false;
    }
    return true;
}

bool LongNumber::operator!=(const LongNumber& x) const {
    return !(*this == x);
}

bool LongNumber::operator>(const LongNumber& x) const {
    if (sign != x.sign) return sign > x.sign;
    bool isPositive = (sign == 1);
    if (length != x.length) return (length > x.length) == isPositive;
    for (int i = length - 1; i >= 0; --i) {
        if (numbers[i] != x.numbers[i])
            return (numbers[i] > x.numbers[i]) == isPositive;
    }
    return false;
}

bool LongNumber::operator<(const LongNumber& x) const {
    if (sign != x.sign) return sign < x.sign;
    bool isPositive = (sign == 1);
    if (length != x.length) return (length < x.length) == isPositive;
    for (int i = length - 1; i >= 0; --i) {
        if (numbers[i] != x.numbers[i])
            return (numbers[i] < x.numbers[i]) == isPositive;
    }
    return false;
}

bool LongNumber::operator>=(const LongNumber& x) const {
    return (*this > x) || (*this == x);
}

LongNumber LongNumber::operator+(const LongNumber& x) const {
    if (sign != x.sign) {
        LongNumber tmp = x;
        tmp.sign = -tmp.sign;
        return *this - tmp;
    }

    int max_len = std::max(length, x.length);
    int* res = new int[max_len + 1]{0};
    int carry = 0;
    int res_len = 0;

    for (int i = 0; i < max_len; ++i) {
        int a = (i < length) ? numbers[i] : 0;
        int b = (i < x.length) ? x.numbers[i] : 0;
        int sum = a + b + carry;
        res[i] = sum % 10;
        carry = sum / 10;
        res_len = i + 1;
    }

    if (carry) {
        res[max_len] = carry;
        res_len = max_len + 1;
    }

    while (res_len > 1 && res[res_len - 1] == 0) res_len--;

    LongNumber result;
    result.numbers = new int[res_len];
    result.length = res_len;
    result.sign = sign;
    std::copy(res, res + res_len, result.numbers);
    delete[] res;
    return result;
}

LongNumber LongNumber::operator-(const LongNumber& x) const {
    if (sign != x.sign) {
        LongNumber tmp = x;
        tmp.sign = -tmp.sign;
        return *this + tmp;
    }

    bool absGreater = (this->abs() >= x.abs());
    if (!absGreater) {
        LongNumber result = x - *this;
        result.sign = -sign;
        return result;
    }

    int* res = new int[length]{0};
    int borrow = 0;
    int res_len = 0;

    for (int i = 0; i < length; ++i) {
        int a = numbers[i];
        int b = (i < x.length) ? x.numbers[i] : 0;
        int diff = a - b - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        res[i] = diff;
        res_len = i + 1;
    }

    while (res_len > 1 && res[res_len - 1] == 0) res_len--;

    LongNumber result;
    result.numbers = new int[res_len];
    result.length = res_len;
    result.sign = sign;
    std::copy(res, res + res_len, result.numbers);
    delete[] res;
    return result;
}

LongNumber LongNumber::operator*(const LongNumber& x) const {
    int total_len = length + x.length;
    int* res = new int[total_len]{0};

    for (int i = 0; i < length; ++i) {
        int carry = 0;
        for (int j = 0; j < x.length; ++j) {
            int prod = numbers[i] * x.numbers[j] + res[i + j] + carry;
            res[i + j] = prod % 10;
            carry = prod / 10;
        }
        if (carry) res[i + x.length] += carry;
    }

    int res_len = total_len;
    while (res_len > 1 && res[res_len - 1] == 0) res_len--;

    LongNumber result;
    result.numbers = new int[res_len];
    result.length = res_len;
    result.sign = sign * x.sign;
    std::copy(res, res + res_len, result.numbers);
    delete[] res;
    return result;
}

LongNumber LongNumber::operator/(const LongNumber& x) const {
    if (x == LongNumber("0")) throw std::invalid_argument("Division by zero");

    LongNumber dividend = abs();
    LongNumber divisor = x.abs();
    if (dividend < divisor) return LongNumber("0");

    LongNumber quotient("0");
    LongNumber current("0");

    for (int i = dividend.length - 1; i >= 0; --i) {
        current = current * LongNumber("10") + LongNumber(std::to_string(dividend.numbers[i]).c_str());
        int cnt = 0;
        while (current >= divisor) {
            current = current - divisor;
            cnt++;
        }
        quotient = quotient * LongNumber("10") + LongNumber(std::to_string(cnt).c_str());
    }

    quotient.sign = sign * x.sign;
    while (quotient.length > 1 && quotient.numbers[quotient.length - 1] == 0) {
        quotient.length--;
    }
    return quotient;
}

LongNumber LongNumber::operator%(const LongNumber& x) const {
    LongNumber quotient = *this / x;
    LongNumber remainder = *this - (quotient * x);
    if (remainder != LongNumber("0")) remainder.sign = sign;
    return remainder;
}

// Вспомогательные методы
int LongNumber::get_digits_number() const noexcept {
    return length;
}

int LongNumber::get_rank_number(int rank) const {
    if (rank < 0 || rank >= length) throw std::out_of_range("Invalid rank");
    return numbers[rank];
}

bool LongNumber::is_negative() const noexcept {
    return sign == -1;
}

int LongNumber::get_length(const char* const str) const noexcept {
    return (str == nullptr) ? 0 : std::strlen(str);
}

LongNumber LongNumber::abs() const {
    LongNumber result(*this);
    result.sign = 1;
    return result;
}

std::ostream& biv::operator<<(std::ostream& os, const LongNumber& x) {
    if (x.is_negative()) os << '-';
    for (int i = x.length - 1; i >= 0; --i) {
        os << x.numbers[i];
    }
    return os;
}
