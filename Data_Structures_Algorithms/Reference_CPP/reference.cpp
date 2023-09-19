//
// Created by CentralCommand on 12/29/2022.
//

#include "reference.h"

int main() {
    int a = 10;

    // variable 'r' references (&) the value of variable 'a' in address of variable r
    int &r = a;

    // variable 'b' is an assignment variable
    int b = a;
    cout << a << endl << r;

    return 0;
}