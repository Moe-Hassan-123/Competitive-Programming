#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>

const int MAX = 100;
vvi graph (MAX);
vb is_visited (MAX);
deque<int> top_result (MAX);


void reset_all()
{
    graph.clear();
    is_visited.clear();
    top_result.clear();
}


void top_sort(int i)
{
    is_visited[i] = 1;
    for (const int &next: graph.at(i))
    {
        if(is_visited[next]) continue;
        top_sort(next);
    }
    top_result.push_back(i);
}


void solve()
{
while(true)
{
    int t, n;
    cin >> t >> n;
    if (t + n == 0) break;
    graph.resize(t);
    is_visited.resize(t);
    top_result.resize(t);
    int from, to;
    for (int i = 0; i < n; ++i)
    {
        cin >> from >> to;
        graph.at(from-1).push_back(to-1);
    }
    for (int i = 0; i < t; ++i)
    {
        if (is_visited.at(i)) continue;
        top_sort(i);
    }
    for(int i = 0; i < t; ++i)
    {
        cout << top_result.back() + 1 << " ";
        top_result.pop_back();
    }
    cout << "\n";
    reset_all();
}
}


int main()
{
    FASTIO;
    solve();
    return 0;
}