## Tiếng Việt



## English



## Chinese (简体中文)



## Code (Dạng: Duyệt + số học)

```cpp
#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void XuLy()
{
    LL n, a, b; cin >> n >> a >> b;
    double MIN = 1000000000000000000;
    for(LL i = 0; i < n; ++i)
    {
        LL x, y, z; cin >> x >> y >> z;
        MIN = min(MIN, sqrt(pow(x - a, 2) + pow(y - b, 2)) - z);
    }
    LL ans = MIN;
    if(MIN == ans) cout << ans - 1;
    else cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    XuLy();
    return 0;
}

```
