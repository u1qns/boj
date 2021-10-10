#include <iostream>
/*
1000000000
*/
int main()
{
	long long dp[101][10] = { 0, };
	int n ; std::cin >> n;

	for (int i = 1; i < 10; ++i)
	{
		dp[1][i] = 1;
	}

	for (int x = 2; x <= n; ++x)
	{
		for (int i = 0; i < 10; ++i)
		{
			if (i == 0)
			{
				dp[x][i] = dp[x - 1][i + 1] % 1000000000;
			}
			else if (i == 9)
			{
				dp[x][i] =  dp[x - 1][i - 1] % 1000000000;
			}
			else
			{
				dp[x][i] = (dp[x - 1][i + 1] + dp[x - 1][i - 1]) % 1000000000;
			}
		}
	}

	long long max = 0;
	for (int i = 0; i < 10; ++i)
	{
		max += (dp[n][i] % 1000000000);
	}

	std::cout << max % 1000000000 << std::endl; // 안 나누면 틀렸다고 함 ㅡㅡ
}
