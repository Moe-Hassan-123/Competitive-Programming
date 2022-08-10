#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
#define ll unsigned long long int
#define vi vector<long long int>
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())


vi get_ans(vi& arr)
{
    vi ans (sz(arr));
    ans[0] = arr[0];
    for (int i = 1; i < sz(arr); ++i)
    {
        ans[i] = ans[i-1] + arr[i];
    }
    return ans;
}

int32_t main()
{
    FASTIO;
    int n, q;
    cin >> n;
    vi uord (n); 
    vi ord (n);
    for (int i = 0; i < n; ++i)
    {
        cin >> uord[i];
        ord[i] = uord[i];
    }
    sort(all(ord));
    vi Oans = get_ans(ord);
    vi Uans = get_ans(uord);
    cin >> q;
    int t, s, e;
    ll ans;
    while (q--)
    {
        cin >> t >> s >> e; 
        --e;--s;
        if ( t & 1 )
        {
            if (s == 0 || e == 0)
                ans = Uans[e];
            else if (s == e)
                ans = uord[s];
            else
                ans = Uans[e] - Uans[s-1];
        }
        else
        {
            if (s == 0 || e == 0)
                ans = Oans[e];
            else if (s == e)
                ans = ord[s];
            else
                ans = Oans[e] - Oans[s-1];
        }
        cout << ans << "\n";
    }
    return 0;
}