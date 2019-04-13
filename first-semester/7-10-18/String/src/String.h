#pragma once

struct String {
    String(char *cstr);

    ~String();

    char &operator[](unsigned int index) const;

    void print() const;

    unsigned int getLength() const;

    String &operator+=(String const &other);

    String &operator=(String const &other);

    String &operator=(char *cstr);

    String &operator+=(char *cstr);

private:
    unsigned int length;
    char *data;
};
