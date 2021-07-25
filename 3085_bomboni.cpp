#include <iostream>
#include <algorithm>

int N;
char board[51][51];

int bomboni_right()
{
	int max = 0;
	int candy = 1;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N-1; ++j)
		{
			if (board[i][j] == board[i][j + 1]){
				++candy;
			}
			else {
				max = std::max(candy, max);
				candy = 1;
			}
		}
		max = std::max(candy, max);
		candy = 1;

	}

	return max;
}

int bomboni_down()
{
	int max = 0;
	int candy = 1;

	for (int j= 0; j < N; ++j)
	{
		for (int i = 0; i < N-1; ++i)
		{
			if (board[i][j] == board[i+1][j]) {
				++candy;
			}
			else {
				max = std::max(candy, max);
				candy = 1;
			}
		}
		max = std::max(candy, max);
		candy = 1;
	}

	return max;
}

int bomboni()
{
	int right = bomboni_right();
	int down = bomboni_down();
	
	return right < down ? down : right;
}

int main() 
{
	//input
	std::cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			std::cin >> board[i][j];
		}
	}

	//solve
	int result = 0;
	int max = 0;
    char cur = '\0';
    char next = '\0';
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cur = board[i][j];
			
			//right
			if (j+1 == N || cur == board[i][j + 1])
				continue;
			{
				next = board[i][j + 1];

				board[i][j] = next;
				board[i][j+1] = cur;
				max = bomboni();
				board[i][j] = cur;
				board[i][j+1] = next;

				result = (result < max ? max : result);
			}


			//down
			if (i+1 == N ||cur == board[i + 1][j])
				continue;
			{
				next = board[i + 1][j];

				board[i][j] = next;
				board[i+1][j] = cur;
				max = bomboni();
				board[i][j] = cur;
				board[i+1][j] = next;			
				
				result = (result < max ? max : result);
			}

		}
	}

	//input
	std::cout << result;

	return 0;
}