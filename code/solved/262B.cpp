// #pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define FASTIO                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define vi vector<int>
#define pii pair<int, int>

void solve()
{
    int n, swaps, tmp;
    cin >> n >> swaps;
    priority_queue<int, vi, greater<int>> arr;
    while (n--)
    {
        cin >> tmp;
        arr.push(tmp);
    }
    
    int val;
    while (swaps--)
    {
        val = arr.top();
        arr.pop();
        val *= -1;
        arr.push(val);
    }

    int ans = 0;
    while(sz(arr))
    {
        ans += arr.top();
        arr.pop();
    }
    cout << ans;
}

int32_t main()
{
    FASTIO;
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