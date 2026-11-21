#include <iostream>
#include "macros.h"
using namespace std;

#define Z 12           

int main()
{
    double x, y;      
    double w;         

    cout << "Variant 8. z = " << Z << endl;
    cout << "x = "; cin >> x;
    cout << "y = "; cin >> y;

#if Z > 10
    w = MAX(CUBE(x), SQR(x + y));
#else
    w = MIN(ABS(x - Z), ABS(x + Z));
#endif

    PRINTR(w);

    return 0;
}