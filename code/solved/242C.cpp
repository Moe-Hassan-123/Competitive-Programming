#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int) (x).size())
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>


struct hash_function
{
  size_t operator()(const pair<int ,int> &x) const
  {
    return x.first ^ x.second;
  }
};

map<pii, bool> visited;
map<pii, int> dist;
map<pii, unordered_set<pii, hash_function>> graph;


int bfs(pii& start, pii& end)
{
    queue<pii> qu;
    qu.push(start);

    visited[start] = 1;
    dist[start] = 0;

    pii cur;
    while (sz(qu))
    {
        cur = qu.front();
        qu.pop();
        for(const pii& next: graph[cur])
        {
            if (visited[next]) continue;
            visited[next] = 1;
            dist[next] = dist[cur] + 1;
            qu.push(next);
            if (next ==  end) return dist[next];
        }
    }
    return -1;
}

void link(int row, int col)
{
    visited[{row, col}] = 0;
    dist[{row, col}] = 0;
    for (int i = -1; i < 2; ++i)
    {
        for (int j = -1; j < 2; ++j)
        {
            if ((!(i == 0 && j == 0)) && graph.contains({row+i, col+j}))
            {
                graph[{row+i, col+j}].insert({row, col});
                graph[{row, col}].insert({row+i, col+j});                
            }
        }
    }
}

int solve()
{
    pii start, end;
    cin >> start.first >> start.second >> end.first >> end.second;
    int t;
    cin >> t;
    int row, start_col,end_col;
    while ( t-- )
    {
        cin >> row >> start_col >> end_col;
        
        // Corner Case
        if (start_col == end_col) 
        {
            graph[{row, start_col}];
            link(row, start_col);
        }
        for (int col = start_col; col < end_col; ++col)
        {
            graph[{row, col}].insert({row, col+1});
            graph[{row, col+1}].insert({row, col});
            link(row, col);
            if (col == end_col-1) link(row, col+1);
        }
    }
    return bfs(start, end);
}

int32_t main()
{

    FASTIO;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    #endif
    int n = 1;
    // cin >> n;
    while (n--)
    {
        cout << solve();
    }
    return 0;
}