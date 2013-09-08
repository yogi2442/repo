#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>

int main()
{
	int A[26],i,j,k,l,m,n,test,u,len,max1,max2,diff;
	char str[2000],ch;
	scanf("%d",&test);
	for(u=0;u<test;u++)
	{
		scanf("%d",&ch);
		scanf("%[^\n]",str);
		len = strlen(str);
	//	printf("len = %d\n",len);
	//	printf("%s\n",str);
		for(i=0;i<26;i++)
			A[i]=0;
		for(i=0;i<len;i++)
		{
			if(str[i] == ' ')
				continue;
			else
				A[str[i] - 'A']++;
		}
		max1=0;
		max2=0;
		for(i=0;i<26;i++)
		{
			if(A[i] >= A[max1])
			{
				max2 = max1;
				max1 = i;
			}
		}
		if(A[max1] == A[max2] && max1 != max2)
			printf("NOT POSSIBLE\n");
		else
		{
		//	printf("%c\n",max1+'A');
			diff = max1 + 'A' - 'E';
			diff = (diff >= 0) ? diff : 26+diff;
			printf("%d ",diff);
			for(i=0;i<len;i++)
			{
				if(str[i] == ' ')
					printf("%c",str[i]);
				else
				{
					if(str[i]-diff >= 65 && str[i]-diff <= 90)
						printf("%c",str[i]-diff);
					else
						printf("%c",str[i]-diff-65+91);
					
				}
			}
			printf("\n");
		}
	}
	return 0;

}
