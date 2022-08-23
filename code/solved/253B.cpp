#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int) (x).size())
#define f first
#define s second


// Gets the index of Greatest number smaller than (arr[cur] * 2) in the vector arr
int binary(vector<float>& arr, int cur)
{
    int min = cur;
    int max = sz(arr)-1;
    int mid;
    while (min != max)
    {
        mid = (min + max) >> 1;
        if (arr[mid] <= (arr[cur] * 2))
        {
            if (mid == min)
            {
                if (arr[max] <= (arr[cur] * 2))
                    return max;
                else
                    return min;
            }
            else min = mid;
        }
        else
        {
            max = mid - 1;
        }
    }
    return max;
}

void solve()
{
    int n;
    cin >> n;

    vector<float> arr(n);
    for (int i = 0; i < n; ++i)
    {   
        cin >> arr[i];
    }

    sort(all(arr));
    int cur = 0;
    int min = 1e9;
    while (cur <= n-1)
    {    
        // the number of deleted elements is the value of
        // the current starting index + the deleted indeces from the end
        int num_deleted = cur + (sz(arr) - binary(arr, cur) - 1);
        if (num_deleted < min)
            min = num_deleted;

        ++cur;
    }
    cout << min << "\n";
}


int32_t main()
{
    FASTIO;
    freopen("input.txt","r",stdin);
    freopen("output.txt", "w", stdout);
    int t = 1;
    // cin >> t;

    #ifndef ONLINE_JUDGE

    auto t1 = chrono::high_resolution_clock::now();

    #endif

    while (t--)
    {
        solve();
    }
    
    #ifndef ONLINE_JUDGE

    auto t2 = chrono::high_resolution_clock::now();
    cout << ( chrono::duration<double, std::milli>(t2 - t1).count() )<< " ms\n";

    #endif

    return 0;
}