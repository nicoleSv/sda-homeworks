#include <iostream>
#include <vector>
#define N 100001
#define MOVE_TOWARDS 0
#define MOVE_AWAY 1

using namespace std;

vector<int> graph[N];
int start[N] = {0};
int finish[N] = {0};

int timer = 1;
void dfs(int s)
{
    start[s] = timer++;
	
    for (int i : graph[s])
		dfs(i);
		
    finish[s] = timer++;
}

int main()
{
    int nodes;
    cin >> nodes;
    
    for(int i = 0; i < nodes-1; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    dfs(1);
    
    int queries;
    cin >> queries;
    
    for(int i = 0; i < queries; i++)
    {
        int move, x, y;
        cin >> move >> x >> y;
        if(move == MOVE_TOWARDS)
        {
            if(start[y] > start[x] && finish[y] < finish[x]) cout << "YES\n";
            else cout << "NO\n";
        }   
        else if(move == MOVE_AWAY)
        {
            if(start[y] < start[x] && finish[y] > finish[x]) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}
