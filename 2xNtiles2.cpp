#include <iostream>

int main()
{
  int N; std::cin >> N;
  long long tiles[1001];

  tiles[0] = 0;
  tiles[1] = 1;
  tiles[2] = 3;
  tiles[3] = 5;

  for(int i = 3; i <= N; ++i)
  {
    tiles[i] = ( tiles[i-1] + tiles[i-2]*2) % 10007;
  }
  std::cout << tiles[N];

}
