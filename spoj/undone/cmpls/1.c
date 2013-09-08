#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	long long int power;
	long long int coffNum;
	long int coffDeno;
	struct node *next;
}node;

long long int term(node*,long long int*,long long int*,long long int);

int main()
{
	long long int n,m,p,q,r,s,i,j,k,l;
	scanf("%lld",&n);
	long long int *arrayNum,*array1Num,*array2Num,*arrayDeno,*array1Deno,*array2Deno;
	arrayNum = (long long int*)malloc(sizeof(long long int)*n);
	array1Num = (long long int*)malloc(sizeof(long long int)*n);
//	array2Num = (long long int*)malloc(sizeof(long long int)*n);
	arrayDeno = (long long int*)malloc(sizeof(long long int)*n);
	array1Deno = (long long int*)malloc(sizeof(long long int)*n);
//	array2Deno = (long long int*)malloc(sizeof(long long int)*n);
	for(i=0;i<n;i++)
	{
		arrayDeno[i] = 1;
		scanf("%lld",&arrayNum[i]);
		printf("%lld ",arrayNum[i]);
		array1Num[i] = arrayNum[i];
		array1Deno[i] = 1;
	}
	printf("\n");
	node *head,*head1;
	head = (node*)malloc(sizeof(node)*1);
	head->next = NULL;
	head1 = head;
	long long int col=-1,po,fact,mult;
	while(col != 0)
	{
		col = term(head,array1Num,array1Deno,n);
		printf("col in main = %lld\n\n",col);
		while(head->next != NULL)
		{
			head = head->next;
		}
		po = head->power;
		printf("po = %lld\n",head->power);
		printf("head->coffNum = %lld\n",head->coffNum);
		printf("head->coffDeno = %lld\n\n",head->coffDeno);
		fact = 1;
		while(po)
		{
			fact = fact * po;
			po--;
		}
		printf("fact = %lld\n",fact);
		
		printf("head->coffDeno phela = %lld\n",head->coffDeno);
		head->coffDeno = head->coffDeno*fact;
		
		p = abs(head->coffNum);
		q = abs(head->coffDeno);
		r = 1;
			if(p != 0 && q != 0)
			{
		while(r != 0)
		{
			r = p % q;
			p = q;
			q = r;
		}
		head->coffNum = head->coffNum / p;
		head->coffDeno = head->coffDeno / p;
			}
		printf("head->coffNum = %lld\n",head->coffNum);
		printf("head->coffDeno baad ch = %lld\n\n",head->coffDeno);


		
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
			printf("head->coffNum = mult = %lld\n",mult);
			printf("head->coffDeno = %lld\n",head->coffDeno);
			printf("arrayNum[i] = %lld\n",arrayNum[i]);
			printf("arrayDeno[i] = %lld\n",arrayDeno[i]);

			p = abs(arrayDeno[i]);
			q = abs(head->coffDeno);
			r = 1;
			while(r != 0)
			{
				r = p % q;
				p = q;
				q = r;
			}
			s = (head->coffDeno*arrayDeno[i])/p;
			printf("lcm in main = %lld\n",s);

			array1Deno[i] = s;
			array1Num[i] = ((s/arrayDeno[i])*arrayNum[i]) - ((s/head->coffDeno)*mult);


			p = abs(array1Deno[i]);
			q = abs(array1Num[i]);
			r = 1;
			if(p != 0 && q != 0)
			{
				while(r != 0)
				{
					r = p % q;
					p = q;
					q = r;
				}
				//	numb = (array1Deno[i]*array1Num[i])/p;
				array1Deno[i] = array1Deno[i]/p;
				array1Num[i] = array1Num[i]/p;
			}

			arrayNum[i] = array1Num[i];
			arrayDeno[i] = array1Deno[i];

			printf("array1Num[i] = %lld\n",array1Num[i]);
			printf("array1Deno[i] = %lld\n\n",array1Deno[i]);
		}
	//	n--;
	}

	scanf("%lld",&k);
	long long int num,deno,num1,deno1,num3;
	for(l=n+1;l<=n+k;l++)
	{
		printf("l = %lld    ",l);
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
			p = abs(head->coffDeno);
			q = abs(deno);
			r = 1;
			while(r != 0)
			{
				r = p%q;
				p = q;
				q = r;
			}
			
			s = (deno*head->coffDeno)/p;
			
			po = head->power;
			num3 = head->coffNum;
			while(po)
			{
				num3 = num3 * l;
				po--;
			}
			
			num1 = ((s/deno)*num) + ((s/head->coffDeno)*num3);
			deno1 = s;

			num = num1;
			deno = deno1;
			

		//	printf("num = %d\n",head->coffNum);
		//	printf("deno = %d\n",head->coffDeno);
		//	printf("power = %d\n\n",head->power);
		}
		printf("%lld\n",num/deno);
	}
	printf("\n");

	return 0;
}

long long int term(node *head,long long int *array1Num,long long int *array1Deno,long long int n)
{
	long long int col = 0;  //////column number;
	long long int i,j,k,l,m,flag;
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
		long long int *array2Num,*array2Deno,flag1;
		array2Num = (long long int*)malloc(sizeof(long long int)*n);
		array2Deno = (long long int*)malloc(sizeof(long long int)*n);
		long long int p,q,r,s;
		m = n;
		while(1)
		{
			flag1 = 0;
			for(i=0;i<m-1;i++)
			{
				printf("array1Num[i] = %lld\n",array1Num[i]);
				printf("array1Deno[i] = %lld\n",array1Deno[i]);
				printf("array1Num[i+1] = %lld\n",array1Num[i+1]);
				printf("array1Deno[i+1] = %lld\n",array1Deno[i+1]);
				// find GCD of i and i+1 array1Deno;
				p = abs(array1Deno[i]);
				q = abs(array1Deno[i+1]);
				r = 1;
				while(r != 0)
				{
					r = p % q;
					p = q;
					q = r;
				}
				// p is my GCD;
				s = (array1Deno[i]*array1Deno[i+1])/p;  //    its LCM of denominators;
				printf("lcm in function = %lld\n",s);
				array2Deno[i] = s;
				array2Num[i] = ((s/array1Deno[i+1])*array1Num[i+1]) - ((s/array1Deno[i])*array1Num[i]);
				
				p = abs(array2Num[i]);
				q = abs(array2Deno[i]);
				r = 1;
				while(r != 0)
				{
					r = p % q;
					p = q;
					q = r;
				}
				array2Num[i] = array2Num[i]/p;
				array2Deno[i] = array2Deno[i]/p;

				
				printf("array2Num[i] = %lld\n",array2Num[i]);
				printf("array2Deno[i] = %lld\n\n",array2Deno[i]);
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
				printf("temp->power = %lld\n",temp->power);
				printf("temp->coffNum = %lld\n",temp->coffNum);
				printf("temp->coffDeno = %lld\n\n",temp->coffDeno);

				free(array2Num);
				free(array2Deno);
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
	




