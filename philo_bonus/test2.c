#include <stdio.h>
int main()
{
	int	b;
	int a;
	int c;

	c = 'a';
	a = 0;
	for (int i = 0; i < 8; i++)
	{
		b = (c >> i) & 1;
		printf("%d\n", b);
	}
}
