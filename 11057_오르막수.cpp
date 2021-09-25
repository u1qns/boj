#include <iostream>

int main()
{
  int n; std::cin >> n;

  int result = 0;
  int dp[10001][10];

  for(int i = 0; i<10; ++i)
  {
	   dp[1][i] = 1;
  }

  for(int i = 2; i < n+1; ++i)
  {
    //std::cout << "#" << i << std::endl;
      for(int j = 0; j < 10; ++j)
      {
        for(int k=j; k<10; ++k)
        {
        	//std::cout <<"k " <<k <<": " << dp[i-1][k] << "\t";
          dp[i][j]+=dp[i-1][k] % 10007;
        }
        //std::cout << "dp[i][" << j <<"]: "<< dp[i][j] << "\n";
      }
      //std::cout << "\n";
  }

  for(int i = 0; i<10; ++i)
  {
    result += dp[n][i];
  }
  std::cout << result % 10007;

  return 0;
}
