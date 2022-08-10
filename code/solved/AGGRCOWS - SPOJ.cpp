#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
#define vi vector<int> 
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int) (x).size())


bool is_pos(vi arr, int mid, int size, int cows)
{
    int placed = 1, distance = arr[0];
    for (int i = 1; i < size; ++i)
    {
        if (arr[i] - distance >= mid)
        {
            placed += 1;
            distance = arr[i];
        }
        if (placed == cows) return true;
    }
    return false;
    }

void solve()
{
    int n,c, tmp;
    cin >> n >> c;
    vi cows (0);
    cows.reserve(n);
    while (n--)
    {
        cin >> tmp;
        cows.push_back(tmp);
    }
    int low, high, mid, ans=0;
    sort(all(cows));
    low = cows[0];
    high = cows[sz(cows)-1] - cows[0];
    while (low <= high)
    {
        mid = (low + high) >> 1;
        if (is_pos(cows, mid, sz(cows), c))
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << ans << "\n";
    return;
}


int main()
{
    FASTIO;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}