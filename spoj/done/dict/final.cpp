#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>

typedef struct node
{
	char ch[26];
	struct node *next[26];
	int array[26];
	int end[26];

}node;

int flag;
void func(node*,char*,int,int);
void print(node*,char*,int,int,char*);
void print1(node*,char*);

int main()
{
	int n,k,i,j,len;
	char *str = (char*)malloc(sizeof(char)*200);
	node *head;
	head = (node*)malloc(sizeof(node)*1);
	for(i=0;i<26;i++)
	{
		head->ch[i] = '$';
		head->array[i] = 0;
		head->next[i] = NULL;
		head->end[i] = 0;
	}
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s",str);
		len = strlen(str);
	//	printf("len = %d\n",len);
		j=0;
		func(head,str,j,len);
	}
	int m;
	scanf("%d",&m);
	char str1[200];
	for(i=0;i<m;i++)
	{
		flag=0;
		scanf("%s",str);
		printf("Case #%d:\n",i+1);
		j=0;
		len = strlen(str);
		strcpy(str1,"");
		print(head,str,j,len,str1);
		if(flag == 0)
			printf("No match.\n");
			
	}

	return 0;
}

void print(node *head,char *str,int j,int len,char *str1)
{
	char c[2];
	c[1] = '\0';
	char str2[200];
	c[0] = str[j];

	if(j < len)
	{
		if(head->array[c[0] - 'a'] != 1)
		{
			flag=1;
			printf("No match.\n");
			return;
		}
		else
		{
			strcpy(str2,str1);
			strcat(str2,c);
		/*	if(j == len -1)
			{
				if(head->end[c[0]-'a'] == 1)
					printf("%s\n",str2);
			}*/
			print(head->next[c[0]-'a'],str,j+1,len,str2);
		}
	}
	else
	{
		print1(head,str1);
	}
}

void print1(node *head,char *str1)
{
	char c[2];
	c[1] = '\0';
	int i;
	char str2[200];
	for(i=0;i<26;i++)
	{
		if(head->array[i] == 1)
		{
			c[0] = 'a'+i;
			strcpy(str2,str1);
			strcat(str2,c);
			if(head->end[i] == 1)
			{
				flag=1;
				printf("%s\n",str2);
			}
			print1(head->next[i],str2);
		}
	}
}

void func(node *head,char *str,int j,int len)
{
	if(j < len)
	{

		int ch;
		ch = str[j];
	//	printf("ch = %c\n",ch);
		if(head->array[ch - 'a'] == 1)
		{
	//		printf("'%c' is present\n",ch);
			func(head->next[ch-'a'],str,j+1,len);
		}
		else
		{
		//	printf("'%c' is not present\n",ch);
			head->array[ch-'a'] = 1;
			if(j == len - 1)
			{
			//	printf("At end\n");
				head->end[ch-'a'] = 1;
			}
			if(head->next[ch-'a'] == NULL)
			{
			//	printf("inserting new node\n");
				node *temp;
				temp = (node*)malloc(sizeof(node)*1);
				int i;
				for(i=0;i<26;i++)
				{
					temp->ch[i] = '$';
					temp->array[i] = 0;
					temp->next[i] = NULL;
				}
				head->next[ch-'a'] = temp;
				func(head->next[ch-'a'],str,j+1,len);
			}
		}
			if(j == len - 1)
			{
			//	printf("At end\n");
				head->end[ch-'a'] = 1;
			}
	}
}
