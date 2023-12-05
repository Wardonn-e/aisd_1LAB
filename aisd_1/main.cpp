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
}
