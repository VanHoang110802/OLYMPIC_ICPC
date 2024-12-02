## Tiếng Việt

- l[]: Mảng lưu trữ giá trị tối đa cây không hư hại mà robot không xử lý nếu bắt đầu từ cây a[i] và đi về phía bên trái.

- r[]: Mảng lưu trữ giá trị tối đa cây không hư hại mà robot không xử lý nếu bắt đầu từ cây a[i] và đi về phía bên phải. 

- Thêm giá trị 0 vào đầu mảng và n + 1 vào cuối mảng a[]. Điều này là để xử lý các trường hợp biên, giúp robot có thể bắt đầu di chuyển từ vị trí 0 và kết thúc tại vị trí n + 1.

- Tính toán mảng l[]:
    + Mảng l[i] lưu trữ số lượng cây không bị hư hại mà robot không xử lý nếu robot di chuyển từ vị trí a[i] về phía bên trái.
    + Cách tính l[i]:
        + Duyệt qua từng cây bị hư hại từ 1 đến m và sử dụng biến j (được sử dụng như một con trỏ) để tìm vị trí mà robot có thể di chuyển tới mà không gặp cây bị hư hại.
        + a[i] - k + 1 xác định vị trí mà robot có thể bắt đầu di chuyển.
        + l[j] lưu trữ số lượng cây không bị hư hại mà robot không xử lý từ vị trí j về phía trước.
        + max(0, a[i] - a[j] - k) tính toán số cây không bị hư hại trong đoạn từ a[j] đến a[i].

- Tính toán mảng r[]:
+ Mảng r[i] lưu trữ số lượng cây không bị hư hại mà robot không xử lý nếu robot di chuyển từ vị trí a[i] về phía bên phải.
+ Quy trình tương tự như mảng l[], nhưng lần này chúng ta di chuyển từ phải sang trái (từ cây bị hư hại cuối cùng đến cây bị hư hại đầu tiên).

- Duyệt qua tất cả các vị trí từ 0 đến m và tính toán giá trị tối ưu cho ans.
- l[i] + r[i + 1] là tổng số cây không bị hư hại mà robot không xử lý nếu robot bắt đầu từ vị trí a[i] và kết thúc tại vị trí a[i + 1].
- a[i + 1] - a[i] - 1 tính toán số lượng cây không bị hư hại giữa a[i] và a[i + 1] (không tính các cây bị hư hại).
- Từ đó, giá trị tối đa ans được tính toán.

## English




## Chinese (简体中文)



## Code: (Dạng QHD + sort + hai con trỏ)
```cpp
#include <iostream>
using namespace std;

int a[200010], l[200010], r[200010];
int n, k, m, ans = 0;

void XuLy()
{
    cin >> n >> k >> m;
    for(int i = 1; i <= m; ++i)
        cin >> a[i];
    /// thêm vào 2 cây giả bị hư hại tại vị trí 0 và vị trí m+1
    a[0] = 0;
    a[m + 1] = n + 1;
    /// sắp xếp các cây bị hư hại theo vị trí tăng dần
    sort(a, a + m + 2);
    /*
    NX1: mỗi đoạn cần sửa chữa sẽ có 1 trong 2 đầu mút tại vị trí của cây bị hư hỏng
    NX2: tồn tại 1 vị trí i tại cái cây bị hư hỏng sao cho phần phía trước của i các đoạn sửa chữa thì đổ về phía trước
         và phần phía sau của i gồm các đoạn đổ về sau
    */
    /// l[i]: số cây ko bị hỏng tối đa nếu các đoạn sửa chữa đổ về phía trước của i
    l[0] = 0;
    for(int i = 1, j = 0; i <= m; ++i)
    {
        // tìm vị trí j lớn nhất của cây hư hỏng ko thuộc vào đoạn sửa chữa cuối cùng của i
        while(a[i] - k + 1 > a[j + 1])
            j++;

        l[i] = l[j] + max(0, a[i] - a[j] - k);
    }
    /// r[i]: số cây ko bị hỏng tối đa nếu các đoạn sửa chữa đổ về phía sau của i
    r[m + 1] = 0;
    for(int i = m, j = m + 1; i >= 1; --i)
    {
        /// tìm vị trí j lớn nhất của cây hư hỏng ko thuộc vào đoạn sửa chữa cuối cùng của i
        while(a[i] + k - 1 < a[j - 1])
            j--;

        r[i] = r[j] + max(0, a[j] - a[i]-k);
    }
    /// ta duyệt mọi vị trí của i (i: 0...m) để tìm KQ tối ưu
    for(int i = 0; i <= m; i++)
        ans = max(ans, l[i] + r[i + 1] + a[i + 1] - a[i] - 1);

    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    XuLy();
    return 0;
}

```
