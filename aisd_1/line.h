//
//  line.h
//  aisd_1
//
//  Created by Роман Казаев on 05.12.2023.
//

#ifndef line_h
#define line_h

#pragma once
#include <iostream>
#include <random>
#include <complex>
#include <cmath>

using namespace std;

namespace line {
    template<typename T>
    struct Point {
        T _x;
        T _y;
        Point() : _x(T(0)), _y(T(0)) {}
        Point(T x, T y) : _x(x), _y(y) {}
        Point(std::complex<T> x, std::complex<T> y) : _x(x), _y(y) {}
        void operator = (const Point<T>& a) {
            _x = a._x;
            _y = a._y;
        }
        bool operator==(const Point<T>& a) {
            return ((_x == a._x) && (_y == a._y));
        }
        bool operator!=(const Point<T>& a) {
            return !(* this == a);
        }
    };
    template<typename U>
    double calculate_len(Point<complex<U>>& a, Point<complex<U>>& b) {
        return fabs(sqrt(pow(a._x.real() - b._x.real(), 2) + pow(a._y.real() - b._y.real(), 2)));
    }
    template<typename T>
    double calculate_len(Point<T>& a, Point<T>& b) {
        return sqrt(pow(a._x - b._x, 2) + pow(a._y - b._y, 2));
    }
    template<typename T>
    std::ostream& operator<<(std::ostream& os, const Point<T>& a) {
        os << "X: " << a._x << " Y: " << a._y << std::endl;
        return os;
    }
    template<typename T>
    T random(T x1, T x2) {
        std::random_device random_device;
        std::mt19937 generator(random_device());
        std::uniform_int_distribution<> distribution(x1, x2);
        T x = distribution(generator);
        return x;
    }
    template<typename T>
    complex<T> random(complex<T> m1, complex<T> m2) {
        std::random_device random_device;
        std::mt19937 generator(random_device());
        std::uniform_real_distribution<> real_distribution(m1.real(), m2.real());
        std::uniform_real_distribution<> imag_distribution(m1.imag(), m2.imag());

        T real_part = real_distribution(generator);
        T imag_part = imag_distribution(generator);

        return complex<T>(real_part, imag_part);
    }


    template<typename T>
    class BrokenLine {
    private:
        Point<T>* _data;
        size_t _size;
        const double eps = 0.000001;
    public:
        BrokenLine() : _data(nullptr), _size(0) {}
        
        
        BrokenLine(Point<T>& other) : _data(new Point<T>), _size(1) {
            _data[0] = Point<T>(other._x, other._y);
        }
        BrokenLine(size_t size) : _data(new Point<T>[size]), _size(size) {
            for (size_t i = 0; i < _size; i++) {
                _data[i] = Point<T>();
            }
        }
        BrokenLine(size_t count, Point<T> m1, Point<T> m2) : _data(new Point<T>[count]), _size(count) {
            for (size_t i = 0; i < _size; i++) {
                _data[i] = Point<T>(random(m1._x, m2._x), random(m1._y, m2._y));
            }
        }
        BrokenLine(const BrokenLine<T>& a) : _data(new Point<T>[a._size]), _size(a._size) {
            for (size_t i = 0; i < _size; i++) {
                _data[i] = a[i];
            }
        }
        BrokenLine(size_t count, Point<complex<T>> m1, Point<complex<T>> m2) : _data(new Point<complex<T>>[count]), _size(count) {
            for (size_t i = 0; i < _size; i++) {
                _data[i] = Point<complex<T>>(random(m1._x, m2._x), random(m1._y, m2._y));
            }
        }

        void swap(BrokenLine<T>& a) {
            std::swap(_data, a._data);
            std::swap(_size, a._size);
        }
        BrokenLine operator=(BrokenLine<T> a) {
            swap(a);
            return *this;
        }
        size_t size() {
            return _size;
        }
        Point<T>& operator[](size_t index) const {
            if (index >= _size) {
                throw("all bad");
            }
            return _data[index];
        }
        BrokenLine operator+(const BrokenLine& temp) {
            BrokenLine<T> result;
            result._size = _size + temp._size;
            result._data = new Point<T>[result._size];
            for (size_t i = 0; i < _size; i++) {
                result._data[i] = _data[i];
            }
            for (size_t i = 0; i < temp._size; i++) {
                result._data[_size + i] = temp._data[i];
            }
            return result;
        }
        void push_back(const Point<T>& a) {
            Point<T>* data = new Point<T>[_size+1];
            for (size_t i = 0; i < _size; i++) {
                data[i] = _data[i];
            }
            data[_size] = a;
            delete[] _data;
            _data = data;
            _size++;
        }
        void push_front(const Point<T>& a) {
            Point<T>* data = new Point<T>[_size + 1];
            data[0] = a;
            for (size_t i = 1; i < _size; i++) {
                data[i] = _data[i-1];
            }
            delete[] _data;
            _data = data;
            _size++;
        }
        ~BrokenLine() {
            delete[] _data;
            _data = nullptr;
            _size = 0;
        }
        double len_broken_line() {
            double lenght = 0;
            for (size_t i = 1; i < _size; i++)
            {
                lenght += calculate_len(_data[i], _data[i - 1]);
            }
            return lenght;
        }
        bool operator==(const BrokenLine<T>& a) const {
            if (_size != a._size)
                return false;
            
            for (int i = 0; i < _size; ++i) {
                if (abs(_data[i]._x - a[i]._x) > eps || abs(_data[i]._y - a[i]._y) > eps)
                    return false;
            }

            return true;
        }

        bool operator!=(const BrokenLine<T>& a) const {
            return !(_data == a);
        }

    };
    template<typename T>
    std::ostream& operator<<(std::ostream& os, BrokenLine<T>& a) {
        for (size_t i = 0; i < a.size(); i++) {
            os << a[i] << endl;
        }
        return os;
    }
    template<typename T>
    void task1(T a, T b, T h) {
        BrokenLine<T> line;
        Point<T> A;
        Point<T> B(a, 0);
        Point<T> C(h, b);
        Point<T> D(0, h);
        line.push_back(A);
        line.push_back(B);
        line.push_back(C);
        line.push_back(D);
        line.push_back(A);
        cout << line << endl;
    }
}
#endif /* line_h */
