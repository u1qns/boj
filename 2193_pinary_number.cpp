#include <vector>
#include <string>
#include <iostream>

int main() {

	int N = 0; std::cin >> N;
	std::vector<long> pinarys;
	pinarys.reserve(N+1);

	pinarys.push_back(0);
	pinarys.push_back(1);

	for (int i = 2; i <= N; ++i)
	{
		pinarys.push_back(pinarys[i - 1] + pinarys[i - 2]);
	}
	std::cout << pinarys[N];

	return 0;
}
