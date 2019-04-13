#include "String.h"

#include <iostream>
#include <cstring>

String::String(char *cstr) : length(static_cast<unsigned int>(strlen(cstr))) {
    data = new char[length];
    for (auto i = 0; i < length; ++i) {
        data[i] = cstr[i];
    }
}

String::~String() {
    delete[] data;
}

void String::print() const {
    std::cout << std::endl;
    for (auto i = 0; i < length; ++i) {
        std::cout << data[i];
    }
}

char &String::operator[](unsigned int index) const {
    return data[index];
}

unsigned int String::getLength() const {
    return length;
}

String &String::operator+=(String const &other) {

    unsigned int tlength = length + other.getLength();
    char *tdata = new char[tlength];

    for (auto i = 0; i < length; ++i) {
        tdata[i] = data[i];
    }

    for (auto i = length; i < tlength; ++i) {
        tdata[i] = other[i - length];
    }
    data = tdata;
    length = tlength;

    return *this;
}

String &String::operator+=(char *cstr) {
    unsigned int cstrSize = static_cast<unsigned int>(strlen(cstr));
    unsigned int tlength = length + cstrSize;
    char *tdata = new char[tlength];

    for (auto i = 0; i < length; ++i) {
        tdata[i] = data[i];
    }

    for (auto i = length; i < tlength; ++i) {
        tdata[i] = cstr[i - length];
    }
    data = tdata;
    length = tlength;

    return *this;
}

String &String::operator=(String const &other) {
    delete[] data;
    length = other.getLength();
    data = other.data;
    return *this;
}

String &String::operator=(char *cstr) {
    delete[] data;
    length = static_cast<unsigned int>(strlen(cstr));
    data = new char[length];
    for (auto i = 0; i < length; ++i) {
        data[i] = cstr[i];
    }
    return *this;
}
