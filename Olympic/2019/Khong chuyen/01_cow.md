## Tiếng Việt



## English



## Chinese (简体中文)



---

```cpp
#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL LL_Sqrt(LL x)
{
    LL r = sqrt(x);
    while((r + 1) * (r + 1) < x)
    {
        ++r;
    }
    while(r * r >= x)
    {
        --r;
    }
    return r;
}

void XuLy()
{
    int n, a, b; cin >> n >> a >> b;
    LL ans = LLONG_MAX;
    for(int i = 1; i <= n; ++i)
    {
        int x, y, r; cin >> x >> y >> r;
        x -= a;
        y -= b;
        ans = min(ans, LL_Sqrt(1LL * x * x + 1LL * y * y) - r);
    }
    ans = max(ans, 0LL);
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    XuLy();
    return 0;
}
```
