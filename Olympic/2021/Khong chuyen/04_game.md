## Tiếng Việt



## English



## Chinese (简体中文)



---

## CTDL (stack đơn điệu) + QHD

```cpp
/// Bai toan xu ly mang, tim gia tri lon nhat co the cua 1 bieu thuc nao do dua tren cac phan tu va quy tac lien quan den doan con, day con
#include <iostream>
#include <algorithm>
#include <cmath>
#include <stack>
using namespace std;

#define int long long
int a[500007], prefix[500007], suffix[500007], vt_min_lt[500007], vt_min_ls[500007];
stack<int> st; /// Tim vi tri nho hon lien truoc va lien sau

void XuLy()
{
    int n; cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];

    /// tinh phan tu nho hon lien truoc
    for(int i = 1; i <= n; ++i)
    {
        while(!st.empty() && a[st.top()] > a[i])
        {
            st.pop();
        }
        vt_min_lt[i] = (st.empty()) ? 0 : st.top();
        prefix[i] = prefix[vt_min_lt[i]] + (i - vt_min_lt[i]) * a[i];
        st.push(i);
    }

    /// tinh phan tu nho hon phia sau
    while(!st.empty()) st.pop(); /// xoa het tat ca phan tu cu di

    for(int i = n; i >= 1; --i)
    {
        while(!st.empty() && a[st.top()] > a[i])
        {
            st.pop();
        }
        vt_min_ls[i] = (st.empty()) ? (n + 1) : st.top();
        suffix[i] = suffix[vt_min_ls[i]] + (vt_min_ls[i] - i) * a[i];
        st.push(i);
    }

    int ans = 0;
    /*
    3
    2 1 3
    xet vi tri i = 2 thi:
    prefix: [a[i], a[i]]: [1,1], [a[i], a[i - 1]: [1,2]
    suffix: [a[i], a[i]]: [1,1], [a[i], a[i + 1]: [1,3]
    -> [1,1] ta chi can tinh 1 lan thoi
    */
    for(int i = 1; i <= n; ++i)
    {
        ans = max(ans, prefix[i] + suffix[i] - a[i]); /// - a[i] vi a[i] da duoc tinh 2 lan trong prefix va suffix, chi can tinh 1 lan thoi
    }
    cout << ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    XuLy();
    return 0;
}

```
