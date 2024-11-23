## Tiếng Việt



## English



## Chinese (简体中文)



---

## Duyệt + Số học

```cpp
#include <bits/stdc++.h>
using namespace std;

long long s, l, r, a, k;

int main()
{
    cin >> l >> r >> a >> k;
    cout << (r/(k/__gcd(a, k))) - ((l)/(k/__gcd(a, k)));
    return 0;
}
```

```cpp
#include <bits/stdc++.h>
using namespace std;

#define LIFESUCKS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define ld long double

ll find(ll a, ll b)
{
    while(b != 0)
    {
        ll temp = a % b;
        a = b;
        b = temp;
    }
    return(a);
}

int main()
{
    ll l, r, a, k;
    cin >> l >> r >> a >> k;
    ll gcd = find(a, k);
    ll hcf = (((ld)(k) / (ld)(gcd)));
    ll ans = (floor((ld)r / (ld)hcf) - ceil(((ld)l / (ld)hcf))) + 1;
    cout << ans;
    return 0;
}
```
