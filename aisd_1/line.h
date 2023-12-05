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
#include<complex>
#include <cmath>

using namespace std;

namespace line {
    template<typename T>
    struct Point {
        T _x;
        T _y;
        Point() : _x(T(0)), _y(T(0)) {}
        Point(T x, T y) : _x(x), _y(y) {}
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
        return fabs(sqrt(pow(a.get_x().real() - b.get_x().real(), 2) + pow(a.get_y().real() - b.get_y().real(), 2)));
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
    };
}
#endif /* line_h */
