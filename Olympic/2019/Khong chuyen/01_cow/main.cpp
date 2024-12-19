#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

#define int long long

void XuLy()
{
    int n, a, b; cin >> n >> a >> b;
    double MIN = 1000000000000000000;
    for(int i = 1; i <= n; ++i)
    {
        int x, y, r; cin >> x >> y >> r;
        double l = sqrt(pow(x - a, 2) + pow(y - b, 2)) - r;
        MIN = min(MIN, l);
    }
    int tmp = MIN;
    if(tmp == MIN) cout << tmp - 1;
    else cout << tmp;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    XuLy();
    return 0;
}
