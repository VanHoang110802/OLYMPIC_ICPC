## Tiếng Việt



## English



## Chinese (简体中文)



---

## Segment tree

```cpp
#include <bits/stdc++.h>
using namespace std;

#define int long long

int a[100007], seg[410028], prefix[100007];
int n, q;

void Build(int id, int le, int ri)
{
    if(le == ri)
    {
        seg[id] = a[le];
        return;
    }

    int mid = (le + ri) >> 1;
    Build(2 * id, le, mid);
    Build(2 * id + 1, mid + 1, ri);

    seg[id] = __gcd(seg[2 * id], seg[2 * id + 1]);
}

int Get_Seg(int id, int le, int ri, int u, int v)
{
    if(le > v || ri < u)
    {
        return 0;
    }
    if(le >= u && ri <= v)
    {
        return seg[id];
    }

    int mid = (le + ri) >> 1;
    int Get_1 = Get_Seg(2 * id, le, mid, u, v);
    int Get_2 = Get_Seg(2 * id + 1, mid + 1, ri, u, v);

    return __gcd(Get_1, Get_2);
}

void XuLy()
{
    cin >> n >> q;
    for(int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }

    for(int i = 1; i <= n; ++i)
    {
        int x; cin >> x;
        a[i] -= x;
        if(a[i] < 0) a[i] = -a[i];
    }
    Build(1, 1, n);
    while(q--)
    {
        int l, r; cin >> l >> r;
        cout << Get_Seg(1, 1, n, l, r) << '\n';
    }

}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    XuLy();
    return 0;
}
```

## Sparse table

```cpp
#include <bits/stdc++.h>
using namespace std;

long long a[100007], b[100007];
long long f[20][100007];
int n, k;

long long get(int l, int r)
{
    int k = log2(r - l + 1);
    return __gcd(f[k][l], f[k][r - (1 << k) + 1]);
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    for(int i = 1; i <= n; i++)
    {
        f[0][i] = abs(a[i] - b[i]);
    }
    for(int l = 1; (1 << l) <= n; l++)
    {
        for(int i = 1; i + (1 << l) - 1 <= n; i++)
        {
            f[l][i] = __gcd(f[l - 1][i], f[l - 1][i + (1 << l - 1)]);
        }
    }
    while(k--)
    {
        int l, r;
        cin >> l >> r;
        cout << get(l, r) << "\n";
    }
    return 0;
}
```
