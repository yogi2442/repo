#include <cstdio>
#include <cstring>

int main()
{
	char str[500];
	char ans[500];
	int len,i,j,l,n,m,k,underscore,capital;
	while(scanf("%s",str)!=EOF)
	{
	//	printf("str = %s\n",str);
		len = strlen(str);
	//	printf("len = %d\n",len);
		j=0;
		underscore = 0;
		capital = 0;
		if((str[0] >= 65 && str[0] <= 90 ) || str[0] == '_')
		{
			printf("Error!\n");
			continue;
		}
		k=0;
		for(i=0;i<len;i++)
		{
			if(str[i] == '_')
			{
			//	printf("under\n");
				underscore = 1;
			}
			if(str[i] >= 65 && str[i] <= 90)
			{
				capital = 1;
			//	printf("cap\n");
			}
			if(capital == 1 && underscore == 1)
			{
				printf("Error!\n");
				k=1;
				break;
			}
			if(i == len-1 && str[i] == '_')
			{
				printf("Error!\n");
				k=1;
				break;
			}
			if(str[i] == '_')
			{
				i++;
				if(str[i] == '_' || (str[i] >= 65 && str[i] <= 90))
				{
					printf("Error!\n");
					k=1;
					break;
				}
				else
					ans[j++] = str[i]-32;
			}
			else if(str[i] >= 65 && str[i] <= 90)
			{
				ans[j++] = '_';
				ans[j++] = str[i]+32;
			}
			else
				ans[j++] = str[i];

			// double underscore
		}
		ans[j] = '\0';
		if(k != 1)
			printf("%s\n",ans);
		strcpy(str,"");
		strcpy(ans,"");
	}
}
