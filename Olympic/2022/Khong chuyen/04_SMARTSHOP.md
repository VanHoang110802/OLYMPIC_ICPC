## Tiếng Việt



## English



## Chinese (简体中文)



---

## Sinh + CTDL + Sort + Chặt nhị phân + Số học

```cpp
#include <bits/stdc++.h>
using namespace std;

unordered_set<int> st[6];

void gen(int base)
{
    long long cur = 1;
    while (cur < 2000000000)
    {
        st[base].insert(cur);
        cur *= base;
    }
}

bool check(int x)
{
    for (int base : {2, 3, 5})
    {
        if (st[base].count(x))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie();

    for (int base : {2, 3, 5})
    {
        st[base].reserve(200);
        gen(base);
    }

    int n, q; cin >> n >> q;

    vector<int> val;
    for (int i = 1; i <= n; ++i)
    {
        int x; cin >> x;
        if (check(x))
        {
            val.push_back(x);
        }
    }
    sort(val.begin(), val.end());

    while (q--)
    {
        int l, r; cin >> l >> r;
        cout << (upper_bound(val.begin(), val.end(), r) - lower_bound(val.begin(), val.end(), l)) << '\n';
    }

    return 0;
}

```

## Sort + Mảng cộng dồn + Số học + Tìm kiếm nhị phân

```cpp
#include <bits/stdc++.h>
using namespace std;

int a[500007];
int pre[500007];
int n, m;

bool check(int x)
{
    if (x == 0) return false;
    if (x == 1) return true;
    if (x % 2 == 0)
    {
        while (x % 2 == 0) x /= 2;
        return (x == 1);
    }
    if (x % 3 == 0)
    {
        while (x % 3 == 0) x /= 3;
        return (x == 1);
    }
    if (x % 5 == 0)
    {
        while (x % 5 == 0) x /= 5;
        return (x == 1);
    }
    return false;
}

void Solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    pre[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1] + check(a[i]);
    }
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        int l = lower_bound(a + 1, a + n + 1, x) - a;
        int r = upper_bound(a + 1, a + n + 1, y) - a - 1;
        if (l == n + 1 || l > r)
        {
            cout << 0 << '\n';
            continue;
        }
        cout << pre[r] - pre[l - 1] << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    Solve();
    return 0;
}
```
