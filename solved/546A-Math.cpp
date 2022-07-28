#include <bits/stdc++.h>
#include <numeric>
#define int long long

int32_t main()
{
    std::ios_base::sync_with_stdio(false);
    int cost, m, n;
    scanf("%lld %lld %lld", &cost, &m, &n);
    int total = 0;  
    for (int i = 0; i < n; ++i)
    {
        total += cost * (i+1);
    }
    int diff = total-m;
    if (diff < 0) printf("0");
    else printf("%lld\n",total- m);
    return 0;
}