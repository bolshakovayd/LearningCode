#pragma once

struct AugmentedMatrix {
    explicit AugmentedMatrix(unsigned int rows, unsigned int cols);

    ~AugmentedMatrix();

    void print();

    void printAll();

    unsigned int getSize();

    unsigned int getCols();

    unsigned int getRows();

    double **data;
private:
    unsigned int size;
    unsigned int rows;
    unsigned int cols;
};
