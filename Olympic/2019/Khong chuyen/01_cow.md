## Tiếng Việt

- Mỗi đống rơm được biểu diễn là một hình tròn trên mặt phẳng tọa độ, đống rơm thứ 𝑖 có tọa độ tâm là (x, y) và bán kính r.
- Tại một điểm (a, b) bất kì sẽ cột con bò ở đó với bán kính là l.
- Ta hình dung được rằng: Khi hai đường tròn giao nhau thì đồng nghĩa 2 bán kính l, r sẽ tạo thành 1 đường thẳng. Gọi đường thẳng đó là d.
- Giao nhau khi: l + r = d.
- Nếu mà không giao nhau thì l + r < d. Nghĩa là tổng 2 bán kính không bằng đoạn thẳng được nối từ điểm bán kính này đến bán kính kia.

-> l < d - r.

Nhưng đó chỉ là ta đang xét 1 hình tròn, tức là chỉ có một bó cỏ. Đây đề cho là n bó cỏ. Thì l càng thấp thì bò sẽ càng không ăn được bất
kì một bó cỏ nào cả. Vậy nên ta chỉ cần tìm min là xong.

## English



## Chinese (简体中文)



## Code (Dạng: Duyệt + số học)

```cpp
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

#define int long long

void XuLy()
{
    int n, a, b; cin >> n >> a >> b;
    double MIN = 1000000000000000000;
    for(int i = 1; i <= n; ++i)
    {
        int x, y, r; cin >> x >> y >> r;
        double l = sqrt(pow(x - a, 2) + pow(y - b, 2)) - r;
        MIN = min(MIN, l);
    }
    int tmp = MIN;
    if(tmp == MIN) cout << tmp - 1;
    else cout << tmp;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    XuLy();
    return 0;
}

```
