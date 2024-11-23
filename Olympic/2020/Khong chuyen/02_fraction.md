## Tiếng Việt



## English



## Chinese (简体中文)



---

## Số học

```cpp
/*
- Nếu một phân số tối giản với mẫu dương mà mẫu không có ước nguyên tố khác 2 và 5
thì phân số đó viết được dưới dạng số thập phân hữu hạn.
- Nếu một phân số tối giản với mẫu dương mà mẫu có ước nguyên tố khác 2 và 5
thì phân số đó viết được dưới dạng số thập phân vô hạn tuần hoàn.
*/


#include <iostream>
#include <algorithm>
using namespace std;
using ull = unsigned long long;

#pragma GCC target("avx2")
#pragma GCC optimization("O2")
#pragma GCC optimization("O3")
#pragma GCC optimize("Ofast")

int n;
ull a[1000005], b[1000005];

void solve()
{
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];

    for(int i = 1; i <= n; ++i)
        cin >> b[i];

    ull ts = 1, ms = 1;
    for(int i = 1; i <= n; ++i)
    {
        ts *= a[i];
        ms *= b[i];

        ull gcd = __gcd(ts, ms);
        ts /= gcd;
        ms /= gcd;

        if (ms == 0)
        {
            cout << "repeating\n";
            return;
        }
    }
    while(ms % 2 == 0)
        ms /= 2;

    while(ms % 5 == 0)
        ms /= 5;

    cout << ((ms == 1) ? "finite\n" : "repeating\n");
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int testcase; cin >> testcase;
    while(testcase--) solve();
    return 0;
}

```
