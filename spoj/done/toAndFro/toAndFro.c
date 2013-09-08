#include <stdio.h>
int main()
{
	int i,j,k,l,n,flag;
	char c;
	char array[200][200];
	scanf("%d",&n);
	while(n!=0)
	{
		scanf("%c",&c);
		flag=1;
		i=0;
		j=0;
		scanf("%c",&c);
		while(c!='\n')
		{
			if(flag==1)
			{
				array[i][j++] = c;
				if(j==n)
				{
					j--;
					i++;
					flag=0;
				}
			}
			else
			{
				array[i][j--] = c;
				if(j==-1)
				{
					j=j++;
					i++;
					flag=1;
				}

			}
			scanf("%c",&c);
		}
		for(k=0;k<n;k++)
			for(l=0;l<i;l++)
				printf("%c",array[l][k]);
		printf("\n");
		scanf("%d",&n);

	}
	return 0;
}
