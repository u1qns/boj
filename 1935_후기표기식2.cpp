#include <iostream>
#include <stack>
#include <string>

double calculator(double a, double b, char op)
{
    if(op == '+') return a + b;
    else if(op == '-') return b - a;
    else if(op == '/') return b / a;
    else if(op == '*') return a * b;
}

int main()
{
    int N = 0, result = 0;
    std::string str;
    double nums[27];
    std::stack<double> stk;

    std::cin >> N >> str;
    for(int i =0; i< N; ++i)
    {
        std::cin >> nums[i];
    }


    int idx = 0;
    for(int i =0; i <str.length(); ++i)
    {
        char c = str[i];
        if(65 <= c && c <= 90)
        {
            stk.push(nums[c-65]);
        }
        else
        {
            double a = stk.top(); stk.pop();
            double b = stk.top(); stk.pop();
            stk.push(calculator(a, b, c));
        }
    }

    printf("%0.2lf", stk.top());
    return 0;

}
