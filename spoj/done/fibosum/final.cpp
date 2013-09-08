#include <cstdio>
#include <cstdlib>

int main()
{
	long long u,t,a,b,n,m;
	long long mod = 1000000007;

	long long fib[2][2] = {{1,1},{1,0}};
	long long ans[2][2] = {{1,0},{0,1}};
	long long temp[2][2];
	scanf("%lld",&t);

	for(u=0;u<t;u++)
	{
		scanf("%lld%lld",&n,&m);
		
		fib[0][0] = 1;
		fib[0][1] = 1;
		fib[1][0] = 1;
		fib[1][1] = 0;

		ans[0][0] = 1;
		ans[0][1] = 0;
		ans[1][0] = 0;
		ans[1][1] = 1;
		n++;
		m = m + 2;
		while(n > 0)
		{
			if(n&1)
			{
				temp[0][0] = (ans[0][0]*fib[0][0] + ans[0][1]*fib[1][0])%mod;
				temp[0][1] = (ans[0][0]*fib[0][1] + ans[0][1]*fib[1][1])%mod;
				temp[1][0] = (ans[1][0]*fib[0][0] + ans[1][1]*fib[1][0])%mod;
				temp[1][1] = (ans[1][0]*fib[0][1] + ans[1][1]*fib[1][1])%mod;

				ans[0][0] = temp[0][0];
				ans[0][1] = temp[0][1];
				ans[1][0] = temp[1][0];
				ans[1][1] = temp[1][1];
			}

			temp[0][0] = (fib[0][0]*fib[0][0] + fib[0][1]*fib[1][0])%mod;
			temp[0][1] = (fib[0][0]*fib[0][1] + fib[0][1]*fib[1][1])%mod;
			temp[1][0] = (fib[1][0]*fib[0][0] + fib[1][1]*fib[1][0])%mod;
			temp[1][1] = (fib[1][0]*fib[0][1] + fib[1][1]*fib[1][1])%mod;

			fib[0][0] = temp[0][0];
			fib[0][1] = temp[0][1];
			fib[1][0] = temp[1][0];
			fib[1][1] = temp[1][1];

			n = n / 2;
		}
		a = ans[0][1];
		
		fib[0][0] = 1;
		fib[0][1] = 1;
		fib[1][0] = 1;
		fib[1][1] = 0;

		ans[0][0] = 1;
		ans[0][1] = 0;
		ans[1][0] = 0;
		ans[1][1] = 1;
		while(m > 0)
		{
			if(m&1)
			{
				temp[0][0] = (ans[0][0]*fib[0][0] + ans[0][1]*fib[1][0])%mod;
				temp[0][1] = (ans[0][0]*fib[0][1] + ans[0][1]*fib[1][1])%mod;
				temp[1][0] = (ans[1][0]*fib[0][0] + ans[1][1]*fib[1][0])%mod;
				temp[1][1] = (ans[1][0]*fib[0][1] + ans[1][1]*fib[1][1])%mod;

				ans[0][0] = temp[0][0];
				ans[0][1] = temp[0][1];
				ans[1][0] = temp[1][0];
				ans[1][1] = temp[1][1];
			}

			temp[0][0] = (fib[0][0]*fib[0][0] + fib[0][1]*fib[1][0])%mod;
			temp[0][1] = (fib[0][0]*fib[0][1] + fib[0][1]*fib[1][1])%mod;
			temp[1][0] = (fib[1][0]*fib[0][0] + fib[1][1]*fib[1][0])%mod;
			temp[1][1] = (fib[1][0]*fib[0][1] + fib[1][1]*fib[1][1])%mod;

			fib[0][0] = temp[0][0];
			fib[0][1] = temp[0][1];
			fib[1][0] = temp[1][0];
			fib[1][1] = temp[1][1];

			m = m / 2;
		}
		b = ans[0][1];

		printf("%lld\n",(b-a+mod)%mod);
	}
	return 0;
}
