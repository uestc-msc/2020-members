#include<stdio.h>
#include<math.h>

const int max_size = 1e6;

int main()
{
	bool is_not_prime[max_size] = { 0 };
	int L;
	scanf_s("%d", &L);
	int sum = 0, n = 0;
	for (int i = 2; sum + i <= L; i++)
	{
		if (is_not_prime[i])
			continue;
		for (int j = 2; i * j < max_size; j++)
			is_not_prime[i * j] = 1;
		sum += i;
		n++;
		printf("%d\n", i);
	}
	printf("%d", n);
}