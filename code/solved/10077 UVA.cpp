w
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