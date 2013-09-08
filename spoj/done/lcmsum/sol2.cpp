#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
int A[10000000]={0};
int main()
{
 
    int isprime[3163],d,n,e,p,k,i;
 
    for (n=2;n<3163;n++)
        isprime[n]=1;
 
    //Sieve for Eratosthenes for Prime
    //Storing the smallest prime which divides n.
    //If A[n]=0 it means it is prime number.
    for(d=2;d<3163;d++)
    {
        if(isprime[d])
        {
            for (n=d*d;n<3163;n+=d)
            {
                isprime[n]=0;
                A[n]=d;
            }
            for (;n<=10000000;n+=d)
                A[n]=d;
        }
    }
 
    //Applying the formula
    //Divisor(N)=Divisors(N/p^f(N,p))*(f(N,p)+1)
    A[1]=1;
    for(n=2;n<=10000000;n++)
    {
        if (A[n]==0)
           A[n]=2;
        else
        {
           p=A[n],k=n/p,e=2;
           while (k%p==0)
                 k/=p,e++;
           A[n]=A[k]*e;
        }
    }
    printf("time=%.3lf sec.\n",
    (double) (clock())/CLOCKS_PER_SEC);
    while (scanf("%d",&i),i)
    {
          printf("%d\n",A[i]);
    }
    return 0;
}
