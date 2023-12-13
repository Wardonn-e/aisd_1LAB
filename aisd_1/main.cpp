//
//  main.cpp
//  aisd_1
//
//  Created by Роман Казаев on 05.12.2023.
//

#include <iostream>
#include "line.h"
using namespace std;
using namespace line;


int main() {
    // Тестирование конструктора с одной точкой
    Point<complex<double>> complexPoint(1.0, -2.0);
    BrokenLine<complex<double>> lineSingle(complexPoint);
    cout << "Конструктор с одной точкой:\n" << lineSingle << endl;
    
    // Тестирование конструктора с указанным числом точек
    BrokenLine<double> lineCount(5);
    cout << "Конструктор с указанным числом точек:\n" << lineCount << endl;
    
    // Тестирование конструктора с указанным диапазоном и числом точек
    Point<double> m1(0.0, 0.0);
    Point<double> m2(10.0, 10.0);
    BrokenLine<double> lineRange(3, m1, m2);
    cout << "Конструктор с указанным диапазоном и числом точек:\n" << lineRange << endl;
    
    // Тестирование оператора [] для чтения/записи вершины по индексу
    cout << "Чтение и запись вершины по индексу:\n";
    lineRange[0] = Point<double>(-1.0, -1.0);
    cout << lineRange << endl;
    
    // Тестирование оператора конкатенации
    cout << "Конкатенация двух ломаных:\n";
    BrokenLine<double> concatenatedLine = lineRange + lineCount;
    cout << concatenatedLine << endl;
    
    // Тестирование оператора добавления точки в конец ломаной
    cout << "Добавление точки в конец ломаной:\n";
    Point<double> newPoint(15.0, 15.0);
    concatenatedLine.push_back(newPoint);
    cout << concatenatedLine << endl;
    
    // Тестирование оператора добавления точки в начало ломаной
    cout << "Добавление точки в начало ломаной:\n";
    concatenatedLine.push_front(Point<double>(-5.0, -5.0));
    cout << concatenatedLine << endl;
    
    // Тестирование вычисления длины ломаной
    cout << "Длина ломаной: " << concatenatedLine.len_broken_line() << endl;
    
    
    line::BrokenLine<complex<double>> line1;
    line::BrokenLine<complex<double>> line2;

    line1.push_back({1.0, 2.0});
    line1.push_back({2.0, 3.0});
    line1.push_back({3.0, 4.0});

    line2.push_back({4.0, 5.0});
    line2.push_back({5.0, 6.0});

    line::BrokenLine<complex<double>> resultLine = line1 + line2;

    cout << "Ломаная 1:\n" << line1 << endl;
    cout << "Ломаная 2:\n" << line2 << endl;
    cout << "Результат конкатенации:\n" << resultLine << endl;
    

    int a = 3;
    int b = 6;
    int h = 4;
    
    cout << "Ломаная в виде прямоугольной трапеции:\n";
    task1(a, b, h);
    
    return 0;
}

