> [Link](https://oj.vnoi.info/problem/olp_kc23_triangle)

## Vietnam
Cá nhân mình thấy tuy chỉ mới là bài toán mở đầu và là bài toán dễ, nhưng nó đã làm khó những bạn nào (như mình) không kỹ càng trong việc sử dụng các giới hạn dữ liệu cũng như về việc xử lý số thực. Do đó, nếu trong phòng thi ta không biết dùng trick này, đây có thể sẽ là 1 bài gây cảm giác ức chế và có thể làm xuống tinh thần của người làm. 

Ta chỉ cần biết một chút kiến thức về diện tích tam giác cũng như định lý Pytago là xong. 

Tuy nhiên, ở bài này, nếu bạn xử lý và xuất ra đáp án bằng việc xử lý trên số thực, rất có thể bạn sẽ không AC trọn vẹn bộ test này. 

Công thức của bài toán sẽ như sau: d = sqrt(u * u + v * v), và đáp án là d * d / 4 

Tuy nhiên, ta có thể thấy, ta lấy d = sqrt(u * u + v * v), thì d sẽ là số thực, sau đó ta lại bình phương, thì việc sai số sẽ trở nên tệ gấp đôi. Nhất là khi u và v có giới hạn tối đa 2 tỷ 

Trong mọi bài toán, nếu ta xử lý bằng số thực, bao giờ cũng không tốt bằng xử lý dựa trên số nguyên, vì số nguyên có sự chính xác 100% 

Vì đáp án ta cần là d * d và d = căn (u * u + v * v), do đó, thực tế d * d = u * u + v * v (d * d là một số nguyên) 

Vậy còn chuyện xuất ra số thực dưới dạng 2 chữ số thập phân thì sao, mình đã dùng 1 trick đó là xuất ra d * d / 4 và đặt 1 số dư là d * d % 4

Sau đó sẽ kiểm tra số dư, nếu là 0 thì xuất .00, là 1 thì xuất .25, là 2 thì xuất .50 và là 3 thì xuất .75



## English



## Chinese

---

```cpp
#include<bits/stdc++.h>
using namespace std;

unsigned long long u, v;

int main ()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> u >> v;
    unsigned long long S = u * u + v * v;
    unsigned long long d = S / 4;
    unsigned long long r = S % 4;
    cout << d << '.';
    if (r == 0)
    {
        cout << "00";
    }
    else if (r == 1)
    {
        cout << "25";
    }
    else if (r == 2)
    {
        cout << "50";
    }
    else
    {
        cout << "75";
    }
    return 0;
}
```
