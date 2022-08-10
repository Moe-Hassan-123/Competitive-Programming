    #pragma GCC optimize("Ofast")
    #include <bits/stdc++.h>
    #include <cctype>
    using namespace std;
    #define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #define vi vector<int>
    #define pii pair<int, int>
    #define all(x) (x).begin(), (x).end()
    #define sz(x) ((int) (x).size())

    int rows, cols;
    double mx;
    vector<pii> shifts;

    double min_dist(int x, int y)
    {
        double minimal = 1e9;
        for (pii& shift: shifts)
        {
            double dist = sqrt(pow(x-shift.first, 2) + pow(y-shift.second, 2));
            if (dist < minimal)
                minimal = dist;
        }
        return minimal;
    }

    int at(int x, int y)
    {
        return (x * cols) + y;
    }

    int solve()
    {
        cin >> rows >> cols >> mx;
        char grid[rows * cols];
        for (int r = 0; r < rows; ++r)
        {
            for (int c = 0; c < cols; ++c)
            {
                cin >> grid[at(r,c)];
                if (grid[at(r,c)] == 'S')
                    shifts.push_back({r,c});
            }
        }
        unordered_map<char,double> answers;
        for (int r = 0; r < rows; ++r)
        {
            for (int c = 0; c < cols; ++c)
            {
                char cur = grid[at(r,c)];
                if (cur == 'S') continue;
                cur = toupper(cur);
                if (!answers.contains(cur)) answers[cur] = min_dist(r, c);
                else answers[cur] = min(answers[cur], min_dist(r, c));
            }
        }

        int ans = 0;
        int n_q;
        char q;
        cin >> n_q;
        while (n_q--)
        {
            cin >> q;
            if ((!answers.contains(toupper(q)) || answers[q] > mx && sz(shifts) == 0)) return -1;
            if (answers[q] > mx)
            {
                ans += 1;
            }
        }
        return ans;
    }

    int32_t main()
    {
        FASTIO;
        int t = 1;
        // cin >> t;
        while (t--)
        {
            cout << solve();
        }
        return 0;
    }