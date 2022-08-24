#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int) (x).size())
#define vi vector<int>
#define f first
#define s second

////////////// Prewritten code follows. ////////////////

#define foreach(x, v) for (typeof (v).begin() x=(v).begin(); x !=(v).end(); ++x)
#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define D(x) cerr << #x " is " << (x) << endl

const double EPS = 1e-9;


// 1 if x is bigger, -1 is y is bigger, 0 if equals
int cmp(double x, double y) {
    return (x <= y + EPS) ? (x + EPS < y) ? -1 : 0 : 1;
}

////////////////////////// Solution starts below. //////////////////////////////

struct node {
    int x;
    int y;
};


string solve(node target)
{
    node left, right, mid;    
    mid = {1, 1};
    left = {0, 1};
    right = {1, 0};
    string result;
    while (true)
    {
        double val_mid = ((double) mid.x / mid.y);
        double val_target = ((double) target.x / target.y);
        switch (cmp(val_mid, val_target))
        {
        case 0: // equals
            return result;
            break;
        case 1: // mid is bigger
            right = mid;
            mid.x += left.x;
            mid.y += left.y;
            result += "L";
            break;
        case -1: // cur is bigger
            left = mid;
            mid.x += right.x;
            mid.y += right.y;
            result += "R";
            break;
        }
    }
}

int32_t main()
{
    FASTIO;
    node a;
    cin >> a.x >> a.y;
    while (true)
    {
        if (a.x + a.y == 2) break;
        cout << solve(a) << "\n";
        cin >> a.x >> a.y;
    }
    return 0;
}