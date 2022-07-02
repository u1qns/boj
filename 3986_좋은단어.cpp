#include <iostream>
#include <string>
#include <stack>

int main()
{
    int N = 0, result = 0;
    std::string word;

    std::cin >> N;
    for(int i=0; i<N; ++i)
    {
        std::stack<char> stk;
        std::cin >> word;
        for(auto& c : word)
        {
            if(!stk.empty() && stk.top() == c)
                stk.pop();
            else
                stk.push(c);
        }

        if(stk.empty()) ++result;
    }
    std::cout << result;
    return 0;
}
