#include <cstdio>
#include <cstdlib>
#include <cstring>

int main()
{
	int i,j,k,l,m,n,t,u,num,num1,len,len1;
	char str[3000],str1[3000];
	scanf("%d",&t);
	for(u=0;u<t;u++)
	{
		scanf("%d%s%d%s",&n,str,&m,str1);
	//	printf("%d %s %d %s\n",n,str,m,str1);
		len = strlen(str);
		num = str[len-1] - '0';
		if(n == 1 && strcmp(str,"1") == 0)
		{
			printf("Impossible.\n");
			continue;
		}
		if(n % 2 == 1 && num % 2 == 1)
		{
			m = m % 2;
			len1 = strlen(str1);
			num1 = str1[len1 - 1] - '0';
			num1 = num1 % 2;
			if(m == 0)
			{
				if(num1 == 0)
					printf("Possible.\n");
				else
					printf("Impossible.\n");
			}
			else
			{
				if(num1 == 1)
					printf("Possible.\n");
				else
					printf("Impossible.\n");

			}
		}
		else
			printf("Impossible.\n");
	}
	return 0;
}

