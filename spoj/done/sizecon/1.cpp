#include<cstdio>
int main(){
	int i,n,s=0,m;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&m);
		if(m>0)
			s+=m;
	}
	printf("%d\n",s);
	return 0;
}
