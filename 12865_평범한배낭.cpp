#include <iostream>
#include <algorithm>
int dp[101][100000];

int main()
{
	int n = 0, k = 0;
	std::cin >> n >> k;

	int max = 0;
	int w = 0; int v = 0;
	for (int i = 1; i <= n; ++i)
	{
		std::cin >> w >> v;
		for (int j = 0; j <= k; ++j)
		{
			if (j < w)
			{
				dp[i][j] = dp[i - 1][j];
			}
			else
			{
				dp[i][j] = std::max(dp[i - 1][j - w] + v, dp[i - 1][j]);
			}

			max = (max < dp[i][j] ? dp[i][j] : max);
		}
	}

	std::cout << max << std::endl;

	return 0;
}
