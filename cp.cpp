#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int) (x).size())
#define vi vector<int>
#define pii pair<int, int>

void unioqize(vi& arr)
{
    auto s = unique(all(arr));
    arr.erase(s, arr.end());
}

void solve()
{
    int n;
    vi nums(n),uni(n);
    for (int i = 0;i < n; ++i)
    {
        scanf("%d", &nums[i]);
        uni[i] = nums[i];
    }
    auto u = unique(all(uni));
    uni.erase(u, uni.end());
    while (1)
    {
    if (sz(uni) == sz(nums))
        unioqize(uni);
        if 
    }
}

int32_t main()
{
    FASTIO;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    #endif
    int t = 1;
    scanf("%d", &t);
    while (t--)
    {
        solve();
    }
    return 0;
}