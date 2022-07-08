#include <iostream>
#include <list>
#include <string>
#include <stack>
#include <vector>
#include<algorithm>
int main()
{
	int T = 0; std::cin >> T;
	while(T--)
	{
    std::string code; std::cin >> code;
    std::stack<char> c1, c2;
    
    char temp; char c;
    for(int i=0; i<code.length(); ++i)
    {
        c = code[i];
        if(c == '<')
        {
            if(c1.empty()) continue;
            c2.push(c1.top());
            c1.pop();
        }
        else if(c == '>')
        {
            if(c2.empty()) continue;
            c1.push(c2.top());
            c2.pop();
            
        }
        else if(c == '-')
        {
            if(c1.empty()) continue;
            c1.pop();
        }
        else
            c1.push(c);
    }
    
	std::string result;
    while (!c2.empty())
    {
		c1.push(c2.top());
		c2.pop();
	}
    while(!c1.empty())
    {
		result += c1.top();
		c1.pop();
	}
	
	std::reverse(result.begin(), result.end());
	std::cout << result <<'\n';
	if(T==0) break;
    
	}
    return 0;
}
