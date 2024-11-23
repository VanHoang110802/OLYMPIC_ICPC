## Tiếng Việt



## English



## Chinese (简体中文)



---

## CTDL + Xử lý mảng + Sort + Min - max trên đoạn định tiến

```cpp
#include <bits/stdc++.h>
using namespace std;

int n, m, b[100009], cnt[100009];
vector<int> unique_val;

class Compare
{
public:
    bool operator()(pair<int, int> p, pair<int, int> q)
    {
        if (p.second != q.second) return p.second > q.second;
        return true;
    }
};

vector<pair<int, int> > inc_segs;
priority_queue<pair<int, int>, vector<pair<int, int> >, Compare> pq;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);

    cin >> n >> m;
    long long only_add_op = 0;

    // tính số thao tác mà ko sử dụng phép nhảy nào
    // sắp xếp cần đảm bảo là
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];

        if (i > 1)
        {
            if (b[i] > b[i - 1])
            {
                only_add_op += b[i] - b[i - 1];
                inc_segs.emplace_back(b[i - 1], b[i]);
            }
            else
            {
                only_add_op += m - b[i - 1] + b[i];
                inc_segs.emplace_back(b[i - 1], b[i] + m);
                inc_segs.emplace_back(b[i - 1] - m, b[i]);
            }
            unique_val.push_back(b[i]);
        }
    }

    sort(unique_val.begin(), unique_val.end());
    sort(inc_segs.begin(), inc_segs.end());

    int k2 = 0;
    long long ans = only_add_op;
    long long sum_left = 0;

    for (int i = 0; i + 1 < n; i++)
    {
        if (unique_val[i] ^ unique_val[i + 1])
        {
            int X = unique_val[i];

            while (k2 < (int)inc_segs.size() && inc_segs[k2].first < X)
            {
                sum_left += inc_segs[k2].first;
                pq.push(inc_segs[k2]);
                k2++;
            }

            while (pq.size() && pq.top().second < X)
            {
                sum_left -= pq.top().first;
                pq.pop();
            }
            ans = min(ans, only_add_op - (long long)pq.size() * X + sum_left + (long long)pq.size());
        }
    }

    cout << ans;
}
```

## Xử lý mảng + Segment tree lazy
```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll seg[4 * 100005], lz[4 * 100005];
int a[100005];
int n, m;
ll ans = (ll)1e18, cnt;

void Lazy_Seg(int id, int l, int r)
{
    if(lz[id] == 0)
    {
        return;
    }

    seg[id] += lz[id] * (r - l + 1);

    if(l < r)
    {
        lz[2 * id] += lz[id];
        lz[2 * id + 1] += lz[id];
    }
    lz[id] = 0;
}

void Update_Seg(int id,int l,int r,int u,int v,int x)
{
    Lazy_Seg(id, l, r);
    if(l > v || r < u)
    {
        return;
    }
    if(l >= u && r <= v)
    {
        lz[id] += x;
        Lazy_Seg(id, l, r);
        return;
    }

    int mid = (l + r) / 2;
    Update_Seg(2 * id, l, mid, u, v, x);
    Update_Seg(2 * id + 1, mid + 1, r, u, v, x);

    seg[id] = seg[2 * id] + seg[2 * id + 1];
}

ll Get_Seg(int id,int l,int r,int u,int v)
{
    Lazy_Seg(id, l, r);
    if(l > v || r < u)
    {
        return 0;
    }
    if(l >= u && r <= v)
    {
        return seg[id];
    }
    int mid = (l + r) / 2;
    int get_1 = Get_Seg(2 * id, l, mid, u, v);
    int get_2 = Get_Seg(2 * id + 1, mid + 1, r, u, v);

    return get_1 + get_2;
}

void sol()
{
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= n - 1; ++i)
    {
        int x = (a[i + 1] + m - a[i]) % m;
        cnt += x;
        if(x < 2)
        {
            continue;
        }
        x--;
        int l = (a[i] + 2) % m, r = a[i + 1];
        if(l <= r)
        {
            Update_Seg(1, 0, m - 1, l, r, 1);
            Update_Seg(1, 0, m - 1, r + 1, r + 1, -x);
        }
        else
        {
            Update_Seg(1, 0, m - 1, l, m - 1, 1);
            Update_Seg(1, 0, m - 1, 0, 0, m - l + 1);
            if(r > 0)
            {
                Update_Seg(1, 0, m - 1, 1, r, 1);
            }
            Update_Seg(1, 0, m - 1, r + 1, r + 1, -x);
        }
    }
    for(int i = 0; i <= m - 1; ++i)
    {
        ans = min(ans, cnt - Get_Seg(1, 0, m - 1, 0, i));
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    sol();
    return 0;
}

```
