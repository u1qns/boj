#include <iostream>
#include <stack>
#include <string>

int main() 
{
    //input
    std::string input; std::cin >> input;

    //solve
    std::stack <char> op;
    std::string result;

	for (int i = 0; i < input.size(); ++i)
    {
        //문자열
		if (input[i] >= 'A' && input[i] <= 'Z')
			result += input[i];
		else 
        {
                // 연산자 
				if (input[i] == '(')
					op.push(input[i]);

				else if (input[i] == ')') {
					while (1) 
                    {
						char temp = op.top();
						op.pop();
                        
						if (temp == '(')
							break;
						result += temp;
					}
				}
				else if (input[i] == '+' || input[i] == '-') {
					while (!op.empty() && op.top() != '(')
                    {
						result += op.top();
						op.pop();
					}
					op.push(input[i]);
								
				}
				else if (input[i] == '*' || input[i] == '/') {
					while (!op.empty() && (op.top() == '*' || op.top() == '/'))
                    {
						result += op.top();
						op.pop();
					}
					op.push(input[i]);
					
				}


		}

	}

	while (!op.empty())
    {
		result += op.top();
		op.pop();
	}
    
    //output
	std::cout << result;
	return 0;
}
