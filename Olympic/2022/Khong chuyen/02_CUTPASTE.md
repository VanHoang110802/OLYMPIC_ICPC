## Tiếng Việt



## English



## Chinese (简体中文)



---

## Cấu trúc bản ghi (Struct) + Toán học + Sort

```cpp
#include<bits/stdc++.h>
using namespace std;
using LL = long long;

struct
{
    LL x, y;
} A[5], B[5];
double dA[5], dB[5];
LL t, res;

int main()
{
    for(int i = 1; i <= 4; i++)
    {
        cin >> A[i].x >> A[i].y;
    }

    for(int i = 1; i < 4; i++)
    {
        dA[i] = sqrt(pow((A[i + 1].x - A[i].x), 2) + pow((A[i + 1].y - A[i].y), 2));
    }
    dA[4] = sqrt(pow((A[1].x - A[4].x), 2) + pow((A[1].y - A[4].y), 2));

    sort(dA + 1, dA + 5);

    cin >> t;
    res = 0;
    while(t--)
    {
        for(int i = 1; i <= 4; i++)
        {
            cin >> B[i].x >> B[i].y;
        }

        for(int i = 1; i < 4; i++)
        {
            dB[i] = sqrt(pow((B[i + 1].x - B[i].x),2) + pow((B[i + 1].y - B[i].y), 2));
        }
        dB[4] = sqrt(pow((B[1].x - B[4].x), 2) + pow((B[1].y - B[4].y), 2));

        sort(dB + 1, dB + 5);

        res++;
        for(int i = 1; i <= 4; i++)
        {
            if(dB[i] != dA[i])
            {
                res--;
                break;
            }
        }
    }
    cout << res;
    return 0;
}

```

## Cấu trúc bản ghi (Struct) + Xử lý mảng + Sort

```cpp
#include <bits/stdc++.h>
using namespace std;

struct ii
{
    int x, y;
};
struct iii
{
    int x, y, w;
};

int x[5], y[5], st[5], f[5];

int calc(int u, int v)
{
    if (v > 4)
    {
        v = 1;
    }
    int xx = abs(x[u] - x[v]), yy = abs(y[u] - y[v]);
    return xx * xx + yy * yy;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    for(int i = 1; i <= 4; ++i)
    {
        cin >> x[i] >> y[i];
    }
    for(int i = 1; i <= 4; ++i)
    {
        st[i] = calc(i, i + 1);
    }
    sort(st + 1, st + 1 + 4);
    int n, ans = 0;
    cin >> n;
    for(int j = 1; j <= n; ++j)
    {
        int d = 0;
        for(int i = 1; i <= 4; ++i)
        {
            cin >> x[i] >> y[i];
        }
        for(int i = 1; i <= 4; ++i)
        {
            f[i] = calc(i, i + 1);
        }
        sort(f + 1, f + 1 + 4);
        for(int i = 1; i <= 4; ++i)
        {
            if (f[i] == st[i])
            {
                d++;
            }
        }
        if(d == 4)
        {
            ans++;
        }
    }
    cout << ans;
    return 0;
}

```
