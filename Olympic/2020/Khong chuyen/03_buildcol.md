## Tiếng Việt



## English



## Chinese (简体中文)



---

## Mảng cộng dồn + Mảng hiệu + Chặt nhị phân

```cpp
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int LIM = 1e5 + 15;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int n, M;
int a[LIM];
int b[LIM];
bool check(int x)
{
    int remains = 0;
    for (int i = 1; i <= n; ++i)
    {
        int water = b[i] - a[i];
        int drain = max(0, min(x, b[i]) - a[i]);
        remains += water - drain;
        if (remains >= M) return true;
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(NULL), cin.tie(NULL);

    cin >> n >> M;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 1, pref = 0; i <= n; ++i)
    {
        if (pref < a[i]) pref = a[i];
        b[i] = pref;
    }

    for (int i = n, suff = 0; i >= 1; --i)
    {
        if (suff < a[i]) suff = a[i];
        b[i] = min(b[i], suff);
    }

    int res = -1;
    int mn = *min_element(a + 1, a + n + 1);
    int mx = *max_element(a + 1, a + n + 1);
    for (int l = mn, r = mx; l <= r; )
    {
        int m = (l + r) >> 1;
        if (check(m))
        {
            res = m;
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }

    cout << res;
    return 0;
}
```

## Segment tree + Chặt nhị phân

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

#define int long long
int a[100007], seg[410028];
int n, m, max_cot = -2000000009, min_cot = 2000000009, ans = -1;

void Build_Seg(int id, int le, int ri)
{
    if(le == ri)
    {
        seg[id] = a[le];
        return;
    }
    int mid = (le + ri) / 2;
    Build_Seg(2 * id, le, mid);
    Build_Seg(2 * id + 1, mid + 1, ri);

    seg[id] = max(seg[2 * id], seg[2 * id + 1]);
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
    int mid = (le + ri) / 2;
    int get_1 = Get_Seg(2 * id, le, mid, u, v);
    int get_2 = Get_Seg(2 * id + 1, mid + 1, ri, u, v);

    return max(get_1, get_2);
}

bool Check(int cot_dang_xet, int dv_nuoc)
{
    int sum = 0;
    /// Tinh tong luong nuoc con dong lai nhu the nao???
    for(int i = 2; i <= n - 1; ++i)
    {
        int day_cot_left = Get_Seg(1, 1, n, 1, i - 1);
        int day_cot_right = Get_Seg(1, 1, n, i + 1, n);

        day_cot_left = max(day_cot_left, cot_dang_xet);
        day_cot_right = max(day_cot_right, cot_dang_xet);

        if(max(a[i], cot_dang_xet) < day_cot_left && max(a[i], cot_dang_xet) < day_cot_right)
        {
            sum = sum + min(day_cot_left, day_cot_right) - max(a[i], cot_dang_xet);
        }
    }
    return (sum >= dv_nuoc);
}

void XuLy()
{
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        min_cot = min(min_cot, a[i]);
        max_cot = max(max_cot, a[i]);
    }
    Build_Seg(1, 1, n);
    while(min_cot <= max_cot)
    {
        int mid_cot = (min_cot + max_cot) / 2;
        if(Check(mid_cot, m))
        {
            ans = mid_cot;
            min_cot = mid_cot + 1;
        }
        else
        {
            max_cot = mid_cot - 1;
        }
    }
    cout << ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    XuLy();
    return 0;
}
```
