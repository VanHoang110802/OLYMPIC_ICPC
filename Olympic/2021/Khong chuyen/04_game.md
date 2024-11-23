## Tiếng Việt



## English



## Chinese (简体中文)



---

## CTDL + QHD

```cpp
#include <iostream>
#include <stack>
using namespace std;
using LL = long long;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")

LL a[511111], f[511111], ff[511111], dp1[511111], dp2[511111];
int near1[511111], near2[511111];

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }

    stack<int> st;
    for (int i = 1; i <= n; ++i)
    {
        f[i] = f[i - 1] + a[i];
        while (!st.empty() && a[st.top()] >= a[i])
        {
            st.pop();
        }
        if (st.empty()) near1[i] = 0;
        else near1[i] = st.top();
        st.push(i);
    }
    stack<int> stt;
    for (int i = n; i >= 1; --i)
    {
        ff[i] = ff[i + 1] + a[i];
        while (!stt.empty() && a[stt.top()] >= a[i])
        {
            stt.pop();
        }
        if (stt.empty()) near2[i] = 0;
        else near2[i] = stt.top();
        stt.push(i);
    }

    for (int i = 1; i <= n; ++i)
    {
        if (near1[i] == 0)
        {
            dp1[i] = (i - 1) * a[i];
        }
        else
        {
            dp1[i] = dp1[near1[i]] + a[near1[i]] + (i - near1[i] - 1) * a[i];
        }
    }
    for (int i = n; i >= 1; --i)
    {
        if (near2[i] == 0)
        {
            dp2[i] = (n - i) * a[i];
        }
        else
        {
            dp2[i] = dp2[near2[i]] + a[near2[i]] + (near2[i] - i - 1) * a[i];
        }
    }
    LL ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        LL num = 0;
        num += dp1[i];
        num += dp2[i];
        num += a[i];
        ans = max(ans, num);
    }
    cout << ans;

    return 0;
}
```
