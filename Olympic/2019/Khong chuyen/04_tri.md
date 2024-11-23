## Tiếng Việt



## English



## Chinese (简体中文)



---

## Min - max trong đoạn định tiến

```cpp
#include <bits/stdc++.h>
using namespace std;

int a[100007];
int n, k, ans = 0;
long long sum = 0;
deque<int> dq;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        sum += a[i];

        if (!dq.empty() && dq.front() <= i - k)
        {
            dq.pop_front();
        }
        while (!dq.empty() && a[i] >= a[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);

        if (i >= k)
        {
            sum -= a[i - k];
            int mx = a[dq.front()];
            if (sum - mx > mx)
            {
                ++ans;
            }
        }
    }
    cout << ans << '\n';

    return 0;
}
```

## Mảng cộng dồn + Segment tree

```cpp
#include <bits/stdc++.h>
using namespace std;

long long a[100005], b[100005], st[4 * 100005];

void bt(int id,int l,int r)
{
    if(l == r)
    {
        st[id] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    bt(id * 2, l, mid);
    bt(id * 2 + 1, mid + 1, r);
    st[id] = max(st[id * 2], st[id * 2 + 1]);
}

long long get(int id, int l, int r, int u, int v)
{
    if(u > r || v < l)
    {
        return INT_MIN;
    }
    if(u <= l && r <= v)
    {
        return st[id];
    }
    int mid = (l + r) / 2;
    return max(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n, i, k, s = 0, l, o;
    cin >> n >> k;
    for(i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i] = b[i - 1] + a[i];
    }
    bt(1, 1, n);

    for(i = 1; i<=n-k+1; i++)
    {
        l = b[i + k - 1] - b[i - 1];
        o = get(1, 1, n, i, i + k - 1);
        if(l - o > o)
        {
            s++;
        }
    }
    cout << s;
    return 0;
}

```

## Mảng cộng dồn + Chặt nhị phân

```cpp
#include<bits/stdc++.h>
using namespace std;

int main()
{
#define int long long
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    vector<long long> pref(n + 1);
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }
    int ans = 0;
    for(int i = 1; i <= n - k + 1; i++)
    {
        long long sum = pref[i + k - 1] - pref[i - 1];
        int l = i, r = i + k - 3;
        int maxa = -1;
        while(l <= r)
        {
            int mid = (l + r) / 2;
            if(sum > 2 * (pref[mid] - pref[i - 1]))
            {
                maxa = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        if(maxa == -1)
        {
            continue;
        }
        int maxb = -1;
        l = maxa + 1, r = i + k - 2;
        while(l <= r)
        {
            int mid = (l + r) / 2;
            if(sum > 2 * (pref[mid] - pref[maxa]))
            {
                maxb = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        if(maxb == -1)
        {
            continue;
        }
        if(sum > 2 * (pref[i + k - 1] - pref[maxb]))
        {
            ans ++;
        }
    }
    cout << ans;
}
```
