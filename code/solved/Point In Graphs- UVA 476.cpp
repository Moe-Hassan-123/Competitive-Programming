#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pf pair<float, float>

struct rectangle
{
    float x_s;
    float y_e;
    float x_e;
    float y_s;
};
vector<rectangle> rectangles;

int main()
{
FASTIO;
// freopen("input.in","r",stdin);
// Fill rectangles Vector
char c;
pf tmp1, tmp2;
rectangles.reserve(10);
while(true)
{
    cin >> c;
    if (c == '*') break;
    if (c != 'r') continue;
    cin >> tmp1.first >> tmp1.second;
    cin >> tmp2.first >> tmp2.second;
    rectangle tmp = {tmp1.first, tmp1.second, tmp2.first, tmp2.second};
    rectangles.push_back(tmp);
}

int point_no = 1;
pf pt;
while(true)
{
    cin >> pt.first >> pt.second;
    if (fabs(pt.first - pt.second) < 0.001 && fabs(pt.first - 9999.9) < 0.001) break;
    int rect_no = 0;
    bool is_contained = false;
    for (rectangle &rect: rectangles)
    {
        rect_no += 1;
        if (rect.x_s < pt.first && rect.x_e > pt.first && rect.y_s < pt.second && rect.y_e > pt.second)
        {
            is_contained = true;
            printf("Point %d is contained in figure %d\n",point_no, rect_no);
        }
    }
    if (!is_contained) printf("Point %d is not contained in any figure\n", point_no);
    ++point_no;
}
return 0;
}