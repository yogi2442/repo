#include <stdio.h>

int main()
{
	printf("50000\n\n");
	int i,j;
	int c[4] = {50000,50000,50000,50000};
	char ch[4];
	ch[0] = 'A';
	ch[1] = 'B';
	ch[2] = 'C';
	ch[3] = 'D';
	int count=0;
	while(1)
	{
		j = rand()%4;
		if(c[j] > 0)
		{
			count++;
			printf("%c",ch[j]);
			c[j]--;
		}
		if(count == 100000)
			break;
	}
	printf("\n");
	return 0;
}
