#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int) (x).size())
#define vi vector<int>

const int MAX = 100010;

void solve()
{
    int n;
    scanf("%d", &n);
    map<int, pair<int, int>> answers;
    vector<bool> is_valid (MAX, 1);
    int tmp;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &tmp);

        if (!is_valid[tmp])
            continue;

        if (answers.contains(tmp))
        {
            if (answers[tmp].first == 0)
            {
                answers[tmp].first = (i - answers[tmp].second);
                answers[tmp].second = i;
            }
            else
            {
                if (!((i - answers[tmp].second)  == answers[tmp].first))
                {
                    answers.erase(tmp);
                    is_valid[tmp] = 0;
                }
                else
                {
                    answers[tmp].second = i;
                }
            }
        }
        else
        {
            answers[tmp].first = 0;
            answers[tmp].second = i;
        }
    }

    printf("%d\n", sz(answers));
    for (auto &[key,val]: answers)
    {
        printf("%d %d\n", key, val.first);
    }
}

int32_t main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    #endif
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}