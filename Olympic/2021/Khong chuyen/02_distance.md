## Tiếng Việt



## English



## Chinese (简体中文)



---

## Sort + Chặt nhị phân + Segment tree

```cpp
#include <bits/stdc++.h>
using namespace std;

int m, n, k, a[100007], b[100007], dist[100007];
int ST[500007];

int findMinDiff(int value, int arr[], int size)
{
    int left = 0, right = size - 1;
    int minDiff = INT_MAX;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        minDiff = min(minDiff, abs(arr[mid] - value));
        if (arr[mid] < value)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return minDiff;
}

void build(int id, int start, int end)
{
    if (start == end)
    {
        ST[id] = dist[start];
    }
    else
    {
        int mid = (start + end) / 2;
        int leftid = 2 * id + 1;
        int rightid = 2 * id + 2;
        build(leftid, start, mid);
        build(rightid, mid + 1, end);
        ST[id] = min(ST[leftid], ST[rightid]);
    }
}

int get(int id, int start, int end, int L, int R)
{
    if (R < start || L > end)
    {
        return INT_MAX;
    }
    if (L <= start && end <= R)
    {
        return ST[id];
    }
    int mid = (start + end) / 2;
    int leftid = 2 * id + 1;
    int rightid = 2 * id + 2;
    int leftMin = get(leftid, start, mid, L, R);
    int rightMin = get(rightid, mid + 1, end, L, R);
    return min(leftMin, rightMin);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);

    cin >> m >> n >> k;
    for (int i = 1; i <= m; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    sort(b + 1, b + n + 1);

    // Tính khoảng cách nhỏ nhất giữa mỗi phần tử a[i] với mảng b
    for (int i = 1; i <= m; i++)
    {
        dist[i] = findMinDiff(a[i], b + 1, n);
    }

    // Xây dựng Segment Tree từ mảng dist
    build(0, 1, m);

    while (k--)
    {
        int l, r;
        cin >> l >> r;
        // Truy vấn giá trị nhỏ nhất trong đoạn [l, r] của mảng dist
        int res = get(0, 1, m, l, r);
        cout << res << "\n";
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
