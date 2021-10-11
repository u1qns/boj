#include <iostream>
#include <cmath>

int main(){

	int dp[100001];
	int n; std::cin >> n;

	for(int i=1; i<=n; ++i)
	{
		dp[i] = i;
		for(int j=1; j*j<=i; ++j)
		{
			dp[i] = std::min(dp[i], dp[i-j*j]+1);
		}
	}

 	std::cout << dp[n];

	return 0;
}
