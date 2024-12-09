## Tiếng Việt



## English



## Chinese (简体中文)



---

## Mảng cộng dồn + Stack đơn điệu + Sort + Chặt nhị phân

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

int td_vt[100005], cc_vt[100005], sumL[100005], L[100005], sumR[100005], R[100005];
int n, m, T;
stack<int> st; /// su dung stack de tim cac gia tri cot gan nhat co chieu cao lon nhat

void XuLy()
{
    cin >> n >> m;

    for(int i = 1; i <= n; ++i) cin >> td_vt[i];
    for(int i = 1; i <= n; ++i) cin >> cc_vt[i];

    /// Tao cac cot gia, dam bao se luon luon co cot cao, thap nhat de xet.
    /// Tranh loi khi truy cap ngoai pham vi hoac khong tim thay cot phu hop trong stack
    td_vt[0] = 0;
    td_vt[n + 1] = m;

    cc_vt[0] = 100005;
    cc_vt[n + 1] = 100005;

    for(int i = 1; i <= n; ++i)
    {
        sumL[i] = sumL[i - 1] + cc_vt[i];
    }
    for(int i = n; i >= 1; --i)
    {
        sumR[i] = sumR[i + 1] + cc_vt[i];
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
        while(!st.empty() && cc_vt[st.top()] < cc_vt[i])
        {
            st.pop();
        }
        L[i] = L[st.top()] + (td_vt[i] - td_vt[st.top()] - 1) * cc_vt[i] - (sumL[i - 1] - sumL[st.top()]);
        st.push(i);

    }

    while(!st.empty()) st.pop();

    /*
    Tinh tong chi phi tu phai sang trai, su dung stack de xac dinh cot cao nhat gan o ben phai
    Luc nay R[i] se duoc tinh dua tren:
    - Khoang cach tu cot cao nhat ben phai den cot hien tai la i
    - Chi phi duoc dieu chinh bang cach tru tong chieu cao cua 2 cot
    - 
    */

    st.push(n + 1);
    for(int i = n ; i >= 1; --i)
    {
        while(!st.empty() && cc_vt[st.top()] < cc_vt[i])
        {
            st.pop();
        }
        R[i] = R[st.top()] + (td_vt[st.top()] - td_vt[i] - 1) * cc_vt[i] - (sumR[i + 1] - sumR[st.top()] );
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


Phép tính này dùng để tính giá trị  R[i] , đại diện cho chi phí khi mở rộng từ cột  i  sang bên phải, đến cột cao hơn gần nhất (hoặc cột giả  n+1 ).

Ý nghĩa của từng thành phần
	
1. R[st.top()] :
	- Đây là chi phí đã tính được của cột cao hơn gần nhất bên phải của  i  (chỉ số  st.top()  lưu trong stack).
	- Kế thừa chi phí đã tính trước đó để tối ưu việc tính toán.
2. (td_vt[st.top()] - td_vt[i] - 1) * cc_vt[i] :
	- Đây là chi phí phát sinh do vùng trống giữa cột  i  và cột cao hơn gần nhất bên phải.
	- v[st.top()] - v[i] - 1 : Khoảng cách giữa hai cột (trừ 1 vì không tính cột tại  i  và  st.top() ).
	- h[i] : Độ cao của vùng đó được “lấp đầy” bởi chiều cao  h[i] .
3. (sumR[i + 1] - sumR[st.top()]) :
	- Tổng chiều cao của các cột nằm giữa  i+1  và  st.top() .
	- Chi phí (td_vt[st.top()] - td_vt[i] - 1) * cc_vt[i] tính toán vùng trống như là toàn bộ được lấp bởi h[i] , nhưng thực tế các cột giữa đã lấp một phần.
	Vì vậy, phần  sumR[i + 1] - sumR[st.top()]  được trừ đi để loại bỏ chiều cao thực tế đã được tính giữa  i+1  và  st.top() .

