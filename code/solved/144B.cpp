// #pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define vi vector<int>

int r_x[1010], r_y[1010], r_r[1010];
int n;

float dist(int x1, int y1, int x2, int y2)
{
    return sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
}

int check(int x, int y)
{
    for (int i = 0; i < n; ++i)
    {
        if ((dist(x, y, r_x[i], r_y[i])) <= r_r[i])
        {
            return 0;
        }
    }
    return 1;
}

void solve()
{
    int x1, y1, x2, y2;
    scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d %d %d", &r_x[i], &r_y[i], &r_r[i]);
    }
    int ans = 0;

    for (int i = min(x1, x2); i <= max(x1, x2); ++i)
    {
        ans += check(i, y1) + check(i, y2);
    }
    for (int i = min(y1, y2) + 1; i < max(y1, y2); ++i)
    {
            ans += check(x1, i) + check(x2, i);
    }
    
    printf("%d", ans);
    return;
}

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}