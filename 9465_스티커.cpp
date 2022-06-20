#include <iostream>
#include <algorithm>

int main()
{
	int T; std::cin >> T;
	int sticker[2][100001];
	int dp[2][100001];
	dp[0][0] = 0;
	dp[1][0] = 0;
	
	while (T--)
	{
		int n; std::cin >> n;

		//input
		for (int i = 1; i <= n; i++)
			std::cin >> sticker[0][i];
		for (int i = 1; i <= n; i++)
			std::cin >> sticker[1][i];

		//solution
		dp[0][1] = sticker[0][1];
		dp[1][1] = sticker[1][1];
		for (int i = 2; i <= n; i++)
		{
			dp[0][i] = std::max(dp[1][i - 1], dp[1][i - 2]) + sticker[0][i];
			dp[1][i] = std::max(dp[0][i - 1], dp[0][i - 2]) + sticker[1][i];
		}

		//output 
		std::cout << std::max(dp[0][n], dp[1][n])<< "\n";
		
	}//T

	return 0;
}
