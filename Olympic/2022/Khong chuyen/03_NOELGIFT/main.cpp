#include <bits/stdc++.h>
using namespace std;

int n, m, ptr[110007], level[110007], atob[110007], btoa[110007];
vector<int> g[110007];
queue<int> q;

bool dfs(int u)
{
    if (u == 0)
    {
        return true;
    }
    for (int &i = ptr[u]; i < (int)g[u].size();)
    {
        int v = g[u][i++];
        if (level[btoa[v]] == level[u] + 1 && dfs(btoa[v]))
        {
            atob[u] = v;
            btoa[v] = u;
            return true;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> m >> n;
    for (int i = 1; i <= n; ++i)
    {
        int x, y;
        cin >> x >> y;
        g[i].push_back(x);
        g[i].push_back(y);
    }

    int ans = 0;
    while (true)
    {
        memset(ptr, 0, sizeof(ptr));
        memset(level, -1, sizeof(level));
        for (int i = 1; i <= n; ++i)
        {
            if (!atob[i])
            {
                level[i] = 0;
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            for (int v : g[u])
            {
                v = btoa[v];
                if (level[v] == -1)
                {
                    level[v] = level[u] + 1;
                    q.push(v);
                }
            }
        }
        if (level[0] == -1) break;

        for (int i = 1; i <= n; ++i)
        {
            if (!atob[i])
            {
                ans += dfs(i);
            }
        }
    }
    cout << ans;
    return 0;
}

