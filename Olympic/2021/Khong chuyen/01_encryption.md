## Tiếng Việt



## English



## Chinese (简体中文)



---

## Duyệt + Số học

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

#define int long long

void XuLy()
{
    int l, r, a, k;
    cin >> l >> r >> a >> k;
    if(a % k == 0) cout << (r / k) - ((l - 1) / k);
    else
    {
        if(k % a == 0)
        {
            int tmp = k / a;
            int L = (l - 1) / tmp;
            int R = r / tmp;
            cout << R - L;
        }
        else
        {
            int tmp = k / __gcd(a, k);
            int L = (l - 1) / tmp;
            int R = r / tmp;
            cout << R - L;
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    XuLy();
    return 0;
}

```
