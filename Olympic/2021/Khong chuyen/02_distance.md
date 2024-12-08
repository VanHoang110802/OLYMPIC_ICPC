## Tiếng Việt



## English



## Chinese (简体中文)



---

## Sort + Chặt nhị phân + Segment tree

```cpp
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

#define int long long
int a[100007], b[100007], c[100007], seg[500009];

int Tim_Kc_Min(int val, int d[], int size_arr)
{
    int le = 1, ri = size_arr, kc_min = 2000000009;
    while(le <= ri)
    {
        int mid = (le + ri) / 2;
        kc_min = min(kc_min, abs(d[mid] - val));
        if(d[mid] < val)
        {
            le = mid + 1;
        }
        else
        {
            ri = mid - 1;
        }
    }
    return kc_min;
}

void Build_Seg(int id, int le, int ri)
{
    if(le == ri)
    {
        seg[id] = c[le];
        return;
    }
    int mid = (le + ri) / 2;
    Build_Seg(2 * id, le, mid);
    Build_Seg(2 * id + 1, mid + 1, ri);

    seg[id] = min(seg[2 * id], seg[2 * id + 1]);
}

int Get_Seg(int id, int le, int ri, int u, int v)
{
    if(le > v || ri < u)
    {
        return 2000000009;
    }
    if(le >= u && ri <= v)
    {
        return seg[id];
    }
    int mid = (le + ri) / 2;
    int get_1 = Get_Seg(2 * id, le, mid, u, v);
    int get_2 = Get_Seg(2 * id + 1, mid + 1, ri, u, v);

    return min(get_1, get_2);
}

void XuLy()
{
    int n, m, k; cin >> n >> m >> k;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= m; ++i) cin >> b[i];
    sort(b + 1, b + m + 1);
    for(int i = 1; i <= n; ++i) c[i] = Tim_Kc_Min(a[i], b, m);
    Build_Seg(1, 1, n);
    while(k--)
    {
        int l, r; cin >> l >> r;
        cout << Get_Seg(1, 1, n, l, r) << "\n";
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    XuLy();
    return 0;
}

```
