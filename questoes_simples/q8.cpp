#include <stdio.h>
#include <stdlib.h> 

int main(int argc, char const *argv[])
{
	int i , x;
	scanf("%d", &x);

	for (i = 1; i < x; ++i)
	{
		if(x%i == 0)
			printf("%d ", i);
	}

	printf("%d\n", i);

	
	return 0;
}
