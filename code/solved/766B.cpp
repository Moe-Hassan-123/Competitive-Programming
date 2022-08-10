#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>

bool solve()
{
    int n;
    cin >> n;
    vi sides (n);
    for (int i = 0; i < n; ++i)
    {
        cin >> sides[i];
    }
    sort(all(sides));
    for (int i = 0; i < n-2; ++i)
    {
        if (sides[i] + sides[i+1] > sides[i+2])
        {
            return true;
        }
    }
    return false;
}

int32_t main()
{
    FASTIO;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        cout << (solve()? "YES": "NO");
    }
    return 0;
}