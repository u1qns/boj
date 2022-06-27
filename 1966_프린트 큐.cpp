#include <iostream>
#include <queue>

int main()
{
    int T= 0;
    std::cin >> T;
    
    while(T--)
    {
        int result = 0;
        int N=0, M=0, v=0;
        std::queue<std::pair<int, int>> q;
        std::priority_queue<int> sorted;
        
        //input
        std::cin >> N >> M;
        for(int i=0; i<N; ++i)
        {
            std::cin >> v;
            q.push(std::make_pair(i, v));
            sorted.push(v);
        }
        
        //solve
        while(!q.empty())
        {
            int index = q.front().first;
            int value = q.front().second;
            
            if(sorted.top() == value)
            {
                sorted.pop();
                ++result;
                if(index == M) break;
            }
            else
            {
                q.push(std::make_pair(index, value));
            }
            q.pop();
        }
        
        //output
        std::cout << result << std::endl;
    }
    
    return 0;
}



