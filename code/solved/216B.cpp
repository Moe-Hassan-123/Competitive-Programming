#include <bits/stdc++.h>
using namespace std;
#define FASTIO                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define pp pop_back

vi parent{0};
bool is_visited[100]{0};
int cycle_start, cycle_end;

int dfs(vi const (&graph)[], int cur, int par)
{
    // Find ONE path to the end
    // if it leads back to a visited node
    // Then a cycle was found
    is_visited[cur] = 1;
    for (const int &next : graph[cur])
    {
        if (next == par) continue;
        if (is_visited[next])
        {
            cycle_end = cur;
            cycle_start = next;
            return true;
        }
        parent[next] = cur;
        if (dfs(graph, next, parent[next]))
            return true;
    }
    return false;
}

int main()
{
    FASTIO;
    // freopen("input.in", "r", stdin);
    int n, e;
    scanf("%d%d", &n, &e);
    vi graph[n];
    parent.reserve(n);
    int n1, n2;
    for (int i = 0; i < e; ++i)
    {
        scanf("%d %d", &n1, &n2);
        // Indexing should start from 0 not 1
        --n1;--n2;
        // Undirected Graph
        graph[n1].pb(n2);
        graph[n2].pb(n1);
    }
    int odd_cycles = 0;
    for (int i = 0; i < n; ++i)
    {
        if (!is_visited[i])
        {
            if (dfs(graph, i, i))
            {
                int count = 1; // to account for cycle start
                for (int v = cycle_end; v != cycle_start; v = parent[v])
                {
                    count += 1;
                }
                if (count & 1 == 1)
                {
                    odd_cycles += 1;
                }
            }
        }
    }
    if ((n-odd_cycles) & 1 == 1)
    {
        odd_cycles += 1;
    }
    printf("%d\n", odd_cycles);
    return 0;
}
