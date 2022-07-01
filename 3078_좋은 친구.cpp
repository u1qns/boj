#include <iostream>
#include <string>
#include <queue>

int main()
{
    int N = 0, K =0;
    long long result = 0;
    std::queue<int> students[21];
    std::string name;

    std::cin >> N >> K;
    for(int i=0; i<N; ++i)
    {
        std::cin >> name;
        while(!students[name.length()].empty() && i - students[name.length()].front() > K)
            students[name.length()].pop();    
        result+=students[name.length()].size();
        students[name.length()].push(i); // ex) students[2] = 3 // 글자수가 2인 3등을 표현
    }
    std::cout << result;
    return 0;
}
