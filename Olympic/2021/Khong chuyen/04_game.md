## Tiếng Việt



## English



## Chinese (简体中文)



---

## Duyệt + Xử lý mảng (biến thể của mảng cộng dồn)

```cpp
#include<bits/stdc++.h>
using namespace std;

const int inf = 1000000007;
int a[500005];
int n;
int minValue[500005];

int main ()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    long long s = 0LL;
    long long ans = 0LL;
    minValue[0] = inf;
    for (int i = 1; i <= n; i++)
    {
        minValue[i] = min(minValue[i - 1], a[i]);
    }
    for (int i = n; i >= 1; i--)
    {
        s += minValue[i];
    }
    ans = s;
    reverse(a + 1, a + n + 1);
    s = 0;
    minValue[0] = inf;
    for (int i = 1; i <= n; i++)
    {
        minValue[i] = min(minValue[i - 1], a[i]);
    }
    for (int i = n; i >= 1; i--)
    {
        s += minValue[i];
    }
    ans = max(ans, s);
    cout << ans;
    return 0;
}

```
