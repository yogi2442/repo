#include <cstdio>
#include <cstring>

int main()
{
	int i,j,count,ans,n,m,len;
	char str[3000];
	scanf("%s",str);
	j=1;
	while(str[0] != '-')
	{
		len = strlen(str);
		count=0;
		ans = 0;
		for(i=0;i<len;i++)
		{
			if(str[i] == '{')
				count++;
			else if(str[i] == '}')
				count--;
			if(count < 0)
			{
				count = count + 2;
				ans++;
			}
		}
		printf("%d. %d\n",j,(count/2)+ans);
		scanf("%s",str);
		j++;
	}
}
