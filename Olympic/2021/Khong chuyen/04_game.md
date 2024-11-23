## Tiếng Việt



## English



## Chinese (简体中文)



---

## CTDL + QHD

```cpp
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define int long long
const int inf = 1e9 + 7;
const ll infll = 1e18 + 7;
const int max5 = 1e5 + 7;
const int max6 = 1e6 + 7;
const int MOD = 998244353;

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    int inp[n + 2] = {};
    for (int i = 1; i <= n; ++i)
    {
        cin >> inp[i];
    }
    ll f[n + 2] = {};
    ll ff[n + 2] = {};
    int near1[n + 2] = {};
    int near2[n + 2] = {};
    stack<int> st;
    for (int i = 1; i <= n; ++i)
    {
        f[i] = f[i - 1] + inp[i];
        while (!st.empty() && inp[st.top()] >= inp[i])
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
        ff[i] = ff[i + 1] + inp[i];
        while (!stt.empty() && inp[stt.top()] >= inp[i])
        {
            stt.pop();
        }
        if (stt.empty()) near2[i] = 0;
        else near2[i] = stt.top();
        stt.push(i);
    }
    ll dp1[n + 2] = {};
    ll dp2[n + 2] = {};
    for (int i = 1; i <= n; ++i)
    {
        if (near1[i] == 0)
        {
            dp1[i] = (i - 1) * inp[i];
        }
        else
        {
            dp1[i] = dp1[near1[i]] + inp[near1[i]] + (i - near1[i] - 1) * inp[i];
        }
    }
    for (int i = n; i >= 1; --i)
    {
        if (near2[i] == 0)
        {
            dp2[i] = (n - i) * inp[i];
        }
        else
        {
            dp2[i] = dp2[near2[i]] + inp[near2[i]] + (near2[i] - i - 1) * inp[i];
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        ll num = 0;
        num += dp1[i];
        num += dp2[i];
        num += inp[i];
        ans = max(ans, num);
    }
    cout << ans;

    return 0;
}


```
