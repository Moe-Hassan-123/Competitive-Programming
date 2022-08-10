#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define FASTIO                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define vi vector<int>
#define int long long int

int low(vi &arr, int &val)
{
    int i;
    if (arr[0] >= val)
        return -1;
    for (i = 0; i < arr.size(); ++i)
    {
        if (arr[i] >= val) break;
    }
    return arr[i-1];
}


int up(vi &arr, int &val)
{
    int low, high, mid;
    high = arr.size()-1;
    low = 0;
    if (arr[high] <= val)
        return -1;
    while (low != high)
    {
        mid = (low + high)/2;
        if (arr[mid] <= val) low = mid + 1;
        else high = mid;
    }
    return arr[high];
}


void solve(vi &arr, int &val)
{
    int sz = arr.size();
    int upper, lower;
    lower = low(arr, val);
    upper = up(arr, val);
    // Print Answers
    if (lower == -1)
        cout << "X";
    else
        cout << lower;
    cout << " ";
    if (upper == -1)
        cout << "X";
    else
        cout << upper;
    cout << "\n";
}

int32_t main()
{
    FASTIO;
    freopen("input.in", "r", stdin);
    int n, nn, tmp;
    cin >> n;
    vi arr;
    arr.reserve(n);
    while (n--)
    {
        cin >> tmp;
        arr.push_back(tmp);
    }
    cin >> nn;
    while (nn--)
    {
        cin >> tmp;
        solve(arr, tmp);
    }
}