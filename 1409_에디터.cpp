#include <iostream>
#include <string>
#include <stack>
int main()
{
	std::stack<char> left, right;
	std::string text;
	int M = 0;
	char op;
	
	std::cin >> text >> M;
	
	for(const auto c: text)
	{
		left.push(c);
	}
    while(M--)
    {
        std::cin >> op; 
        if (op == 'L')
        {
            if (left.empty()) continue;
            right.push(left.top());
            left.pop();
        }
        else if (op == 'D')
        {
            if (right.empty()) continue;
            left.push(right.top());
            right.pop();
        }
        else if (op == 'B')
        {
            if (left.empty()) continue;
            left.pop();
        }
        else if (op == 'P')
    	{
            std::cin >> op;
            left.push(op);
        }
    }
    
	while(!left.empty())
	{
		right.push(left.top());
		left.pop();
	}
	while(!right.empty())
	{
		std::cout << right.top();
		right.pop();
	}
    return 0;
}
