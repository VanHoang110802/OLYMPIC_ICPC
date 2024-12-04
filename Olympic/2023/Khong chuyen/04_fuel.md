## Tiếng Việt



## English



## Chinese (简体中文)



---

## CTDL + Mảng cộng dồn + Mảng hiệu dồn + Tìm max - min trên đoạn tịnh tiến + chặt nhị phân

```cpp
#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int v[100005], h[100005];
LL sumL[100005], L[100005];
LL sumR[100005], R[100005];
int n, m, T;
stack<int> st;

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
    {
        cin >> v[i];
    }

    v[0] = 0;
    v[n + 1] = m;

    for(int i = 1; i <= n; ++i)
    {
        cin >> h[i];
    }

    h[0] = 100005;
    h[n + 1] = 100005;

    for(int i = 1; i <= n; ++i)
    {
        sumL[i] = sumL[i - 1] + h[i];
    }
    for(int i = n; i >= 1; --i)
    {
        sumR[i] = sumR[i + 1] + h[i];
    }

    st.push(0);
    for(int i = 1; i <= n; ++i)
    {
        while(!st.empty() && h[st.top()] < h[i])
        {
            st.pop();
        }
        L[i] = L[st.top()] + (LL)(v[i] - v[st.top()] - 1) * h[i] - (sumL[i - 1] - sumL[st.top()]);
        st.push(i);

    }
    while(!st.empty())
    {
        st.pop();
    }

    st.push(n + 1);

    for(int i = n ; i >= 1; --i)
    {
        while(!st.empty() && h[st.top()] < h[i])
        {
            st.pop();
        }
        R[i] = R[st.top()] + (LL)(v[st.top()] - v[i] - 1) * h[i] - (sumR[i + 1] - sumR[st.top()] );
        st.push(i);
    }

    cin >> T;
    for(int i = 1; i <= T; ++i)
    {
        LL k;
        cin >> k;
        int maxL = 0, l = 0, r = n;
        while(l <= r)
        {
            int mid = ( l + r ) / 2;
            if(L[mid] < k)
            {
                maxL = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }

        int minR = n + 1;
        l = maxL + 1;
        r = n;
        while(l <= r)
        {
            int mid = (l + r) / 2;
            if(R[mid] < k)
            {
                minR = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        cout << (maxL + 1) + (n - minR) << "\n";
    }
    return 0;
}

```

## CTDL + Mảng cộng dồn + Tìm max - min trên đoạn tịnh tiến + Sort + Chặt nhị phân

```cpp
#include <bits/stdc++.h>

using namespace std;
int h[100005], v[100005];
long long sumf[100005], f[100005], sumg[100005], g[100005];
// f là mảng tính tổng các độ cao dùng prefixsum từ trái sang, g là từ phải sang
// sumf là mảng tổng lượng nước cho cần tại mỗi cột cũng dùng prefixsum
// sumf[i] xây dựng bằng cách tìm phần tử lớn nhất gần i nhất bằng stack
// sau đó tính lượng nước cần từ vị trí đó đến i
// trong đoạn từ vị trí đó đến i-1 thì tính xem tổng các cột nằm trong bằng bao nhiêu để trừ đi
long long n, m, k, q;
stack<int> s;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    v[0] = 0;
    v[n+1] = m;

    for(int i = 1; i <= n; i++)
    {
        cin >> h[i];
    }
    h[0] = 100005;
    h[n+1] = 100005;

    for(int i = 1; i <= n; i++)
    {
        f[i] = f[i-1] + h[i];
    }
    for(int i = n; i > 0; i--)
    {
        g[i] = g[i+1] + h[i];
    }
    s.push(0);
    for(int i = 1; i <= n; i++)
    {
        while(!s.empty() && h[s.top()] < h[i])
        {
            s.pop();
        }
        sumf[i] = sumf[s.top()] + (long long)(v[i] - v[s.top()] - 1) * h[i] - (f[i-1] - f[s.top()]);
        s.push(i);
    }
    while(!s.empty()) s.pop();
    s.push(n+1);
    for(int i = n; i >= 1; i--)
    {
        while(!s.empty() && h[s.top()] < h[i])
        {
            s.pop();
        }
        sumg[i] = sumg[s.top()] + (long long)(v[s.top()] - v[i] - 1) * h[i] - (g[i+1] - g[s.top()]);
        s.push(i);
    }

    cin >> q;
    while(q--)
    {
        cin >> k;
        int l = 0, r = n;
        int maxl = 0;
        while(l <= r)
        {
            int mid = (l+r)/2;
            if(sumf[mid] < k)
            {
                maxl = mid;
                l = mid+1;
            }
            else
                r = mid-1;
        }
        int minr = n+1;
        l = maxl+1;
        r = n+1;
        while(l <= r)
        {
            int mid = (l+r)/2;
            if(sumg[mid] < k)
            {
                minr = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        cout << maxl + n + 1 - minr << "\n";
    }

    return 0;
}

```
