#include <bits/stdc++.h>
using namespace std;
#define FASTIO                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define pi pair<int, int>

struct rectangle
{
    int x_s;
    int y_s;
    int x_e;
    int y_e;
};

void solve()
{
    int x_s, y_s, x_e, y_e;
    cin >> x_s >> y_s >> x_e >> y_e;
    rectangle rect1{x_s, y_s, x_e, y_e};
    cin >> x_s >> y_s >> x_e >> y_e;
    rectangle rect2{x_s, y_s, x_e, y_e};
    // Determine if the graph Overlabs
    if (rect1.x_s > rect2.x_e || rect2.x_s > rect1.x_e || rect1.y_s > rect2.y_e || rect2.y_s > rect1.y_e)
    {
        cout << "No Overlap";
        return;
    }
    // Finding The Overlab
    x_s = max(rect1.x_s, rect2.x_s);
    y_s = max(rect1.y_s, rect2.y_s);
    x_e = min(rect1.x_e, rect2.x_e);
    y_e = min(rect1.y_e, rect2.y_e);
    if (y_e == y_s || x_s == x_e) // Meeting on one edge only
    {
        cout << "No Overlap";
        return;
    }
    printf("%d %d %d %d", x_s, y_s, x_e, y_e);
}

int main()
{
    freopen("input.in", "r", stdin);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        if (t != 1)
        {
            printf("\n\n");
        }
        else{
            printf("\n");
        }
    }
}