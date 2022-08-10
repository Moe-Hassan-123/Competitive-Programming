#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define FASTIO iostream::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()

void solve(vi &arr)
{
    int size = sz(arr);
    vi maximal (size);
    int last, max;
    for (int i = 0; i < size; ++i)
    {
        last = max = arr[i];
        for (int j = i; j < size; ++j)
        {
            if(last != max && last < arr[j]) break;
            if (last < arr[j]) max = arr[j];
            last = arr[j];
            maximal[i] += 1;
        }
    }
    cout << *max_element(all(maximal));
    return;
}

int main()
{
    FASTIO;
    int t, tmp;
    vi arr;
    cin >> t;
    arr.reserve(t);
    while(t--)
    {
        cin >> tmp;
        arr.push_back(tmp);
    }

    solve(arr);
}