#pragma once
#include "Matrix.h"


class Vector {
private:
    int size_;
    double* vec;
public:
    Vector(int size = 0) : size_(size), vec(new double[size_]) {}

    Vector(const Vector& other) : size_(other.size_), vec(new double[size_]) {
        for (int i = 0; i < size_; i++) {
            vec[i] = other.vec[i];
        }
    }

    ~Vector() {
        delete[] vec;
    }

    int getSize() const {
        return size_;
    }

    double& operator[](int i) {
        return vec[i];
    }

    const double& operator[](int i) const {
        return vec[i];
    }

    Vector& operator=(const Vector& other) {
        if (this != &other) {
            delete[] vec;
            size_ = other.size_;
            vec = new double[size_];
            for (int i = 0; i < size_; i++) {
                vec[i] = other.vec[i];
            }
        }
        return *this;
    }

    Vector& operator+=(const Vector& other) {
        if (size_ == other.size_) {
            for (int i = 0; i < size_; i++) {
                vec[i] += other.vec[i];
            }
        }
        return *this;
    }

    friend Vector operator+(Vector lhs, const Vector& rhs) {
        lhs += rhs;
        return lhs;
    }

    Vector& operator-=(const Vector& other) {
        if (size_ == other.size_) {
            for (int i = 0; i < size_; i++) {
                vec[i] -= other.vec[i];
            }
        }
        return *this;
    }

    friend Vector operator-(Vector lhs, const Vector& rhs) {
        lhs -= rhs;
        return lhs;
    }

    Vector& operator*=(double scalar) {
        for (int i = 0; i < size_; i++) {
            vec[i] *= scalar;
        }
        return *this;
    }

    friend Vector operator*(Vector vector, double scalar) {
        vector *= scalar;
        return vector;
    }

    friend Vector operator*(double scalar, Vector vector) {
        return vector * scalar;
    }

    friend std::ostream& operator<<(std::ostream& os, const Vector& vector) {
        os << "[";
        for (int i = 0; i < vector.getSize() - 1; i++) {
            os << vector[i] << ", ";
        }
        os << vector[vector.getSize() - 1] << "]";
        return os;
    }
};