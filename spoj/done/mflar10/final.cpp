#include <cstdio>
#include <cstring>

int main()
{
	int i,len;
	char str[2000],ch,c;
	strcpy(str,"");
	scanf("%[^\n]",str);
	while(strcmp(str,"*") != 0)
	{	
		scanf("%c",&c);
	//	printf("str = %s\n",str);
		len = strlen(str);
	//	printf("len = %d\n",len);
	/*	if(len == 1 && ((str[0] < 65 || str[0] > 90)))
		{
			strcpy(str,"");
			scanf("%[^\n]",str);
			continue;
		}
		else if(len == 1 && ((str[0] < 97 || str[0] > 122)))
		{
			strcpy(str,"");
			scanf("%[^\n]",str);
			continue;
		}*/
		i=0;
		while(str[i] == ' ')
			i++;
		if(len > 0 && i < len)
		{
			ch = str[i];
			if(ch >= 65 && ch <= 90)
			{
			}
			else if(ch >= 97 && ch <= 122)
				ch = ch - 32;
			for(i=1;i<len;i++)
			{
				if(str[i-1] == ' ' && str[i] != ' ')
				{
					if(str[i] >= 65 && str[i] <= 90 && str[i] == ch)
						continue;
					else if(str[i] >= 97 && str[i] <= 122 && str[i]-32 == ch)
						continue;
					else
						break;
				}
			}
			if(i == len)
				printf("Y\n");
			else
				printf("N\n");
		}
		strcpy(str,"");
		scanf("%[^\n]",str);
	}
	return 0;
}
