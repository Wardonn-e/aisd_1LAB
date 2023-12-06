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
    Point<int> a1(11, 2);
    cout << a << endl;
    cout << calculate_len(a,a1) << endl;
    
    Point<int> a2(8, 12);
    Point<int> b2(1, 17);
    BrokenLine c2(3, a2, b2);
    cout << c2.len_broken_line() << endl;
}
