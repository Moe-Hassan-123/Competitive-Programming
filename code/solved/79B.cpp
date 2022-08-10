#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long int
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define sz(x) ((int) (x).size())

int rows, cols, w, queries;
vector<int> wasted(1000);
char choices[3] {'C', 'K', 'G'};

int at(int x, int y)
{
    return (x * cols) + y;
}

char get_ans(int x, int y)
{
    int pos = at(x,y);
    auto off_put = (int)(lower_bound(all(wasted), pos) - wasted.begin());
    if (wasted[off_put] == pos) return 'W';
    else
    {
        return choices[(pos-off_put) % 3];
    }
    return 'X';
}

void solve()
{
    scanf("%lld %lld %lld %lld", &rows, &cols, &w, &queries);
    int x,y;
    wasted.resize(w);
    for (int i = 0; i < w; ++i)
    {
        cin >> x >> y;
        wasted[i] = at(x-1, y-1);
    }
    sort(all(wasted));
    char choices[3] {'C', 'K', 'G'};
    int cur = 0;
    
    while (queries--)
    {
        cin >> x >> y;
        switch (get_ans(x-1,y-1))
        {
        case 'W':
            printf("Waste\n");
            break;
        case 'G':
            printf("Grapes\n");
            break;
        case 'K':
            printf("Kiwis\n");
            break;
        case 'C':
            printf("Carrots\n");
            break;
        }
    }
}

int32_t main()
{
    // FASTIO;
    // freopen64("input.txt","r",stdin);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}