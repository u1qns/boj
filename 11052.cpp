#include <iostream>
#include <vector>
#include <algorithm>

int main() {

	std::vector<int> P;
	std::vector<int> dp;
	int N; std::cin >> N;

	P.resize(N +1);
	dp.resize(N+1);

	for(int i = 1; i< N+1; ++i)
	{
		std::cin >> P[i];
	}
	P[0] = 0;
	dp[0] = 0;
	for(int i = 1; i < N+1 ; ++i)
	{
		for(int j = 1; j <i +1 ; ++j)
		{
			dp[i] = std::max(dp[i], dp[i -j] + P[j]);
		}
	}

	std::cout << dp[N];

	return 0;
}
