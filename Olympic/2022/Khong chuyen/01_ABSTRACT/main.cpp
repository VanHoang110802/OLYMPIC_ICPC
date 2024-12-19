#include <iostream>
#include <algorithm>
using namespace std;

#define int long long
int a[1007][1007], n_t[1007][1007];

void XuLy()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= n; ++i)
    {
        int check = 0;
        for(int j = 1; j <= m; ++j)
        {
            if(check < a[i][j])
            {
                check = a[i][j];
                n_t[i][j] = 1;
            }
        }

        check = 0;
        for(int j = m; j; --j)
        {
            if(check < a[i][j])
            {
                check = a[i][j];
                n_t[i][j] = 1;
            }
        }
    }
    for(int j = 1; j <= m; ++j)
    {
        int check = 0;
        for(int i = 1; i <= n; ++i)
        {
            if(check < a[i][j])
            {
                check = a[i][j];
                n_t[i][j] = 1;
            }
        }

        check = 0;
        for(int i = n; i; --i)
        {
            if(check < a[i][j])
            {
                check = a[i][j];
                n_t[i][j] = 1;
            }
        }
    }
    int sum = 0;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            sum = sum + n_t[i][j];
        }
    }
    cout << sum;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    XuLy();
    return 0;
}
