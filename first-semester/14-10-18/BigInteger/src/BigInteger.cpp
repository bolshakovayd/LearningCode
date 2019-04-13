#include "BigInteger.h"

#include <iostream>
#include <algorithm>

BigInteger::BigInteger(BigInteger const &other) {
    data = other.data;
}

BigInteger::BigInteger(std::vector<char> vec) {
    if (vec.empty()) {
        data.push_back(0);
    } else {
        data = vec;
    }
}

BigInteger::BigInteger(std::string str) {
    if (str.empty()) {
        data.push_back(0);
    } else {
        for (int i = (int) str.length() - 1; i >= 0; --i) {
            data.push_back(str[i] - 48);
        }
    }
    normalize();
}

BigInteger::BigInteger(long long n) {
    if (!n) {
        data.push_back(0);
    } else {
        std::string str = std::to_string(n);
        for (int i = (int) str.length() - 1; i >= 0; --i) {
            data.push_back(str[i] - 48);
        }
    }
    normalize();
}

BigInteger::BigInteger() = default;

void BigInteger::print() const {
    std::cout << std::endl;
    if (data.empty()) {
        std::cout << 0;
    } else {
        for (int i = (int) data.size() - 1; i >= 0; --i) {
            std::cout << char(data[i] + 48);
        }
    }
}

void BigInteger::normalize() {
    if (data.empty()) {
        data.push_back(0);
    } else {
        while (data.size() > 1 && data.back() == 0)
            data.pop_back();
    }
}

bool BigInteger::operator==(BigInteger const &other) const {
    if (data.empty() || other.data.empty()) {
        return false;
    }
    if (data.size() != other.data.size()) {
        return false;
    }
    for (auto i = 0; i < data.size(); ++i) {
        if (data[i] != other.data[i]) {
            return false;
        }
    }
    return true;
}

BigInteger &BigInteger::operator=(BigInteger const &other) {
    if (this != &other) {
        data = other.data;
    }
    normalize();
    return *this;
}

BigInteger &BigInteger::operator+=(BigInteger const &other) {
    int carry = 0;
    for (auto i = 0; i < std::max(data.size(), other.data.size()) || carry; ++i) {
        if (i == data.size()) {
            data.push_back(0);
        }
        data[i] += carry + (i < other.data.size() ? other.data[i] : 0);
        carry = data[i] >= 10;
        if (carry) {
            data[i] -= 10;
        }
    }
    normalize();
    return *this;
}

BigInteger &BigInteger::operator-=(BigInteger const &other) {
    int carry = 0;
    for (size_t i = 0; i < other.data.size() || carry; ++i) {
        data[i] -= carry + (i < other.data.size() ? other.data[i] : 0);
        carry = data[i] < 0;
        if (carry) data[i] += 10;
    }
    normalize();
    return *this;
}

BigInteger &BigInteger::operator*=(BigInteger const &other) {
    BigInteger temp;
    temp.data = std::vector<char>(data.size() + other.data.size(), 0);
    for (auto i = 0; i < data.size(); ++i) {
        for (int j = 0, carry = 0; j < (int) other.data.size() || carry; ++j) {
            long long cur =
                    temp.data[i + j] + data[i] * 1ll * (j < (int) other.data.size() ? other.data[j] : 0) + carry;
            temp.data[i + j] = char(cur % 10);
            carry = int(cur / 10);
        }
    }
    temp.normalize();
    *this = temp;
    return *this;
}

BigInteger operator+(BigInteger const &a, BigInteger const &b) {
    BigInteger temp = a;
    int carry = 0;
    for (auto i = 0; i < std::max(temp.data.size(), b.data.size()) || carry; ++i) {
        if (i == temp.data.size()) {
            temp.data.push_back(0);
        }
        temp.data[i] += carry + (i < b.data.size() ? b.data[i] : 0);
        carry = temp.data[i] >= 10;
        if (carry) {
            temp.data[i] -= 10;
        }
    }
    temp.normalize();
    return temp;
}

BigInteger operator-(BigInteger const &a, BigInteger const &b) {
    BigInteger temp = a;
    int carry = 0;
    for (auto i = 0; i < b.data.size() || carry; ++i) {
        temp.data[i] -= carry + (i < b.data.size() ? b.data[i] : 0);
        carry = temp.data[i] < 0;
        if (carry) {
            temp.data[i] += 10;
        }
    }
    temp.normalize();
    return temp;
}

BigInteger operator*(BigInteger const &a, BigInteger const &b) {
    BigInteger temp;
    temp.data = std::vector<char>(a.data.size() + b.data.size(), 0);
    for (auto i = 0; i < a.data.size(); ++i) {
        for (int j = 0, carry = 0; j < (int) b.data.size() || carry; ++j) {
            long long cur = temp.data[i + j] + a.data[i] * 1ll * (j < (int) b.data.size() ? b.data[j] : 0) + carry;
            temp.data[i + j] = char(cur % 10);
            carry = int(cur / 10);
        }
    }
    temp.normalize();
    return temp;
}

BigInteger karatsubaMultiplication(BigInteger const &a, BigInteger const &b) {
    BigInteger maxArg;
    BigInteger minArg;
    if (a.data.size() > b.data.size()) {
        maxArg = a;
        minArg = b;
    } else {
        maxArg = b;
        minArg = a;
    }
    unsigned long minLen = minArg.data.size();
    unsigned long maxLen = maxArg.data.size();

    // trivial case
    if (minLen < 4 || maxLen < 4) {
        BigInteger res(a * b);
        res.normalize();
        return res;
    }

    unsigned long halfLength = (maxLen % 2 == 0 ? maxLen / 2 : (maxLen + 1) / 2);

    // split numbers into 3
    if (minLen <= halfLength) { // length of a is less then half of b
        BigInteger maxArg1;
        for (auto i = 0; i < halfLength; ++i) {
            maxArg1.data.push_back(maxArg.data[i]);
        }
        BigInteger maxArg2;
        for (auto i = halfLength; i < maxArg.data.size(); ++i) {
            maxArg2.data.push_back(maxArg.data[i]);
        }

        BigInteger q = karatsubaMultiplication(minArg, maxArg1);
        BigInteger p = karatsubaMultiplication(minArg, maxArg2);
        for (auto i = 0; i < halfLength; ++i) { // ~ * 10^halfLength
            p.data.insert(p.data.begin(), 0);
        }
        BigInteger res(q + p);
        res.normalize();
        return res;
    } else {        // split numbers into 4
        BigInteger maxArg1;
        for (auto i = 0; i < halfLength; ++i) {
            maxArg1.data.push_back(maxArg.data[i]);
        }
        BigInteger maxArg2;
        for (auto i = halfLength; i < maxArg.data.size(); ++i) {
            maxArg2.data.push_back(maxArg.data[i]);
        }
        BigInteger minArg1;
        for (auto i = 0; i < halfLength; ++i) {
            minArg1.data.push_back(minArg.data[i]);
        }
        BigInteger minArg2;
        for (auto i = halfLength; i < minArg.data.size(); ++i) {
            minArg2.data.push_back(minArg.data[i]);
        }
        BigInteger q = karatsubaMultiplication(minArg1, maxArg1);
        BigInteger p = karatsubaMultiplication(minArg2, maxArg2);
        BigInteger g = karatsubaMultiplication(minArg1 + minArg2, maxArg1 + maxArg2);
        g -= (p + q);
        for (auto i = 0; i < halfLength * 2; ++i) { // * 10^(halfLength * 2)
            p.data.insert(p.data.begin(), 0);
        }
        for (auto i = 0; i < halfLength; ++i) { // * 10^halfLength
            g.data.insert(g.data.begin(), 0);
        }
        BigInteger res(q + p + g);
        res.normalize();
        return res;
    }
}
