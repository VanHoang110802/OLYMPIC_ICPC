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
