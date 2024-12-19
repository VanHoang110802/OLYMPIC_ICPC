#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

#define int long long
int a[508][508], ans[408940], tmp_sum[408940];
int k, n, hang, cot, s;

int mul_mod(int x, int y)
{
    if(y == 0)
        return 0;

    int tmp = mul_mod(x, y / 2);
    tmp = (tmp + tmp) % s;

    if(y % 2 == 1)
        return tmp = (tmp + x) % s;
    else
        return tmp;
}

void XuLy()
{
    cin >> k >> n >> hang >> cot >> s;
    for(int nd = 1; nd <= k; ++nd)
    {
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j <= n; ++j)
            {
                cin >> a[i][j];
                while(a[i][j] < 0)
                {
                    a[i][j] = a[i][j] + s;
                }
            }
        }

        if(nd == 1)
        {
            for(int i = 1; i <= n; ++i)
            {
                ans[i] = a[hang][i] % s;
            }
        }
        else
        {
            for(int i = 1; i <= n; ++i)
            {
                int sum = 0;
                for(int j = 1; j <= n; ++j)
                {
                    sum = sum + mul_mod(ans[j], a[j][i]);
                    sum = sum % s;
                }
                tmp_sum[i] = sum;
            }
            for(int i = 1; i <= n; ++i)
            {
                ans[i] = tmp_sum[i];
            }
        }
    }
    cout << ans[cot];
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    XuLy();
    return 0;
}
