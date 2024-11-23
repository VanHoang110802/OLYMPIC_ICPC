## Tiếng Việt



## English



## Chinese (简体中文)



---

## Sort + Số học + CTDL + Xử lý mảng + Chặt nhị phân

```cpp
#include<bits/stdc++.h>
using namespace std;

pair<int, int> a[100001];
pair<int, int> b[100001];
int d[2000001];

vector<int> prime(int x) // sang uoc
{
    vector<int> ds;
    int i = 1;
    while(i * i <= x)
    {
        if(x % i == 0)
        {
            ds.push_back(i);
            if(i * i != x)
            {
                ds.push_back(x / i);
            }
        }
        i++;
    }
    return ds;
}

int main()
{
    int n, s;
    cin >> n >> s;
    int x, y;
    for(int i = 1; i <= n; i++)
    {
        cin >> x >> y;
        a[i].first = x + 1000000;
        a[i].second = y + 1000000;
        b[i].first = y + 1000000;
        b[i].second = x + 1000000;
    }
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);

    //phan tich s
    vector<int> nt = prime(2 * s);

    int dem = 0;
    for(int i = 1; i <= n; i++)
    {
        if(a[i].first != a[i - 1].first)
        {
            for(int j = i - 1; j >= 1; j--)
            {
                if(a[j].first == a[i - 1].first)
                {
                    d[a[j].second] = 0;
                }
                else break;
            }
            for(int j = i; j <= n; j++)
            {
                if(a[j].first == a[i].first)
                {
                    d[a[j].second] = 1;
                }
                else break;
            }
        }
        for(auto x : nt)
        {
            //len

            if(a[i].second + x <= b[n].first && d[a[i].second + x] == 1)
            {
                //phai
                auto it1 = lower_bound(b + 1,b + n + 1, make_pair(a[i].second, a[i].first + 2 * s / x));
                if(it1->second == a[i].first + 2 * s / x && it1->first == a[i].second)
                {
                    dem++;
                }
                //trai
                it1 = lower_bound(b + 1, b + n + 1, make_pair(a[i].second, a[i].first - 2 * s / x));
                if(it1->second == a[i].first - 2 * s / x && it1->first == a[i].second)
                {
                    dem++;
                }
            }
            //xuong
            if(a[i].second >= x + b[1].first && d[a[i].second - x] == 1)
            {
                //phai
                auto it1 = lower_bound(b + 1, b + n + 1, make_pair(a[i].second, a[i].first + 2 * s / x));
                if(it1->second == a[i].first + 2 * s / x && it1->first == a[i].second)
                {
                    dem++;
                }

                //trai
                it1 = lower_bound(b + 1, b + n + 1, make_pair(a[i].second, a[i].first - 2 * s / x));
                if(it1->second == a[i].first - 2 * s / x && it1->first == a[i].second)
                {
                    dem++;
                }
            }
        }
    }
    cout << dem;
    return 0;
}

```

## CTDL + Sort + Xử lý mảng + Hai con trỏ + Chặt nhị phân
```cpp
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define F first
#define S second
int x[100007], y[100007];
int n, s;

/**#define pii pair<int, int>
map <pii, int> mp;

int Cnt(int a, int b)
{
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        pii X = {x[i], y[i]};
        pii Y = {x[i], y[i]};
        Y.F = x[i] + a, X.S = y[i] + b;
        if (mp.count(X) && mp.count(Y)) ans += mp[X] * mp[Y];
        Y.F = x[i] - a, X.S = y[i] + b;
        if (mp.count(X) && mp.count(Y)) ans += mp[X] * mp[Y];
        Y.F = x[i] + a, X.S = y[i] - b;
        if (mp.count(X) && mp.count(Y)) ans += mp[X] * mp[Y];
        Y.F = x[i] - a, X.S = y[i] - b;
        if (mp.count(X) && mp.count(Y)) ans += mp[X] * mp[Y];
    }
    return ans;
}**/

signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    cin >> n >> s;
    s *= 2;

    vector <pair<int, int>> v;
    map<int, vector<int>> mp;

    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
        v.push_back({x[i], y[i]});
        mp[y[i]].push_back(x[i]);
    }

    /**int ans = 0, m = sqrt(s);
    for (int i = 1; i < m; i++)
    {
        if (s % i == 0) ans += Cnt(i, s / i) + Cnt(s / i, i);
    }
    if (s % m == 0)
    {
        if (m * m == s) ans += Cnt(m, m);
        else ans += Cnt(m, s / m) + Cnt(s / m, m);
    }
    cout << ans;**/

    sort(v.begin(), v.end());
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        sort(it->S.begin(), it->S.end());
    }
    int ans = 0, cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int j = i + 1;
        while (v[i].F == v[j].F && j < n)
        {
            if (v[i].S != v[j].S && s % abs(v[i].S - v[j].S) == 0)
            {
                int tmp = s / abs(v[i].S - v[j].S);
                if (binary_search(mp[v[i].S].begin(), mp[v[i].S].end(), v[i].F + tmp) == 1)
                {
                    cnt++;
                }
                if (binary_search(mp[v[i].S].begin(), mp[v[i].S].end(), v[i].F - tmp) == 1)
                {
                    cnt++;
                }
                if (binary_search(mp[v[j].S].begin(), mp[v[j].S].end(), v[j].F + tmp) == 1)
                {
                    cnt++;
                }
                if (binary_search(mp[v[j].S].begin(), mp[v[j].S].end(), v[j].F - tmp) == 1)
                {
                    cnt++;
                }
            }
            j++;
        }
    }
    cout << cnt;
    return 0;
}

```
