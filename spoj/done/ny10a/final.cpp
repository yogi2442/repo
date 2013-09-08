#include <cstdio>
#include <cstring>

int main()
{
	int i,j,k,l,m,n,A[8],t,u;
	char str[50];
	scanf("%d",&t);
	while(t)
	{
		scanf("%d",&n);
		scanf("%s",str);
	//	printf("%s\n",str);
		for(i=0;i<8;i++)
			A[i]=0;
		for(i=0;i<38;i++)
		{
			if(str[i] == 'T')
			{
				if(str[i+1] == 'T')
				{
				//	printf("yogi\n");
					if(str[i+2] == 'T')
						A[0]++;
					else if(str[i+2] == 'H')
						A[1]++;
				}
				else if(str[i+1] == 'H')
				{
					if(str[i+2] == 'T')
						A[2]++;
					else if(str[i+2] == 'H')
						A[3]++;
					
				}
			}
			else if(str[i] == 'H')
			{
				if(str[i+1] == 'T')
				{
					if(str[i+2] == 'T')
						A[4]++;
					else if(str[i+2] == 'H')
						A[5]++;
				}
				else if(str[i+1] == 'H')
				{
					if(str[i+2] == 'T')
						A[6]++;
					else if(str[i+2] == 'H')
						A[7]++;
					
				}
			}
		}
		printf("%d %d %d %d %d %d %d %d %d\n",n,A[0],A[1],A[2],A[3],A[4],A[5],A[6],A[7]);
		t--;
	}
	return 0;
}
