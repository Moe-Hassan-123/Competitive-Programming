// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define FASTIO                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int) (x).size())
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>


bool is_win(string& config)
{

    bool row = ( config[0] != '.' && config[0] == config[1] && config[1] == config[2] ||
                 config[3] != '.' && config[3] == config[4] && config[4] == config[5] ||
                 config[6] != '.' && config[6] == config[7] && config[7] == config[8] );
                 
    bool col = ( config[0] != '.' && config[0] == config[3] && config[3] == config[6] ||
                 config[1] != '.' && config[1] == config[4] && config[4] == config[7] ||
                 config[2] != '.' && config[2] == config[5] && config[5] == config[8] );

    bool diagonal = ( config[0] != '.' && config[0] == config[4] && config[4] == config[8] ||
                      config[2] != '.' && config[2] == config[4] && config[4] == config[6] );

    return (row || col || diagonal);
}

bool solve( string& grid )
{
    string start = ".........";
    queue<pair<string, bool>> qu;
    qu.push( {start, 1} );
    while(sz(qu))
    {
        string config = qu.front().first;
        bool cur = qu.front().second;
        qu.pop();


        if(is_win(config))
            if(config == grid) return true;
            else continue;
        if (config == grid)
            return (count(all(grid), '.') == 0) ? true: false;

        for (int i = 0; i < 9; ++i)
        {
            if (config[i] == '.')
            {
                config[i] = cur ? 'X': 'O';
                if (config[i] == grid[i])
                    qu.push( { config, 1 ^ cur } );
                config[i] = '.';
            }
        }
    }
    return false;
}

int32_t main()
{
    FASTIO;
    string t;
    while (1)
    {
        cin >> t;
        if (t == "end") break;
        cout << (solve(t) ? "valid" : "invalid") << "\n";
    }
    return 0;
}