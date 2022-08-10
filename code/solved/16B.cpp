#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define FASTIO iostream::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define vi vector<int>
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>

bool comb(const pii &a, const pii &b)
{
    return a.first > b.first;
}

int main()
{
    FASTIO;
    int cap, n;
    cin >> cap >> n;
    pii tmp;
    vector<pii> containers;
    while (n--)
    {
        cin >> tmp.second >> tmp.first;
        containers.push_back(tmp);
    }
    sort(all(containers), comb);
    int ans = 0;
    for (auto &i: containers)
    {
        if (i.second <= cap)
        {
            cap -= i.second;
            ans += i.first * i.second;
        }
        else
        {
            ans += i.first * cap;
            cap = 0;
        }
    }
    cout << ans;
}
