#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

int main() {

	int N = 0; std::cin >> N;
	std::vector<long> tiles;
	tiles.reserve(N + 1);

	tiles.push_back(1);
	tiles.push_back(1);
	tiles.push_back(2);

	for (int i = 3; i <= N; ++i)
	{
		tiles.push_back((tiles[i - 1] + tiles[i - 2]) % 15746);
	}
	std::cout << tiles[N];

	return 0;
}
