#include <cstdio>
#include <cstdlib>
#include <cmath>

int main()
{
//	int A[10],B[3000],i,j,k,l,less=0,great=0,equal=0,n,m,count,p;
//	int flag1=0,flag2=0,flag3=0;
	int i,j,A[10],ans,b;
	for(i=0;i<10;i++)
		scanf("%d",&A[i]);
	for(i=1;i<10;i++)
		A[i] = A[i] + A[i-1];
	ans = A[0];

	for(i=1;i<10;i++)
	{
		if(A[i] > ans && A[i] < 100)
			ans = A[i];
		if(A[i] > 100 && A[i] - 100 <= 100 - ans)
			ans = A[i];
		else if(A[i] == 100)
			ans = A[i];
	}




/*	for(i=1;i<10;i++)
	{
		if(A[i] > ans && A[i] < 100)
			ans = A[i];
		else if(A[i] > 100 && A[i] < ans)
			ans = A[i];
		else if(ans < 100 && A[i] > 100 && A[i] - 100 >= 100 - ans)
			ans = A[i];
		else if(ans > 100 && A[i] < 100 && 100 - A[i] < ans - 100)
			ans = A[i];
		else if(A[i] == 100)
			ans = A[i];
		for(j=0;j<i;j++)
		{
			b = A[i] - A[j];
			if(b > ans && b < 100)
				ans = b;
			else if(b > 100 && b < ans)
				ans = b;
			else if(ans < 100 && b > 100 && b - 100 >= 100 - ans)
				ans = b;
			else if(ans > 100 && b < 100 && 100 - b < ans - 100)
				ans = b;
			else if(b == 100)
				ans = b;
		}
	}*/
	printf("%d\n",ans);
	return 0;






/*
	B[0] = 0;
	B[1] = A[0];
	k=0;l=2;
	p = 1;
	for(i=1;i<10;i++)
	{
		p = p*2;
	//	printf("to add = %d\n",A[i]);
	//	printf("p = %d\n",p);
	//	printf("to whom : ");
	//	count=0;
	//	printf("k = %d   and l = %d  and count = %d\n",k,l,count);
		j=0;
		while(j<p)
		{
		//	count++;
		//	printf("%d j = %d ",B[k],j);
			B[l++] = B[k] + 0;
			B[l++] = B[k++] + A[i];
			j++;
	//		printf("p = %d ",p);
		}
	//	printf("count = %d\n",count);
	//	printf("\n");
	}

//	printf("l = %d\n",l);
	for(i=1022;i<l;i++)
	{
	//	printf("%d ",B[i]);
		if(B[i] > B[less] && B[i] < 100)
		{
			flag1 = 1;
			less = i;
		}
		else if(B[i] < B[great] && B[i] > 100)
		{
			flag2 = 1;
			great = i;
		}
		else if(B[i] == 100)
		{
			flag3 = 1;
			equal = i;
		}
	}
//	printf("\n %d %d %d\n",flag1,flag2,flag3);
	if(flag3 == 1)
		printf("%d\n",B[equal]);
	else if(flag2 == 1 && flag1 == 1)
	{
		if(B[great] - 100 > 100 - B[less])
			printf("%d\n",B[less]);
		else if(B[great] - 100 <= 100 - B[less])
			printf("%d\n",B[great]);
	}
	else if(flag2 == 1 && flag1 == 0)
		printf("%d\n",B[great]);
	else if(flag1 == 1 && flag2 == 0)
		printf("%d\n",B[less]);
	else
		printf("0\n");

	return 0;*/
}

