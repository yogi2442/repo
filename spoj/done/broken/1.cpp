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
	vector<int> v;

	scanf("%d",&m);
	int pop,push;
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
//		printf("\n");
		
		len = i;
//		printf("len = %d\n",len);

		if(len <= m)
		{
			printf("%d\n",len);
			scanf("%d",&m);
			continue;
		}
		else
		{
			int dist=0,head,tail;
			for(i=0;i<m;i++)
			{
				if(A[str[i]] == 0)
					dist++;
				A[str[i]]++;
			}
//			printf("dist = %d\n",dist);
			max = m;
			head = 0;
			tail = m;
			while(i<len)
			{
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




		/*	pop = 0;
			max = m;
			for(i=m;i<len;i++)
			{
				if(A[str[i]] == 0 && dist < m)
				{
					dist++;
				}
				else if(A[str[i]] > 0  && dist <= m)
				{
					A[str[i]]++;
				}
				else if(A[str[i]] == 0 && dist == m)
				{
					A[str[pop]]--;
					pop++;
					A[str[i]]++;
				}
					printf("pop = %d   i = %d\n",pop,i);
				if(max < i+1-pop)
				{
				//	printf("pop = %d   i = %d\n",pop,i);
					max = i-pop+1;
					printf("max = %d\n",max);
				}
			}*/

		/*	max = 0;
			po=0;
			v.clear();
			for(i=0;i<len;i++)
			{
				if(A[str[i]] != 1)
				{
					if(v.size() == m)
					{
						printf("intial size = %d   ",v.size());
						po = v[0];
						v.erase(v.begin());
						A[str[po]] = 0;
						A[str[i]] = 1;
						v.push_back(i);
						printf("po = %d  ",po);
						printf("i = %d    ",i);
						printf("final size = %d\n",v.size());
					}
					else
					{
						v.push_back(i);
						A[str[i]] = 1;
					}
				}
				po = v[0];
				if(max < i-po+1)
				{
					printf("in else   ");
					max = i-po+1;
					printf("max = %d    i = %d    po = %d\n",max,i,po);
				}
			}*/
			printf("%d\n",max);
		}
		scanf("%d",&m);
	}
}
