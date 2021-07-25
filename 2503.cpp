#include <iostream>

int main() {

	// 가능성배열, 가능성카운트
	int potential[988] = { 0 };
	int p = 0;

	int a = 0, b = 0, c = 0;
	for (int i = 123; i < 988; ++i)
	{
		a = i / 100;
		b = i / 10; b %= 10;
		c = i % 10;
		
		if (a == 0 || b == 0 || c == 0)
			continue;
		if (a == b || a == c || b == c)
			continue;

		potent[i] = i;
		++p;
	}


	int N; std::cin >> N;
	for (int k = 0; k < N; ++k) {

		int n; int num[3] = { 0 }; //물어보는 수
		int strike = 0; int ball = 0; // 스트라이크, 볼

		std::cin >> n >> strike >> ball;

		num[0] = n / 100;
		num[1] = n / 10; num[1] %= 10;
		num[2] = n % 10;

		int _strike = 0; int _ball = 0;
		int a = 0, b = 0, c = 0;

		for (int i = 123; i < 988; ++i)
		{
			a = i / 100;
			b = i / 10; b %= 10;
			c = i % 10;

			if (a == 0 || b == 0 || c == 0)
				continue;
			if (a == b || a == c || b == c)
				continue;


			_strike = 0; _ball = 0;

			if (a == num[0]) _strike++;
			if (b == num[1]) _strike++;
			if (c == num[2]) _strike++;

			if (a == num[1]) _ball++;
			if (a == num[2]) _ball++;

			if (b == num[0]) _ball++;
			if (b == num[2]) _ball++;

			if (c == num[0]) _ball++;
			if (c == num[1]) _ball++;

			if ((strike != _strike) || (ball != _ball))
			{
				if(potent[i] != -1)
				{
					potent[i] = -1;
					--p;
				}
			}
		}


	} // N

	std::cout << p << std::endl;

}//main