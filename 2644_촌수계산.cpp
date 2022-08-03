#include <iostream>
#include <vector>
#define MAX 100

std::vector<std::vector<int>> graph;
bool visited[MAX+1];
int n, a, b, m;
int result = 0;

bool DFS(int v)
{
    if(v == b) return true;
    
    ++result;
    visited[v] = true;
    
    //연결된 노드만 탐색
    for(int i=0; i <graph[v].size(); ++i)
    {
        //방문하지 않은 노드가 있다면
        if(!visited[graph[v][i]])
        {
            //탐색 시작
            if(DFS(graph[v][i])) return true;
            else --result; // 이어지는 촌수가 없다면 다시 촌수 올라가야하니까 빼줌
        }
    }
    
    return false;
}


int main()
{
    int x, y =0
    std::cin >> n >> a >> b >> m;
    
    graph.assign(n+1,std::vector<int>(0, 0));
    
    while(m--)
    {
        std::cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    
    //DFS(a); std::cout << result;
    std::cout << (DFS(a) ? result : -1);
    return 0;
}
