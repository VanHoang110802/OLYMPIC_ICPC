## Tiếng Việt



## English



## Chinese (简体中文)



---

## CTDL + QHD

```cpp
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500005;
int64_t pref[500005], suf[500005], a[500005], nxt[500005], prv[500005];
int n;

void process()
{
    cin >> n;

    stack<int> st;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];

        while(st.size() && a[st.top()] >= a[i])
            st.pop();

        prv[i] = (st.size() ? st.top() : 0);
        pref[i] = pref[prv[i]] + 1 * (i - prv[i]) * a[i];
        st.push(i);
    }

    while(st.size())
        st.pop();

    for (int i = n; i > 0; --i)
    {
        while(st.size() && a[st.top()] >= a[i])
            st.pop();

        nxt[i] = (st.size() ? st.top() : n + 1);
        suf[i] = suf[nxt[i]] + 1 * (nxt[i] - i) * a[i];
        st.push(i);
    }

    int64_t res = 0;
    for (int i = 1; i <= n; ++i)
        res = max(res, pref[i] + suf[i] - a[i]);

    cout << res << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    process();
    return 0;
}

```

## Segment tree lazy

```cpp
#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

ll a[500011], f[500011], g[500011], st[2044444], lazy[2044444];
int n, ok;

void Fix(int id, int l, int r)
{
    st[id] = min(st[id], lazy[id]);
    if (l != r)
    {
        lazy[2 * id] = min(lazy[2 * id], lazy[id]);
        lazy[2 * id + 1] = min(lazy[2 * id + 1], lazy[id]);
    }
    lazy[id] = 1000000007;
}

void Update_Seg(int id, int l, int r, int i, int j, int x)
{
    if (lazy[id] != 1000000007)
    {
        Fix(id, l, r);
    }
    if (l > j || r < i)
    {
        return;
    }
    if (l >= i && r <= j)
    {
        lazy[id] = x;
        Fix(id, l, r);
        return;
    }
    int mid = (l + r) >> 1;
    Update_Seg(2 * id, l, mid, i, j, x);
    Update_Seg(2 * id + 1, mid + 1, r, i, j, x);

    st[id] = max(st[2 * id], st[2 * id + 1]);
}

int Get_Seg(int id, int l, int r, int x)
{
    if (l == r) return l;
    int mid = (l + r) >> 1;
    if (lazy[id] != 1000000007)
    {
        Fix(id, l, r);
    }
    if (lazy[2 * id] != 1000000007)
    {
        Fix(2 * id, l, mid);
    }
    if (st[2 * id] > x)
    {
        return Get_Seg(2 * id, l, mid, x);
    }

    return Get_Seg(2 * id + 1, mid + 1, r, x);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= 4 * n; ++i)
    {
        st[i] = lazy[i] = 1000000007;
    }
    for(int i = 1; i <= n; ++i)
    {
        int j = Get_Seg(1, 1, n, a[i]);
        Update_Seg(1, 1, n, j, i, a[i]);
        f[i] = f[j - 1] + (i - j + 1) * a[i];
    }
    reverse(a + 1, a + n + 1);
    for(int i = 1; i <= 4 * n; ++i)
    {
        st[i] = lazy[i] = 1000000007;
    }
    for(int i = 1; i <= n; ++i)
    {
        int j = Get_Seg(1, 1, n, a[i]);
        Update_Seg(1, 1, n, j, i, a[i]);
        g[n - i + 1] = g[n - j + 2] + (i - j + 1) * a[i];
    }
    ll ans = 0;
    for(int i = 1; i <= n; ++i)
    {
        ans = max(ans, f[i] + g[i + 1]);
    }
    cout << ans;
    return 0;
}

```
