// #pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

////////////// Prewritten code follows. ////////////////

#define FASTIO                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define foreach(x, v) for (typeof(v).begin() x = (v).begin(); x != (v).end(); ++x)
#define D(x) cerr << #x " is " << (x) << endl

#define f first
#define s second
#define pb push_back

const double EPS = 1e-9;

// 1 if x is bigger, -1 is y is bigger, 0 if equals
int cmp(double x, double y)
{
    return (x <= y + EPS) ? (x + EPS < y) ? -1 : 0 : 1;
}

////////////////////////// Solution starts below. //////////////////////////////



const int N = 100 + 10;
vector<vector<pair<int, int>>> graph (N);
bool visited[N][N];

void dfs(int cur_node, int cur_color)
{
    visited[cur_node][cur_color] = 1;

    for (auto& next: graph[cur_node])
    {

        if(next.s != cur_color || visited[next.f][next.s])
            continue;
        dfs(next.f, next.s);
    }
}

void solve()
{
    int n, e;
    cin >> n >> e;
    int t1, t2, c;
    for (int i = 0; i < e; ++i)
    {
        cin >> t1 >> t2 >> c;
        graph[t1].pb({t2, c});
        graph[t2].pb({t1, c});
    }
    int q;
    cin >> q;
    while (q--)
    {
        cin >> t1 >> t2;
        int sum = 0;
        for (int cc = 1;cc <= e; ++cc)
        {
            dfs(t1, cc);
            sum += visited[t2][cc];          
        }
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                visited[i][j] = 0;
            }
        }
        cout << sum << "\n";
    }
}

int32_t main()
{
    FASTIO;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
#ifndef ONLINE_JUDGE
    auto t1 = chrono::high_resolution_clock::now();
#endif

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }

#ifndef ONLINE_JUDGE
    auto t2 = chrono::high_resolution_clock::now();
    cout << ( chrono::duration<double, std::milli>(t2 - t1).count() )<< " ms\n";
#endif

    return 0;
}