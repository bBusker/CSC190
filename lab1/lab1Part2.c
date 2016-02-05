#include "lab1.h"

float S(float a, float b)
{
float m, ans;
m = (a+b)/2.0;
ans = ((b-a)/6.0)*(f(a)+(4.0*f(m))+f(b));
return ans;
}
