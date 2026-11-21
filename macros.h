#pragma once

#include <iostream>

#define SQR(x)    ((x) * (x))
#define CUBE(x)   ((x) * (x) * (x))
#define ABS(x)    (((x) < 0) ? -(x) : (x))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define PRINTR(w) std::cout << #w << " = " << (w) << std::endl