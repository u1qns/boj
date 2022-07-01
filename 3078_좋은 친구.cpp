#include <iostream>

using namespace std;
typedef pair<string, int> P;

int N, K;
long long ret;
string name;
queue<P> names[21];

int main() {
	cin >> N >> K;
	// K 등수 이하로 차이가 나면서 길이가 같아야 함.
	for (int i = 0; i < N; i++) {
		cin >> name;
		int len = name.size();

		// 등수가 K보다 크게 차이가 나는 녀석들을
		// 다 pop한다.
		while (!names[len].empty() &&
			i - names[len].front().second > K) {
			names[len].pop();
		}
		// Q의 크기만큼 i번째 사람과 친구 할 수 있음.
		ret += names[len].size();

		// 이름과 등수를 큐에 저장한다.
		names[len].push(P(name, i));

	}
	cout << ret;
  return 0;
}
