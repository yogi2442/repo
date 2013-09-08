#include <cstdio>
#include <cstring>

int main()
{
	int A[26],B[26],i,j,min,len,len1;
	char str[1002],str1[1002];
	while(scanf("%s%s",str,str1) !=  EOF)
	{
		for(i=0;i<26;i++)
		{
			A[i]=0;
			B[i]=0;
		}
		len = strlen(str);
		len1 = strlen(str1);
		for(i=0;i<len;i++)
		{
			A[str[i]-'a']++;
		}
		for(i=0;i<len1;i++)
		{
			B[str1[i]-'a']++;
		}
		for(i=0;i<26;i++)
		{
			if(A[i]<B[i])
				min = A[i];
			else
				min = B[i];
			for(j=0;j<min;j++)
			{
				printf("%c",i+'a');
			}
		}
			printf("\n");
	}
	return 0;
}
