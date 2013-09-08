#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int power;
	int coffNum;
	int coffDeno;
	struct node *next;
}node;

int term(node*,int*,int*,int);

int main()
{
	int n,m,p,q,r,s,i,j,k,l;
	scanf("%d",&n);
	int *arrayNum,*array1Num,*array2Num,*arrayDeno,*array1Deno,*array2Deno;
	arrayNum = (int*)malloc(sizeof(int)*n);
	array1Num = (int*)malloc(sizeof(int)*n);
	array2Num = (int*)malloc(sizeof(int)*n);
	arrayDeno = (int*)malloc(sizeof(int)*n);
	array1Deno = (int*)malloc(sizeof(int)*n);
	array2Deno = (int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
	{
		arrayDeno[i] = 1;
		scanf("%d",&arrayNum[i]);
		printf("%d ",arrayNum[i]);
		array1Num[i] = arrayNum[i];
		array1Deno[i] = 1;
	}
	printf("\n");
	node *head,*head1;
	head = (node*)malloc(sizeof(node)*1);
	head->next = NULL;
	head1 = head;
	int col=-1,po,fact,mult;
	while(col != 0)
	{
		col = term(head,array1Num,array1Deno,n);
		printf("col in main = %d\n\n",col);
		while(head->next != NULL)
		{
			head = head->next;
		}
		po = head->power;
		printf("po = %d\n",head->power);
		printf("head->coffNum = %d\n",head->coffNum);
		printf("head->coffDeno = %d\n\n",head->coffDeno);
		fact = 1;
		while(po)
		{
			fact = fact * po;
			po--;
		}
		printf("fact = %d\n",fact);
		
		printf("head->coffDeno phela = %d\n",head->coffDeno);
		head->coffDeno = head->coffDeno*fact;
		printf("head->coffDeno baad ch = %d\n\n",head->coffDeno);
		
		for(i=0;i<n;i++)
		{
			po = head->power;
			mult = 1;
			while(po)
			{
				mult = mult * (i+1);
				po--;
			}
			mult = mult * head->coffNum;
			printf("head->coffNum = mult = %d\n",mult);
			printf("head->coffDeno = %d\n",head->coffDeno);
			printf("arrayNum[i] = %d\n",arrayNum[i]);
			printf("arrayDeno[i] = %d\n",arrayDeno[i]);

			p = arrayDeno[i];
			q = head->coffDeno;
			r = 1;
			while(r != 0)
			{
				r = p % q;
				p = q;
				q = r;
			}
			s = (head->coffDeno*arrayDeno[i])/p;
			printf("lcm in main = %d\n",s);
			
			array1Deno[i] = s;
			array1Num[i] = ((s/arrayDeno[i])*arrayNum[i]) - ((s/head->coffDeno)*mult);

			arrayNum[i] = array1Num[i];
			arrayDeno[i] = array1Deno[i];

			printf("array1Num[i] = %d\n",array1Num[i]);
			printf("array1Deno[i] = %d\n\n",array1Deno[i]);
		}
	}

	scanf("%d",&k);
	int num,deno,num1,deno1,num3;
	for(l=n+1;l<=n+k;l++)
	{
		head = head1;
		head = head->next;
		
		po = head->power;
		num = head->coffNum;
		deno = head->coffDeno;
		while(po)
		{
			num = num * l;
			po--;
		}
		
		while(head->next != NULL)
		{
			head = head->next;
			p = head->coffDeno;
			q = deno;
			r = 1;
			while(r != 0)
			{
				r = p%q;
				p = q;
				q = r;
			}
			
			s = (deno*head->coffDeno)/p;
			
			po = head->power;
			num3 = 1;
			while(po)
			{
				num3 = num3 * l;
				po--;
			}
			
			num1 = ((s/deno)*head->coffNum*num3) + ((s/head->coffDeno)*num);
			deno1 = s;

			num = num1;
			deno = deno1;
			

		//	printf("num = %d\n",head->coffNum);
		//	printf("deno = %d\n",head->coffDeno);
		//	printf("power = %d\n\n",head->power);
		}
		printf("%d ",num/deno);
	}
	printf("\n");

	return 0;
}

int term(node *head,int *array1Num,int *array1Deno,int n)
{
	int col = 0;  //////column number;
	int i,j,k,l,m,flag;
	flag = 0;
	for(i=0;i<n-1;i++)
	{
		if(array1Num[i] == array1Num[i+1] && array1Deno[i] == array1Deno[i+1])
			continue;
		else
		{
			flag = 1;
			break;
		}
	}
	if(flag == 0)
	{
		node *temp;
		temp = (node*)malloc(sizeof(node)*1);
		temp->next = NULL;

		temp->power = col;
		temp->coffNum = array1Num[0];
		temp->coffDeno = array1Deno[0];

		while(head->next != NULL)
		{
			head = head->next;
		}
		temp->next = head->next;
		head->next = temp;
		return col;
	}
	else
	{
		int *array2Num,*array2Deno,flag1;
		array2Num = (int*)malloc(sizeof(int)*n);
		array2Deno = (int*)malloc(sizeof(int)*n);
		int p,q,r,s;
		m = n;
		while(1)
		{
			flag1 = 0;
			for(i=0;i<m-1;i++)
			{
				printf("array1Num[i] = %d\n",array1Num[i]);
				printf("array1Deno[i] = %d\n",array1Deno[i]);
				printf("array1Num[i+1] = %d\n",array1Num[i+1]);
				printf("array1Deno[i+1] = %d\n",array1Deno[i+1]);
				// find GCD of i and i+1 array1Deno;
				p = array1Deno[i];
				q = array1Deno[i+1];
				r = 1;
				while(r != 0)
				{
					r = p % q;
					p = q;
					q = r;
				}
				// p is my GCD;
				s = (array1Deno[i]*array1Deno[i+1])/p;  //    its LCM of denominators;
				printf("lcm in function = %d\n",s);
				array2Deno[i] = s;
				array2Num[i] = ((s/array1Deno[i+1])*array1Num[i+1]) - ((s/array1Deno[i])*array1Num[i]);
				printf("array2Num[i] = %d\n",array2Num[i]);
				printf("array2Deno[i] = %d\n\n",array2Deno[i]);
			}
			col++;
			if(m == 2)
			{
				flag1 = 1; // means all the numbers are same;
				// halt the loop and do something else;;
			//	break;
			}
			if(flag1 == 0)
			{
				for(i=0;i<m-2;i++)
				{
					if(array2Num[i] == array2Num[i+1] && array2Deno[i] == array2Deno[i+1])
						continue;
					else
						break;
				}
			}
			if(i == m-2)
				flag1 = 1;
			if(flag1 == 1)
			{
				// store the cofficient and power;
				node *temp;
				temp = (node*)malloc(sizeof(node)*1);
				temp->power = col;
				temp->coffNum = array2Num[0];
				temp->coffDeno = array2Deno[0];
				temp->next = NULL;

				while(head->next != NULL)
				{
					head = head->next;
				}
				temp->next = head->next;
				head->next = temp;
				printf("temp->power = %d\n",temp->power);
				printf("temp->coffNum = %d\n",temp->coffNum);
				printf("temp->coffDeno = %d\n\n",temp->coffDeno);
				return col;
			}
			else
			{
				for(i=0;i<m-1;i++)
				{
					array1Num[i] = array2Num[i];
					array1Deno[i] = array2Deno[i];
				}
			}
			m = m - 1;
		}
	}

}
	




