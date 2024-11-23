## Tiếng Việt



## English



## Chinese (简体中文)



---

## CTDL + QHD

```cpp
#include <iostream>
#include <stack>
using namespace std;
using LL = long long;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")

LL a[511111], f[511111], ff[511111], dp1[511111], dp2[511111];
int near1[511111], near2[511111];

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }

    stack<int> st;
    for (int i = 1; i <= n; ++i)
    {
        f[i] = f[i - 1] + a[i];
        while (!st.empty() && a[st.top()] >= a[i])
        {
            st.pop();
        }
        if (st.empty()) near1[i] = 0;
        else near1[i] = st.top();
        st.push(i);
    }
    stack<int> stt;
    for (int i = n; i >= 1; --i)
    {
        ff[i] = ff[i + 1] + a[i];
        while (!stt.empty() && a[stt.top()] >= a[i])
        {
            stt.pop();
        }
        if (stt.empty()) near2[i] = 0;
        else near2[i] = stt.top();
        stt.push(i);
    }

    for (int i = 1; i <= n; ++i)
    {
        if (near1[i] == 0)
        {
            dp1[i] = (i - 1) * a[i];
        }
        else
        {
            dp1[i] = dp1[near1[i]] + a[near1[i]] + (i - near1[i] - 1) * a[i];
        }
    }
    for (int i = n; i >= 1; --i)
    {
        if (near2[i] == 0)
        {
            dp2[i] = (n - i) * a[i];
        }
        else
        {
            dp2[i] = dp2[near2[i]] + a[near2[i]] + (near2[i] - i - 1) * a[i];
        }
    }
    LL ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        LL num = 0;
        num += dp1[i];
        num += dp2[i];
        num += a[i];
        ans = max(ans, num);
    }
    cout << ans;

    return 0;
}
```

## Segment tree lazy

```cpp
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")

ll a[511111], f[511111], g[511111];
int st[2044444], lazy[2044444];
int n, ok;

template<class X, class Y>
bool minimize(X &x, const Y y)
{
    if (x > y)
    {
        x = y;
        return 1;
    }
    return 0;
}

template<class X, class Y>
bool maximize(X &x, const Y y)
{
    if (x < y)
    {
        x = y;
        return 1;
    }
    return 0;
}

void down(int id, int l, int r)
{
    minimize(st[id], lazy[id]);
    if (l != r)
    {
        minimize(lazy[2 * id], lazy[id]);
        minimize(lazy[2 * id + 1], lazy[id]);
    }
    lazy[id] = 1000000007;
}

void update(int id, int l, int r, int i, int j, int x)
{
    if (lazy[id] != 1000000007)
    {
        down(id, l, r);
    }
    if (l > j || r < i)
    {
        return;
    }
    if (l >= i && r <= j)
    {
        lazy[id] = x;
        down(id, l, r);
        return;
    }
    int mid = (l + r) >> 1;
    update(2 * id, l, mid, i, j, x);
    update(2 * id + 1, mid + 1, r, i, j, x);

    st[id] = max(st[2 * id], st[2 * id + 1]);
}

int get(int id, int l, int r, int x)
{
    if (l == r) return l;
    int mid = (l + r) >> 1;
    if (lazy[id] != 1000000007)
    {
        down(id, l, r);
    }
    if (lazy[2 * id] != 1000000007)
    {
        down(2 * id, l, mid);
    }
    if (st[2 * id] > x)
    {
        return get(2 * id, l, mid, x);
    }

    return get(2 * id + 1, mid + 1, r, x);
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
        st[i] = 1000000007;
        lazy[i] = 1000000007;
    }
    for(int i = 1; i <= n; ++i)
    {
        int j = get(1, 1, n, a[i]);
        update(1, 1, n, j, i, a[i]);
        f[i] = f[j - 1] + (i - j + 1) * 1ll * a[i];
    }
    reverse(a + 1, a + n + 1);
    for(int i = 1; i <= 4 * n; ++i)
    {
        st[i] = lazy[i] = 1000000007;
    }
    for(int i = 1; i <= n; ++i)
    {
        int j = get(1, 1, n, a[i]);
        update(1, 1, n, j, i, a[i]);
        g[n - i + 1] = g[n - j + 2] + (i - j + 1) * 1ll * a[i];
    }
    ll ans = 0;
    for(int i = 1; i <= n; ++i)
    {
        maximize(ans, f[i] + g[i + 1]);
    }
    cout << ans;
    return 0;
}

```
