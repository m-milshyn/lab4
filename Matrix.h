#pragma once
#include "Vector.h"
#include <iostream>

using namespace std;

class Matrix {
private:
    int rows;
    int cols;
    double** data;

public:
    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        data = new double* [rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new double[cols];
            for (int j = 0; j < cols; j++) {
                data[i][j] = 0;
            }
        }
    }

    ~Matrix() {
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;
    }

    double& operator()(int row, int col) {
        return data[row][col];
    }

    const double& operator()(int row, int col) const {
        return data[row][col];
    }

    int getRows() const {
        return rows;
    }

    int getCols() const {
        return cols;
    }

    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
        for (int i = 0; i < matrix.getRows(); i++) {
            for (int j = 0; j < matrix.getCols(); j++) {
                os << matrix(i, j) << " ";
            }
            os << std::endl;
        }
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Matrix& matrix) {
        for (int i = 0; i < matrix.getRows(); i++) {
            for (int j = 0; j < matrix.getCols(); j++) {
                is >> matrix(i, j);
            }
        }
        return is;
    }

    Matrix operator*(const Vector& vec) {
        if (cols != vec.getSize()) {
            throw std::invalid_argument("Invalid size");
        }

        Matrix result(rows, 1);

        for (int i = 0; i < rows; i++) {
            double sum = 0;
            for (int j = 0; j < cols; j++) {
                sum += data[i][j] * vec[j];
            }
            result(i, 0) = sum;
        }

        return result;
    }
};
