## Tiếng Việt



## English



## Chinese (简体中文)



---

## Xử lý số mod + Duyệt

```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll MOD;

ll modmul(ll a, ll b)
{
    ll ret = a * b - MOD * ll(1.L / MOD * a * b);
    return ret + MOD * (ret < 0) - MOD * (ret >= MOD);
}

void add(ll& x, ll y)
{
    x += y;
    x -= (x >= MOD) * MOD;
}

ll row[100], tmp[100], mat[100][100];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int k, n, x, y;
    cin >> k >> n >> x >> y >> MOD;
    --x, --y;

    row[x] = 1;

    while (k--)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cin >> mat[i][j];
                mat[i][j] %= MOD;
                mat[i][j] += (mat[i][j] < 0) * MOD;
            }
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                add(tmp[j], modmul(row[i], mat[i][j]));
            }
        }
        memcpy(row, tmp, sizeof(tmp));
        memset(tmp, 0, sizeof(tmp));
    }
    cout << row[y] << '\n';

    return 0;
}
```

## Xử lý mũ với mod + Duyệt
```cpp
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
using namespace std;

int n, k, row, col;
long long s, a[110][110], ans[110], c[110];

long long multiply_modulo(long long a, long long b)
{
    if (b == 0)
        return 0;

    long long t = multiply_modulo(a, b / 2);
    t = (t + t) % s;

    if(b & 1)
        return t = (t + a) % s;
    else
        return t;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> k >> n >> row >> col >> s;
    for(int ct = 1; ct <= k; ct++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                cin >> a[i][j];
                while(a[i][j] < 0)
                {
                    a[i][j] += s;
                }
            }
        }

        if(ct == 1)
        {
            for(int i = 1; i <= n; i++)
            {
                ans[i] = a[row][i] % s;
            }
        }
        else
        {
            for(int i = 1; i <= n; i++)
            {
                long long sum = 0;
                for(int j = 1; j <= n; j++)
                {
                    sum += multiply_modulo(ans[j], a[j][i]);
                    sum %= s;
                }
                c[i] = sum;
            }
            for(int i = 1; i <= n; i++)
            {
                ans[i] = c[i];
            }
        }
    }
    cout << ans[col];
    return 0;
}
```
