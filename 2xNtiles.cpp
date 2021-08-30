#include <iostream>

int main()
{
  int N; std::cin >> N;
  long long tiles[1001];

  tiles[0] = 1;
  tiles[1] = 2;
  for(int i = 2; i < N; ++i)
  {
    tiles[i] = tiles[i-1] + tiles[i-2];
  }
  std::cout << tiles[N];

}
