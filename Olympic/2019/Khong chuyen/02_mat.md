## Tiếng Việt



## English



## Chinese (简体中文)



## Code (Dạng: Xử lý mũ với mod + duyệt)
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
