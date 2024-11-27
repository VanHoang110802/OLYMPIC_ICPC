## Tiếng Việt



## English




## Chinese (简体中文)



## Code:
#include <iostream>
#include <algorithm>
using namespace std;

#define int long long
int a[200007], dpa[200007], dpb[200007];
int n, m, k;

void XuLy()
{
    cin >> n >> k >> m;
    for(int i = 1; i <= m; ++i)
    {
        cin >> a[i];
    }
    sort(a + 1, a + m + 1);
    int gmax = 1000000000000000007;
    {
        int id = 1;
        for(int i = 1; i <= m; i++)
        {
            while(a[i] - a[id] + 1 > k)
            {
                id++;
            }
            dpa[i] = min(dpa[id - 1] + k, a[i]);
        }
        id = m;
        for(int i = m; i >= 1; --i)
        {
            while(a[id] - a[i] + 1 > k)
            {
                --id;
            }
            dpb[i] = min(dpb[id + 1] + k, n - a[i] + 1);
        }
    }
    for(int i = 1; i <= m + 1; ++i)
    {
        gmax = min(gmax, dpa[i - 1] + dpb[i]);
    }
    cout << n - gmax;
}

signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    XuLy();
    return 0;
}
