#include <cstdio>
#include <iostream>
#include <cmath>

long long fib[2][2];
long long p,m,n;
long long ans[2][2];
long long temp[2][2];
    
int main()
{
    int u,t;
    scanf("%d",&t);

    for(u=0;u<t;u++)
    {
        scanf("%lld%lld",&n,&m);
        p = 1<<m;

        fib[0][0] = 1;
        fib[0][1] = 1;
        fib[1][0] = 1;
        fib[1][1] = 0;

        ans[0][0] = 1;
        ans[0][1] = 0;
        ans[1][0] = 0;
        ans[1][1] = 1;
    
        
        while(n > 0)
        {
            if(n & 1)
            {
                temp[0][0] = (ans[0][0]*fib[0][0] + ans[0][1]*fib[1][0])%p;
                temp[0][1] = (ans[0][0]*fib[0][1] + ans[0][1]*fib[1][1])%p;
                temp[1][0] = (ans[1][0]*fib[0][0] + ans[1][1]*fib[1][0])%p;
                temp[1][1] = (ans[1][0]*fib[0][1] + ans[1][1]*fib[1][1])%p;

                ans[0][0] = temp[0][0];
                ans[0][1] = temp[0][1];
                ans[1][0] = temp[1][0];
                ans[1][1] = temp[1][1];
            }

            temp[0][0] = (fib[0][0]*fib[0][0] + fib[0][1]*fib[1][0])%p;
            temp[0][1] = (fib[0][0]*fib[0][1] + fib[0][1]*fib[1][1])%p;
            temp[1][0] = (fib[1][0]*fib[0][0] + fib[1][1]*fib[1][0])%p;
            temp[1][1] = (fib[1][0]*fib[0][1] + fib[1][1]*fib[1][1])%p;

            fib[0][0] = temp[0][0];
            fib[0][1] = temp[0][1];
            fib[1][0] = temp[1][0];
            fib[1][1] = temp[1][1];
            n = n / 2;
        }

        printf("%lld\n",(ans[1][0]%p + ans[1][1]%p)%p); 
    }
    return 0;
}
