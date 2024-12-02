## Tiếng Việt



## English




## Chinese (简体中文)



## Code: (Dạng QHD + sort)
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
    NX2: tồn tại 1 vị trí i tại cái cây bị hư hỏng sao cho phần phía trước của i các đoạn sửa chữa thì đổ về phía trước và phần phía sau của i gồm các đoạn đổ về sau
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
