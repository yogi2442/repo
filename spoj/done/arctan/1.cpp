#include <cstdio>
#include<algorithm>
int main(){
	long long t,u,a,b,m;
	scanf("%lld",&t);
	for(u=0;u<t;u++){
		scanf("%lld",&a);m=1;m<<=50;for(b=a+1;b<2*a+2;b++)if((a*b+1)%(b-a)==0)m=std::min(m,b+((1+a*b)/(b-a)));printf("%lld\n",m);}
	return 0;
}
