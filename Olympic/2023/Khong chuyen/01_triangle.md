> [Link](https://oj.vnoi.info/problem/olp_kc23_triangle)

## Vietnam
Cá nhân mình thấy tuy chỉ mới là bài toán mở đầu và là bài toán dễ, nhưng nó đã làm khó những bạn nào (như mình) không kỹ càng trong việc sử dụng các giới hạn dữ liệu cũng như về việc xử lý số thực. Do đó, nếu trong phòng thi ta không biết dùng trick này, đây có thể sẽ là 1 bài gây cảm giác ức chế và có thể làm xuống tinh thần của người làm. 

Ta chỉ cần biết một chút kiến thức về diện tích tam giác cũng như định lý Pytago là xong. 

Tuy nhiên, ở bài này, nếu bạn xử lý và xuất ra đáp án bằng việc xử lý trên số thực, rất có thể bạn sẽ không AC trọn vẹn bộ test này. 

Công thức của bài toán sẽ như sau: d = sqrt(u * u + v * v), và đáp án là d * d / 4 

Tuy nhiên, ta có thể thấy, ta lấy d = sqrt(u * u + v * v), thì d sẽ là số thực, sau đó ta lại bình phương, thì việc sai số sẽ trở nên tệ gấp đôi. Nhất là khi u và v có giới hạn tối đa 2 tỷ 

Trong mọi bài toán, nếu ta xử lý bằng số thực, bao giờ cũng không tốt bằng xử lý dựa trên số nguyên, vì số nguyên có sự chính xác hoàn toàn 100% 

Vì đáp án ta cần là d * d và d = căn (u * u + v * v), do đó, ta sẽ có được d * d = u * u + v * v (d * d là một số nguyên) 

Vậy còn chuyện xuất ra số thực dưới dạng 2 chữ số thập phân thì sao, mình đã dùng 1 trick đó là xuất ra d * d / 4 và đặt 1 số dư là d * d % 4

Sau đó sẽ kiểm tra số dư, nếu là 0 thì xuất .00; là 1 thì xuất .25; là 2 thì xuất .50 và là 3 thì xuất .75


## English
Personally, I find that although this is just an introductory problem and an easy one at that, it can be challenging for those who (like me) are not meticulous in handling data constraints and dealing with floating-point numbers. Therefore, if we don’t know how to use this trick during the exam, this problem could become frustrating and potentially dampen the solver’s morale.

We only need a bit of knowledge about triangle area and the Pythagorean theorem, and that's it!

However, in this problem, if you handle and output the result using floating-point operations, it’s very likely that you won’t achieve a full AC on the test set.

The formula for the problem is as follows: d = sqrt(u * u + v * v), and the answer is d * d / 4

However, we can see that by taking d = sqrt(u * u + v * v),d becomes a floating-point number. Squaring it again will double the precision error, especially when u and v have a maximum limit of 2 billion.

In any problem, handling with floating-point numbers is never as good as working with integers, because integers provide complete and absolute 100% accuracy.

Since the answer we need is d * d and d = sqr(u * u + v * v), we can derive that d * d = u * u + v * v (d * d is an integer) 

So what about outputting a floating-point number with two decimal places? I used a trick, which is to output d * d / 4 and set the remainder as d * d % 4

Then, check the remainder. If it's 0, output .00; if it's 1, output .25; if it's 2, output .50; and if it's 3, output .75.

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
