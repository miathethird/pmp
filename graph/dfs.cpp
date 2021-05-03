#include <map>
#include <vector>
#include <stack>
#include <iostream>

class Graph
{
    std::vector<bool> visited;
    std::map<int, std::vector<int>> adj;
    int N = 0;

    public:
    Graph(int n)
    {
        N = n-1;
        for(int i=0; i<n; i++)
        {
            visited.push_back(false);
        }
    }

    void addEdges(int vertex, std::vector<int> edges)
    {
        adj.emplace(vertex, edges);
    }

    void clearVisited()
    {
        for(auto i : visited) 
        {
            i = false;
        }
    }

    void dfs_iterative(int startVx)
    {
        std::stack<int> stack;
        stack.push(startVx);

        while(!stack.empty())
        {
            int v = stack.top();
            stack.pop();
            if(visited[v]) continue;
            std::cout << v << " ";
            visited[v] = true;
            
            for(std::vector<int>::iterator i = adj[v].begin(); i!= adj[v].end(); i++)
            {
                if(!visited[*i]) stack.push(*i);
            }
        }
    }

    void dfs_recursive(int Vx)
    {
        if(visited[Vx]) return;
        std::cout << Vx << " ";
        visited[Vx] = true;

        for(std::vector<int>::iterator i = adj[Vx].begin(); i!= adj[Vx].end(); i++)
        {
            if(!visited[*i]) dfs_recursive(*i);
        }
    }
};

int main()
{
    Graph g(8);
    g.addEdges(0, {2,7});
    g.addEdges(1, {6});
    g.addEdges(2, {3,7});
    g.addEdges(3, {7,1});
    g.addEdges(4, {7});
    g.addEdges(5, {4});
    g.addEdges(6, {5});
    g.addEdges(7, {});

    g.dfs_iterative(0);
    g.clearVisited();
    std::cout << std::endl;
    g.dfs_recursive(0);

    return 0;
}