#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>

int main()
{
	int i,j,k,l,A[11],flag,len,count,num;
	long long n,m;
	char str[300][15][2],str1[300];
	while(scanf("%lld%s",&n,str1) != EOF)
	{

		len = strlen(str1);
		if(len <= 2)
		{
			printf("%s\n",str1);
			continue;
		}

		for(i=0;i<300;i++)
		{
			for(j=0;j<15;j++)
			{
				str[i][j][0] = 42;
				str[i][j][1] = 42;
			}
		}
		
		flag = 0;
		for(i=0;i<10;i++)
			A[i]=0;
		m = n;
		i=0;
		while(n>0)
		{
			A[n%10] = ++i;
			n = n/10;
		}
		count = i;
		if(i%2 != 0)
		{
			//  odd columns;
			flag=1;
		}
		num=2;
		i=0;
		for(k=1;;k++)
		{
			if(i >= len)
				break;
			for(j=1;j<=count;j++)
			{
				if(num == 2 && i < len)
				{
					str[k][j][0] = str1[i++];
					if(i <  len)
						str[k][j][1] = str1[i++];
					num = 1;
				}
				else if(num == 1 && i < len)
				{
					str[k][j][0] = str1[i++];
					num = 2;
				}
				if(j == count && flag == 0)
				{
					if(num == 1)
						num = 2;
					else
						num = 1;
				}
				if(i >= len)
					break;
			}
			if(i >= len)
				break;
		}

		for(i=1;i<=count;i++)
		{
			j = count - A[i] + 1;
			k=1;
			while(str[k][j][0] >= 65 && str[k][j][0] <= 90)
			{
				printf("%c",str[k][j][0]);
				if(str[k][j][1] >= 65 && str[k][j][1] <= 90)
					printf("%c",str[k][j][1]);
				k++;
			}
		}
		printf("\n");

	}
	return 0;
}
