#include <iostream>
#include <queue>
#define MAX 1001
bool visited[MAX] = {false, };
int arr[MAX][MAX];
int N;



void BFS(int v)
{
    bool visited[MAX] = {false, };
    std::queue<int> q;
    
    q.push(v);
    visited[v] = true;
    std::cout << v << " ";
    
    while(!q.empty())
    {
    	v = q.front(); q.pop();
        
	    for(int i = 1; i <= N; ++i)
	    {	
	        if(arr[v][i] && visited[i] == false)
	        {
	        	q.push(i);
	            visited[i] = true;
	            std::cout << i << " ";
	        }
		 }
    }
    

}

void DFS(int v)
{
    visited[v] = true;
    std::cout << v << " ";
    
    for(int i =1; i<=N; ++i)
    {
        if(arr[v][i] && visited[i] == false)
        {
            DFS(i);
        }
    }
}

int main()
{
    int a =0, b =0;
    int M =0, V = 0;
    std::cin >> N >> M >> V;
    
    while(M--) // 간선 개수만큼 읽어들이면 됨
    {
        std::cin >> a >> b;
        arr[a][b] = arr[b][a] = true;
    }
    
    DFS(V);

  	for(int i =0; i<=N; ++i)
    {
      visited[i] = false;
    }
    std::cout << "\n";
    
    BFS(V);
    
        
    return 0;
}
