#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

char board[51][51];

int repainting(const char color, const int row, const int col)
{
	int cnt = 0;

	std::string odd(color == 'B' ? "BWBWBWBW" : "WBWBWBWB");
	std::string even(color == 'B' ? "WBWBWBWB" : "BWBWBWBW");
	int idx = 0;
	for (int r = row; r < row + 8; ++r)
	{
		for (int c = col; c < col + 8; ++c)
		{
			if (r % 2)
			{
				if (even.at(idx) != board[r][c])
					cnt++;
			}
			else
			{
				if (odd.at(idx) != board[r][c])
					cnt++;
			}

			++idx;
		}
		idx = 0;
	}

	return cnt;
}


int main() {

	int N, M;
	std::cin >> N >> M;
	int result = 64;

	//input
	for (int row = 0; row < N; ++row)
	{
		for (int col = 0; col < M; ++col)
		{

			std::cin >> board[row][col];
		}
	}


	//solve 
	for (int i = 0; i < N - 7; ++i)
	{
		for (int j = 0; j < M - 7; ++j)
		{
			int bCnt = repainting('B', i, j);
			result = (result < bCnt ? result : bCnt);

			int wCnt = repainting('W', i, j);
			result = (result < wCnt ? result : wCnt);

		}
	}


	//output
	std::cout << result << std::endl;

}//main