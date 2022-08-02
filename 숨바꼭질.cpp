#include <iostream>
#include <queue>
#define MAX 100000

std::queue<int> q;
bool visited[MAX + 1];

bool isValid(int num)
{
    if(num >= MAX || num < 0)
        return false;
        
    return true;
}

int BFS(int K)
{
    int sec = 0;
    int data = 0;
    
    while(1)
    {
        int qSize = q.size();
        for(int i=0; i<qSize; ++i)
        {
            data = q.front(); q.pop();
            if(data == K)
            {
                return sec;
            }
            
            if(isValid(data-1) && !visited[data-1])
            {
                visited[data-1] = true;
                q.push(data-1);
            }
        
            if(isValid(data+1) && !visited[data+1])
            {
                visited[data+1] = true;
                q.push(data+1);
            }
        
            if(isValid(data<<1) && !visited[data<<1])
            {
                visited[data<<1] = true;
                q.push(data<<1);
            }
        }
        sec++;
    }
}

int main()
{
    
    int N=0, K=0;
    std::cin >> N >> K;
    
    visited[N] = true;
    q.push(N);
    std::cout << BFS(K);
    
    return 0;
}
