## Tiếng Việt



## English



## Chinese (简体中文)



---

## Sort + Chặt nhị phân + Sparse table

```cpp
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int a[110005];
int f[110005][20];
int log_2[110005];
int n;

void compute_sparse_table()
{
    for(int i = 0; i < n; ++i)
    {
        f[i][0] = a[i];
    }
    for(int j = 1; (1 << j) <= n; ++j)
    {
        int step = 1 << (j - 1);
        for(int i = 0; i + 2 * step <= n; ++i)
        {
            f[i][j] = min(f[i][j - 1], f[i + step][j - 1]);
        }
    }
}

int minQuery(int l, int r)
{
    int k = log_2[r - l + 1];
    return min(f[l][k], f[r - (1 << k) + 1][k]);
}

void compute_log()
{
    log_2[1] = 0;
    for(int i = 2; i <= n; ++i)
    {
        log_2[i] = log_2[i / 2] + 1;
    }
}

int main()
{
    int m, k;
    cin >> n >> m >> k;
    int b[m];
    for(int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for(int i = 0; i < m; ++i)
    {
        cin >> b[i];
    }
    sort(b, b + m);
    for(int i = 0; i < n; ++i)
    {
        int Min = INT_MAX;
        int j = lower_bound(b, b + m, a[i]) - b;
        if(j < m)
        {
            Min = min(Min, abs(a[i] - b[j]));
        }
        j--;
        if(j >= 0)
        {
            Min = min(Min, abs(a[i] - b[j]));
        }
        a[i] = Min;
    }

    compute_sparse_table();
    compute_log();

    int l, r;
    while(k--)
    {
        cin >> l >> r;
        l--;
        r--;
        cout << minQuery(l, r) << '\n';
    }
    return 0;
}
```

## CTDL + Sparse table

```cpp
#include <bits/stdc++.h>
using namespace std;

#define LIFESUCKS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define ld long double
#define ar array
#define vt vector
#define pb push_back

const int maxlog = 18;
int m, n, k;
ll a[100001];
ll up[100001][maxlog];
ll b[100001];
ll lg[100001];
vt<ll>da;

void build()
{
    for(int i = 0; i  < m; i++)
    {
        up[i][0] = da[i];
    }
    for(int i = 1; i < maxlog; i++)
    {
        for(int j = 0; j  + (1 << i) - 1 < m; j++)
        {
            up[j][i] = min(up[j][i - 1], up[j + (1 << (i - 1))][i - 1]);
        }
    }
    lg[1] = 0;
    for(int i = 2; i <= m; i++)
    {
        lg[i] = lg[i/2] + 1;
    }
}

ll find(int l, int r)
{
    int cr = lg[r - l + 1];
    return(min(up[l][cr], up[r - (1 << cr) + 1][cr]));
}

int main()
{
    cin >> m >> n >> k;
    set<ll>s;
    for(int i = 0; i < m; i++)cin >> a[i];
    for(int i = 0; i < n; i++)
    {
        cin >> b[i];
        s.insert(b[i]);
    }
    for(int i = 0; i < m; i++)
    {
        ll cr = 1e9;
        auto it = s.lower_bound(a[i]);
        if(it != s.end())
        {
            cr = abs(*it - a[i]);
        }
        if(it != s.begin())
        {
            it--;
            cr = min(cr, abs(*it - a[i]));
        }
        da.pb(cr);
    }
    build();
    for(int i = 0; i < k; i++)
    {
        int l, r;
        cin >> l >> r;
        cout << find(--l, --r) << "\n";
    }
    return 0;
}
```
