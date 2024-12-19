#include <iostream>
#include <algorithm>
using namespace std;

int n, m, k;
int a[200005];

/*
n: Tổng số tọa độ (chiều dài của đoạn đường).
m: Số cây bị hư hại.
k: Chiều dài đoạn robot có thể xử lý mỗi lần.
a[]: Mảng lưu các tọa độ cây bị hư hại.

- Vì m <= 2.10^5, nên ta sắp xếp các toạ độ là cây bị hư theo thứ tự tăng dần
- Với k là vị trí đã được cho trước, mà theo đề bài, ta có được dữ kiện là: "Khoảng cách giữa 2 tọa độ liên tiếp cung cấp điều khiển robot không được nhỏ hơn k" -> a[i + 1] - a[i] >= k -> lúc này ta sẽ chặt nhị phân trên mảng a để tìm cái giá trị >= k.
- Duyệt qua các vị trí từ 1 đến giá trị >= k để kiểm tra xem nếu robot bắt đầu xử lý từ mỗi vị trí như vậy thì số cây không bị hư hại và không bị xử lý là bao nhiêu
*/

int solve(int x) ///tính số cây không bị hư hại trong một đoạn đường mà robot xử lý từ vị trí st trở đi
{
    int re = 0;
    while(x <= m)
    {
        int fi = upper_bound(a + 1, a + m + 1, a[x] + k - 1) - a; /// tìm vị trí đầu tiên trong mảng a[] có giá trị lớn hơn a[st] + k - 1
                                                          /// tức là tìm tọa độ cây bị hư hại xa nhất mà robot có thể xử lý bắt đầu từ vị trí a[st] và kéo dài trong đoạn dài k.
        /// fi chính là vị trí của cây bị hư hại sau khi robot xử lý xong đoạn đầu tiên.
        re = re + min(k, n - a[x] + 1); /// Tính số cây không bị hư hại mà robot xử lý trong đoạn từ vị trí a[st] đến a[st] + k - 1.
        x = fi;  /// Sau khi xử lý xong một đoạn, robot di chuyển đến vị trí fi để tiếp tục xử lý.
    }
    return re;
}

int main()
{
    cin >> n >> k >> m;
    for(int i = 1; i <= m; i++)
        cin >> a[i];

    if(m == 0) /// Nếu không có cây bị hư hại (m == 0), thì không có cây nào cần xử lý, in ra 0 và kết thúc chương trình.
    {
        cout << 0;
        return 0;
    }

    sort(a + 1, a + m + 1); /// Sắp xếp các tọa độ cây bị hư hại theo thứ tự tăng dần để thuận tiện cho việc xử lý.
    int tmp = upper_bound(a + 1, a + m + 1, k) - a; /// Tìm vị trí đầu tiên trong mảng a[] có giá trị lớn hơn k. Đây là bước chuẩn bị để tìm ra số cây không bị hư hại mà không bị xử lý nếu robot bắt đầu xử lý từ các tọa độ khác nhau.
    int ma = -2000000009;
    for(int i = 1; i <= tmp; i++) /// Duyệt qua các vị trí từ 1 đến tmp để kiểm tra xem nếu robot bắt đầu xử lý từ mỗi vị trí như vậy thì số cây không bị hư hại và không bị xử lý là bao nhiêu. Lưu giá trị tối đa vào ma.
    {
        ma = max(ma, n - solve(i) - a[i - 1]);
    }
    cout << ma; /// in ra giá trị tối đa ma mà robot không xử lý và không làm hư hại.
    return 0;
}

