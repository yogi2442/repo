#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>

int func(int,int,char*,int);

int main()
{
	int i,j,k,l,len,ans1,ans2;
	char *str;
	str = (char*)malloc(sizeof(char)*10000);
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
		ans1 = 0;
		ans2 = 0;
		if(str[0] == '1' || str[0] == '2')
			ans1 = func(1,len-1,str,0); //  means nahi haiga
		if(str[0] != '0')
			ans2 = func(1,len-1,str,1);  // means haiga

		printf("%d\n",ans1+ans2);
		scanf("%s",str);
	}
	return 0;
}

int func(int low,int high,char *str,int flag)
{
	int ans1,ans2,ans3;
	
	ans1 = 0;
	ans2 = 0;
	ans3 = 0;

	if(high - low == 0)
	{
		if(flag == 0)
		{
			if(str[low-1] == '1' || (str[low-1] == '2' && (str[low] >= '0' && str[low] <= '6')))
			{
				ans1 = 1;
			}

		}
		if(flag == 1)
		{
		//	if(str[low] == '0')
		//		ans2 = 0;
			if(str[high] != '0')
				ans3 = 1;
		}
		return ans1+ans2+ans3;
	}

	if(flag == 0)
	{
		// means nahi haiga;
		if(str[low-1] == '1' || (str[low-1] == '2' && (str[low] >= '0' && str[low] <= '6')))
		{
			ans1 = func(low+1,high,str,1);
		}
	}
	if(flag == 1)
	{
		//  means haiga;
		if(str[low] != '0')
			ans2 = func(low+1,high,str,1);
		
		if(str[low] == '1' || str[low] == '2')
			ans3 = func(low+1,high,str,0);
	}
	return ans1+ans2+ans3;
	
}
