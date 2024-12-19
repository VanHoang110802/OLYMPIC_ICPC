#include <bits/stdc++.h>
using namespace std;

#define int long long
#define F first
#define S second
int x[100007], y[100007];
int n, s;

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
