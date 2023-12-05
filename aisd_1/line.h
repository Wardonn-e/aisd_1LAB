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
}
#endif /* line_h */
