#include<iostream>
using namespace std;

#define MOD 1000000007

long long k, p, n;

long long gogo(long long p, long long n)
{
	if (n == 1)
	{
		return p;
	}

	if (n % 2 == 0) // Â¦¼ö 
	{
		long long ret = gogo( p, n / 2);

		return (ret * ret) % MOD;
	}
	else
	{
		long long ret = gogo( p, n / 2);

		return ((ret * ret % MOD) * (p % MOD)) % MOD;
	}
}

int main()
{

	cin >> k >> p >> n;

	// k * p ^ 10n;

	std::cout <<  k * gogo(p, 10 * n) % MOD;


}