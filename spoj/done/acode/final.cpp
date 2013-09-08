#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>

int main()
{
	int i,j,k,l,len,ans1,ans2;
	long long *yes,*no;
	char *str;
	str = (char*)malloc(sizeof(char)*5005);
	yes = (long long*)malloc(sizeof(long long)*5005);
	no = (long long*)malloc(sizeof(long long)*5005);
	scanf("%s",str);
	while(strcmp(str,"0") != 0)
	{	
		len = strlen(str);
	//	printf("len = %d\n",len);
	//	printf("str = %s\n",str);
		if(len == 1)
		{
			printf("1\n");
			scanf("%s",str);
			continue;
		}
		if(str[1] != '0')
			yes[1] = 1;
		else
			yes[1] = 0;
		if(str[0] == '1' || (str[0] == '2' && (str[1] >= '0' && str[1] <= '6')))
			no[1] = 1;
		else
			no[1] = 0;
		for(i=2;i<len;i++)
		{
			if(str[i] != '0')
				yes[i] = yes[i-1]+no[i-1];
			else
				yes[i] = 0;
			if(str[i-1] == '1' || (str[i-1] == '2' && (str[i] >= '0' && str[i] <= '6')))
				no[i] = yes[i-1];
			else
				no[i] = 0;
		}
		printf("%lld\n",yes[len-1]+no[len-1]);
		scanf("%s",str);
	}
	return 0;
}

