#include "../include/three.h"
#include <iostream> 

Three::Three() : digits(1, '0') {}

Three::Three(const size_t &n, const unsigned char t = '0') : digits(n, t) {}

Three::Three(const std::initializer_list<unsigned char> &t) : digits(t) {}

Three::Three(const std::string &t) {
    for(int i = 0; i < t.size(); ++i) {
        digits.push_back(t[i]);
    }
}

Three::Three(const Three& other) : digits(other.digits) {}

Three::Three(Three&& other) : digits(std::move(other.digits)) {}

Three Three::operator+(const Three& other) const {
    Three result(*this);
    result += other;
    return result;
}

Three Three::operator-(const Three& other) const {
    Three result(*this);
    result -= other;
    return result;
}

Three& Three::operator=(const Three& other){
    digits = other.digits;
    return *this;
}

bool Three::operator>(const Three& other) const {
    if (digits.size() > other.digits.size()) {
        return true; 
    } else if (digits.size() < other.digits.size()) {
        return false; 
    }

    for (int i = digits.size() - 1; i >= 0; --i) {
        if (digits[i] > other.digits[i]) {
            return true; 
        } else if (digits[i] < other.digits[i]) {
            return false; 
        }
    }
    return false;
}

bool Three::operator<(const Three& other) const {
    if (digits.size() < other.digits.size()) {
        return true; 
    } else if (digits.size() > other.digits.size()) {
        return false; 
    }

    for (int i = digits.size() - 1; i >= 0; --i) {
        if (digits[i] < other.digits[i]) {
            return true; 
        } else if (digits[i] > other.digits[i]) {
            return false; 
        }
    }
    return false;
}

bool Three::operator==(const Three& other) const {
    if (digits.size() == other.digits.size()){
        for(int i = 0; i < digits.size(); ++i){
            if (digits[i] != other.digits[i])
                return false;
        }
        return true;
    }
    return false;
}

Three& Three::operator+=(const Three& other) {
    if (other.digits.size() > digits.size()) {
        for(int i = 0; i < (other.digits.size() - digits.size()); ++i)
            digits.push_back('0');
    }
    int remains = 0;
    int other_digit, sum;
    for(int i = 0; i < digits.size(); ++i) {
        other_digit = (i < other.digits.size() ? other.digits[i] - '0' : 0);
        sum = (digits[i] - '0') + other_digit + remains;
        remains = (sum > 2 ? 1 : 0);
        digits[i] = (sum % 3) + '0';
    }
    if (remains > 0) digits.push_back('1');
    return *this;
}

Three& Three::operator-=(const Three& other) {
    if (other.digits.size() > digits.size()) {
        for(int i = 0; i < (other.digits.size() - digits.size()); ++i)
            digits.push_back('0');
    }
    int remains = 0;
    int dif, other_digit;
    for(int i = 0; i < digits.size(); ++i) {
        other_digit = (i < other.digits.size() ? other.digits[i] - '0' : 0);
        if ((digits[i] - '0') - other_digit + remains >= 0) {
            dif = (digits[i] - '0') - other_digit + remains;
            remains = 0;
        } else {
            dif = (digits[i] - '0') + 3 - other_digit + remains;
            remains = -1;
        }
        digits[i] = dif + '0';
    }
    return *this;
}

Three::~Three() noexcept {}
