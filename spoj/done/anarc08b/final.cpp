#include <cstdio>
#include <iostream>

char A[10][3];
void func(long long);


int main()
{
	
	A[0][0] = '0';
	A[0][1] = '6';
	A[0][2] = '3';
	
	A[1][0] = '0';
	A[1][1] = '1';
	A[1][2] = '0';
	
	A[2][0] = '0';
	A[2][1] = '9';
	A[2][2] = '3';

	A[3][0] = '0';
	A[3][1] = '7';
	A[3][2] = '9';

	A[4][0] = '1';
	A[4][1] = '0';
	A[4][2] = '6';

	A[5][0] = '1';
	A[5][1] = '0';
	A[5][2] = '3';

	A[6][0] = '1';
	A[6][1] = '1';
	A[6][2] = '9';

	A[7][0] = '0';
	A[7][1] = '1';
	A[7][2] = '1';

	A[8][0] = '1';
	A[8][1] = '2';
	A[8][2] = '7';

	A[9][0] = '1';
	A[9][1] = '0';
	A[9][2] = '7';

	char str1[40],str2[40],ch;
	int len1,len2,i,j,l,k,m,n;

	long long num1,num2,num3;;
	scanf("%c",&ch);

	while(ch != 'B')
	{
		i=0;
		while(ch != '+')
		{
			str1[i++] = ch;
			scanf("%c",&ch);
		}
		len1 = i;

		j=0;
		scanf("%c",&ch);
		while(ch != '=')
		{
			str2[j++] = ch;
			scanf("%c",&ch);
		}
		len2 = j;

		num1 = 0;
		num2 = 0;

		for(i=0;i<len1;i=i+3)
		{
			printf("%c%c%c",str1[i],str1[i+1],str1[i+2]);
			for(j=0;j<10;j++)
			{
				if(str1[i] == A[j][0] && str1[i+1] == A[j][1] && str1[i+2] == A[j][2])
					break;
			}
			num1 = num1*10 + j;
		}
//		printf("num1 = %lld\n",num1);
		printf("+");
		for(i=0;i<len2;i=i+3)
		{
			printf("%c%c%c",str2[i],str2[i+1],str2[i+2]);
			for(j=0;j<10;j++)
			{
				if(str2[i] == A[j][0] && str2[i+1] == A[j][1] && str2[i+2] == A[j][2])
					break;
			}
			num2 = num2*10 + j;
		}
	//	printf("num2 = %lld\n",num2);
		printf("=");

		num3 = num1 + num2;
	//	printf("num3 = %lld\n",num3);
		if(num3 == 0)
			printf("%c%c%c",A[0][0],A[0][1],A[0][2]);
		else
			func(num3);
		printf("\n");
		scanf("%c",&ch);
		scanf("%c",&ch);
	}
	scanf("%c",&ch);
	scanf("%c",&ch);
	scanf("%c",&ch);
	return 0;
}

void func(long long n)
{
	if(n <= 0)
		return;
	else
	{
		func(n/10);
		int m = n%10;
		printf("%c%c%c",A[m][0],A[m][1],A[m][2]);
	}
}
