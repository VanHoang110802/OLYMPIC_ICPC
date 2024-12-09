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

/* f là mảng tính tổng các độ cao dùng prefixsum từ trái sang, g là từ phải sang
 sumf là mảng tổng lượng nước cho cần tại mỗi cột cũng dùng prefixsum
 sumf[i] xây dựng bằng cách tìm phần tử lớn nhất gần i nhất bằng stack
 sau đó tính lượng nước cần từ vị trí đó đến i
 trong đoạn từ vị trí đó đến i-1 thì tính xem tổng các cột nằm trong bằng bao nhiêu để trừ đi
*/

/// Bai nay giong dang bai "next greater element", tinh toan cac khoang cach dua vao cac chieu cao

#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

#define int long long

int v[100005], h[100005], sumL[100005], L[100005], sumR[100005], R[100005];
int n, m, T;
stack<int> st; /// su dung stack de tim cac gia tri cot gan nhat co chieu cao lon nhat

void XuLy()
{
    cin >> n >> m;

    for(int i = 1; i <= n; ++i) cin >> v[i];
    for(int i = 1; i <= n; ++i) cin >> h[i];

    /// Tao cac cot gia
    v[0] = 0;
    v[n + 1] = m;

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

    /*
    Tinh tong chi phi tu trai sang phai, su dung stack de xac dinh cot cao nhat gan o ben trai
    Luc nay L[i] se duoc tinh dua tren:
    - Khoang cach tu cot cao nhat ben trai den cot hien tai la i
    - Chi phi duoc dieu chinh bang cach tru tong chieu cao cua 2 cot
    */

    st.push(0);
    for(int i = 1; i <= n; ++i)
    {
        while(!st.empty() && h[st.top()] < h[i])
        {
            st.pop();
        }
        L[i] = L[st.top()] + (v[i] - v[st.top()] - 1) * h[i] - (sumL[i - 1] - sumL[st.top()]);
        st.push(i);

    }

    while(!st.empty()) st.pop();

    /*
    Tinh tong chi phi tu phai sang trai, su dung stack de xac dinh cot cao nhat gan o ben phai
    Luc nay R[i] se duoc tinh dua tren:
    - Khoang cach tu cot cao nhat ben phai den cot hien tai la i
    - Chi phi duoc dieu chinh bang cach tru tong chieu cao cua 2 cot
    */

    st.push(n + 1);
    for(int i = n ; i >= 1; --i)
    {
        while(!st.empty() && h[st.top()] < h[i])
        {
            st.pop();
        }
        R[i] = R[st.top()] + (v[st.top()] - v[i] - 1) * h[i] - (sumR[i + 1] - sumR[st.top()] );
        st.push(i);
    }

    cin >> T;
    for(int i = 1; i <= T; ++i)
    {
        int k; cin >> k;
        /// Su dung tknp de tim so luong cot tu trai sang
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

        /// Su dung tiep tknp de tim so luong cot tu phai sang
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
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    XuLy();
    return 0;
}

```
