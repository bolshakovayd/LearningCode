#pragma once

#include <vector>
#include <string>

struct LongNumber {
    LongNumber(LongNumber & other);

    explicit LongNumber(std::string str);

    void print();

    LongNumber &operator=(LongNumber &number);

    LongNumber operator+(LongNumber &number);

    LongNumber operator-(LongNumber &number);

    bool operator==(LongNumber &number);

    std::vector<int> data;
};
