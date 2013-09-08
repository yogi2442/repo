#include <cstdio>
#include <cstring>

int main()
{
	int i,j,k,l,m,n;
	char str[200];
	char carry,ch,ch1;
	int num,num1,num2;
	int len;
	while(scanf("%s",str) != EOF)
	{
		if(strcmp(str,"1")==0)
			printf("1\n");
		else
		{
			carry = '0';
			len = strlen(str);
			num1=0;
			for(i=len-1;i>=0;i--)
			{
				num = str[i] - '0';
				num = num * 2 + num1;
				num1 = num/10;
				str[i] = (num%10) + '0';
			}
		/*	if(num1 != 0)
				printf("%d",num1);
			printf("%s\n",str);

			num2 = num1;
		*/	
			if(str[len-1] >= '2')
			{
				str[len-1] = str[len-1] - 2;
			}
			else
			{

				if(str[len-1] == '1')
					str[len-1] = '9';
				else if(str[len-1] == '0')
					str[len-1] = '8';
				for(i=len-2;i>=0;i--)
				{
					if(str[i] > '0')
					{
						str[i] = str[i]-1;
						break;
					}
					else
					{
						str[i] = '9';
					}
				}
				if(i == -1)
				{
					num1--;
				}
			}
			if(num1 > 0)
				printf("%d",num1);
			printf("%s\n",str);

		}
	}
	return 0;
}
