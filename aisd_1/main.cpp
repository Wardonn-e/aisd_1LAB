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

int main(int argc, const char * argv[]) {
    Point<int> a(1, 2);
    Point<int> b(8, 10);
    BrokenLine c (3, a, b);
    cout << c <<endl;
    Point<int> a1(8, 12);
    Point<int> b1(1, 17);
    BrokenLine c1(3, a, b);
    cout << c1.len_broken_line() << endl;
    auto itog = c + c1;
    cout << itog;
    cout << endl << endl;
    task1<int>(7, 4, 4);

    return 0;
}
