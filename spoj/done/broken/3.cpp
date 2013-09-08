#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	int A[260],i,j,k,l,m,n,len,max,po;
	char *str,*str1,ch;
	str = (char*)malloc(sizeof(char)*1000010);
	int dist=0,head,tail;

	scanf("%d",&m);
	while(m != 0)
	{
		for(i=0;i<260;i++)
			A[i]=0;
		
		scanf("%c",&ch);
		scanf("%c",&ch);
		i=0;
		while(ch != '\n')
		{
			str[i++] = ch;
		//	printf("%c",ch);
			scanf("%c",&ch);
		}
	//	printf("\n");
		
		len = i;
	//	printf("len = %d\n",len);

		if(len <= m)
		{
			printf("%d\n",len);
			scanf("%d",&m);
			continue;
		}
		else
		{
			i=0;
			dist=0;
			while(dist < m && i < len)
			{
				 if(A[str[i]] == 0)
					dist++;
				A[str[i]]++;
				i++;
			}
//			printf("dist = %d\n",dist);
			max = i;
			head = 0;
		//	tail = 0;
		//	dist = 0;
		//	i=0;
			while(i<len)
			{
			//	printf("i = %d and dist = %d    and ",i,dist);

				if(dist < m && A[str[i]] == 0)
				{
					dist++;
					A[str[i]]++;
				//	printf("char = '%c' and dist < m and A[str[i]] == 0   ",str[i]);
				//	tail++;
				}
				else if(dist == m && A[str[i]] == 0)
				{
					A[str[head]]--;
					if(A[str[head]] > 0)
					{
						head++;
						continue;
					}
					head++;
					A[str[i]]++;
				//	printf("char = '%c' and dist == m and A[str[i]] == 0    ",str[i]);
				}
				else if(dist == m && A[str[i]] > 0)
				{
					A[str[i]]++;
				//	printf("char = '%c' and dist == m and A[str[i]] > 0    ",str[i]);
				//	tail++;
				}
			//	printf("i = %d and head = %d\n",i,head);
				if(max < (i -  head) + 1)
				{
					max = i - head + 1;
				//	printf("max = %d\n",max);
				}
				i++;
			}
			printf("%d\n",max);
		}
		scanf("%d",&m);
	}
}
