#include <cstdio>
#include <cstring>
#include <cstdlib>

int A[] = {1,1,2,6,4,2,2,4,2,8,8,8,6,8,2,8,8,6,8,2};
int func(char*,int);

int main()
{
	int i,j,k,l,m,n,len;
	char ch, *str;
	str = (char*)malloc(sizeof(char)*210);

	while(scanf("%s",str) != EOF)
	{
	//	printf("%s\n",str);
		len = strlen(str);
		if(len == 1)
		{
			n = A[str[0] - '0'];
		}
		else
			n = func(str,len);
		printf("%d\n",n);
	}
	return 0;
}

int func(char *str, int len)
{
//	printf("str = %s\n",str);
//	printf("len = %d\n",len);
	if(len == 2)
	{
		int yogi,numb;
		numb = atoi(str);
		numb = numb/5;
		if((str[len-2]-'0') % 2 == 0)
			yogi = 6*A[numb]*A[str[len-1] - '0'];
		else
			yogi = 4*A[numb]*A[str[len-1] - '0'];
		numb = yogi % 10;
		while(numb == 0)
		{
			yogi = yogi / 10;
			numb = yogi % 10;
		}
	//	printf("numb = %d\n",numb);
		return numb;
	}
	else
	{
		int i,num,j,n;
		char *str1;
		str1 = (char*)malloc(sizeof(char)*110);
		j=0;
		num = 0;
		i=0;
		while(i < len)
		{
			num = (num * 10) + (str[i++] - '0');

			while(num < 5 && i < len)
			{
				str1[j++] = '0';
				num  = (num * 10) + (str[i++] - '0');
			}
			str1[j++] = (num / 5) + '0';
			num = num % 5;
		}
		str1[j] = '\0';

		i=0;
		while(str1[i] == '0')
		{
			str1++;
			j--;
		}
	//	printf("str1 = %s\n",str1);
		n = func(str1,j);

		int yogi,numb;
	//	numb = atoi(str);
	//	numb = numb/5;
		if((str[len-2]-'0') % 2 == 0)
			yogi = 6*n*A[str[len-1] - '0'];
		else
			yogi = 4*n*A[str[len-1] - '0'];
		numb = yogi % 10;
		while(numb == 0)
		{
			yogi = yogi / 10;
			numb = yogi % 10;
		}
	//	printf("numb = %d\n",numb);
		return numb;
	}
}
