#include <iostream>
#include <vector>
#define N 100001

using namespace std;
 
vector < int > edge[N], bridges[N];
int discovery[N], low[N], parent[N];
bool visited[N];
 
void dfs (int s)
{
    static int time = 0;
    time++;
    low[s] = time;
    discovery[s] = low[s];
    visited[s] = true;
 
    for (int i = 0; i < edge[s].size(); i++)
    {
        int v = edge[s][i];
 
        if (v == parent[s])
            continue;
 
        else if (visited[v])
            low[s] = min (low[s], discovery[v]);
 
        else
        {
            parent[v] = s;
            dfs(v);
            low[s] = min (low[s], low[v]);
 
            if (discovery[s] < low[v])
            {
                
                bridges[s].push_back(v);
                bridges[v].push_back(s);
            }
        }
    }
}
 
int main()
{
    int x, y, nodes, edges, queries, A[N], B[N];
    cin >> nodes;                                 
    cin >> edges;                                    
 
    for(int i = 0; i < edges; ++i) {
 
        cin >> x >> y;
        edge[x].push_back(y);        
        edge[y].push_back(x);
        A[i] = x;
        B[i] = y;
    }
 
    for (int i = 1; i <= nodes; i++)
    {
        
        if (!visited[i])
            dfs(i);
    }
    
    cin >> queries;
    
    while (queries--)
    {
        
        cin >> x;
        int flag = 0;
        for (int i = 0; i < bridges[A[x - 1]].size(); i++)
        {
            
            if (bridges[A[x - 1]][i] == B[x - 1])
            {
                
                cout << "Unhappy" << endl;
                flag = 1;
            }
        }
        
        if (!flag)
            cout << "Happy" << endl;
    }
 
    return 0;
}
