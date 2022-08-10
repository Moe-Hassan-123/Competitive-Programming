#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
const int MAX = 100000;


vb is_visited (MAX);
vvi graph (MAX);
deque<int> top_stack;

void top_sort(int v)
{
    is_visited[v] = 1;
    for (const int& next: graph[v])
    {
        if (is_visited[next]) continue;
        top_sort(next);
    }
    top_stack.push_back(v);
    return;
}

void solve()
{
    int e, n, nu, tmp;
    cin >> n >> e;
    graph.resize(e);
    is_visited.resize(n);
    for (int i = 0; i < e; ++i)
    {
        cin >> nu;
        for (int j = 0; j < nu; ++j)
        {
            cin >> tmp;
            graph[i].push_back(tmp-1);
        }
    }
    for (int i = 0; i < n; ++i)
    {
        if (is_visited[i]) continue;
        top_sort(i);
    }
    int ans[n] {0};
    int pos = 0;
    for (int i = 0; i < n; ++i)
    {
        int cur = top_stack.back();
        ans[cur] = pos;
        pos = cur+1;
        top_stack.pop_back();
    }
    for(const int& i: ans)
    {
        cout << i << "\n";
    }
}

int main()
{
    FASTIO;
    // freopen("input.in","r",stdin);
    solve();
    return 0;
}

