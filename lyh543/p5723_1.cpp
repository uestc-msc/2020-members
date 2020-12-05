#include<stdio.h>
#include<math.h>

int main()
{
	int L;
	scanf_s("%d", &L);
	int sum = 0, n = 0;
	for (int i = 2; sum + i <= L; i++)
	{
		bool is_prime = true;
		int sqrt_i = sqrt(i);
		for (int j = 2; j <= sqrt_i; j++)
		{
			if (i % j == 0)
			{
				is_prime = false;
				break;
			}
		}
		if (is_prime)
		{
			sum += i;
			n++;
			printf("%d\n", i);
		}
	}
	printf("%d", n);
}