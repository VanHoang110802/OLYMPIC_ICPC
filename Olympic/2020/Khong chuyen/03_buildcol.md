## Tiếng Việt



## English



## Chinese (简体中文)



---

## Mảng cộng dồn + Chặt nhị phân

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

```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 5;
int n, a[N], b[N];
int pref_max[N], suf_max[N];
ll m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }

    int lt = 1, rt = 2e9, ans = -1;
    while (lt <= rt)
    {
        int md = (lt + rt) / 2;
        for (int i = 1; i <= n; ++i)
        {
            b[i] = max(a[i], md);
        }
        for (int i = 1; i <= n; ++i)
        {
            pref_max[i] = max(pref_max[i - 1], b[i]);
        }
        for (int i = n; i >= 1; --i)
        {
            suf_max[i] = max(suf_max[i + 1], b[i]);
        }

        ll total = 0;
        for (int i = 1; i <= n; ++i)
        {
            total += max(0, min(pref_max[i - 1], suf_max[i + 1]) - b[i]);
            if (total >= m) break;
        }

        if (total >= m)
        {
            ans = md;
            lt = md + 1;
        }
        else
        {
            rt = md - 1;
        }
    }
    cout << ans << '\n';

    return 0;
}
```
