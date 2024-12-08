## Tiếng Việt



## English



## Chinese (简体中文)



---

## CTDL (stack đơn điệu) + QHD

```cpp
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500005;
int64_t pref[500005], suf[500005], a[500005], nxt[500005], prv[500005];
int n;

void process()
{
    cin >> n;

    stack<int> st;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];

        while(st.size() && a[st.top()] >= a[i])
            st.pop();

        prv[i] = (st.size() ? st.top() : 0);
        pref[i] = pref[prv[i]] + 1 * (i - prv[i]) * a[i];
        st.push(i);
    }

    while(st.size())
        st.pop();

    for (int i = n; i > 0; --i)
    {
        while(st.size() && a[st.top()] >= a[i])
            st.pop();

        nxt[i] = (st.size() ? st.top() : n + 1);
        suf[i] = suf[nxt[i]] + 1 * (nxt[i] - i) * a[i];
        st.push(i);
    }

    int64_t res = 0;
    for (int i = 1; i <= n; ++i)
        res = max(res, pref[i] + suf[i] - a[i]);

    cout << res << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    process();
    return 0;
}

```
