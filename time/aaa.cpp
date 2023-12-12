#include <stdio.h>
int main()
{
	int i = 785;
	float f = 1.5678E3;
	double d = 1.5e100;
	if (i == (int)(float)i)
		printf("1\n");
	if (f == (float)(int)f)
		printf("2\n");
	if (f == (float)(double)f)
		printf("3\n");
	if ((d + f) - d == f)
		printf("4\n");
	printf("%lf\n",d+f);
	printf("%lf\n",d+f-d);
	printf("%lf\n",(d+f)-d);
	printf("%lf\n",f);
	return 0;
}