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

#define int long long
int n, m, q;
int v[100007], h[100007];
int L[100007], R[100007];
int sum[100007];
deque<int> st;

void XuLy()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
        sum[i] = sum[i - 1] + h[i];
    }

    for (int i = 1; i <= n; i++)
    {
        while (!st.empty() && h[st.front()] <= h[i])
        {
            st.pop_front();
        }

        if (st.empty())
        {
            L[i] = (v[i] - 1) * h[i] - (sum[i - 1] - sum[0]);
        }
        else
        {
            L[i] = L[st.front()] + (v[i] - v[st.front()] - 1) * h[i] - (sum[i - 1] - sum[st.front()]);
        }

        st.push_front(i);
    }

    while (!st.empty())
    {
        st.pop_front();
    }

    for (int i = n; i >= 1; i--)
    {
        while (!st.empty() && h[st.front()] <= h[i])
        {
            st.pop_front();
        }

        if(st.empty())
        {
            R[i] = (m - v[i] - 1) * h[i] - (sum[n] - sum[i]);
        }
        else
        {
            R[i] = R[st.front()] + (v[st.front()] - v[i] - 1) * h[i] - (sum[st.front() - 1] - sum[i]);
        }

        st.push_front(i);
    }

    sort(R + 1, R + n + 1);

    cin >> q;
    while (q--)
    {
        int k;
        cin >> k;
        int l = lower_bound(L + 1, L + n + 1, k) - L;
        int r = lower_bound(R + 1, R + n + 1, k) - R;
        l--;
        r--;
        cout << min(n, l + r) << "\n";
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    XuLy();
    return 0;
}

```
