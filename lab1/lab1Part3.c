#include "lab1.h"

void simpsonsAdaptiveIntegration(float aOrig, float bOrig, float eps, float minIntSize)
{
	double sum, a, b, m;
	sum = 0;
	a = aOrig;
	b = bOrig;

	while(a != bOrig) 
	{
		b = bOrig;
		m = (a + b)/2;
		while(fabs(S(a,m) + S(m,b) - S(a,b))/15 >= eps && (b - a) >= minIntSize) 
		{
			b = m;
			m = (a + b)/2;
		}

		sum += S(a, b);
		a = b;
	}
	
	printf("%f\n",sum);
}
