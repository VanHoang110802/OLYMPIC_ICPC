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
#include <bits/stdc++.h>
#define ll long long
#define x first
#define y second
using namespace std;
ll m;
long n,a[100005],f[400005];
void build(long id, long l, long r)
{
    if( l == r )
    {
        f[id] = a[l];
        return;
    }
    long mid = ( l + r ) / 2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    f[id] = max(f[id*2],f[id*2+1]);
}
long get(long id, long l, long r, long u, long v)
{
    if( r < u || l > v ) return 0;
    if( u <= l && r <= v ) return f[id];
    long mid = ( l + r ) / 2;
    return max(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}
bool check(long x)
{
    ll res = 0;
    for(long i = 2; i <= n - 1; i++)
    {
        long l = get(1,1,n,1,i - 1);
        long r = get(1,1,n,i + 1,n);
        if( a[i] > l || a[i] > r ) continue;
        if( l <= x || r <= x ) continue;
        //cout << i << ' ' <<  l << ' ' << r << '\n';
        res += min(l,r) - max(x,a[i]);
    }
    //cout << res << '\n';
    if (res >= m) return true;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(long i = 1; i <= n; i++) cin >> a[i];
    build(1,1,n);
    long l = 0, r = get(1,1,n,1,n), mid = ( l + r ) / 2;
    //cout << check(2);
    while( r - l > 3 )
    {
        if( check(mid) ) l = mid;
        else r = mid;
        mid = ( l + r ) / 2;
    }
    for(long i = r; i >= l; i--)
    {
        if( check(i) )
        {
            cout << i;
            return 0;
        }
    }
    cout << -1;
}

```
