#include <iostream>
#include <vector>
#include <algorithm>

int N, S;
int result;
std::vector<int> nums;
std::vector<int> dp;


int main()
{
	std::cin >> N ;
	nums.resize(N+1);
	dp.resize(N+1);
	for (int i = 0; i < N; ++i)
	{
		std::cin >> nums[i];
	}

	for (int i = 0; i < N; ++i) {
		int maximum = 0;
		for (int j = 0; j < i; ++j) {
			if (nums[j] < nums[i] && dp[j] > maximum) {
				maximum = dp[j];
			}
		}
		dp[i] = maximum + nums[i];
	}


	int max = 0;
	for (auto i : dp)
	{
		max = std::max(max, i);
	}

	std::cout << max << std::endl;

	return 0;
}
