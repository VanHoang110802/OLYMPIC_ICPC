## Tiếng Việt



## English



## Chinese (简体中文)



---

## Chưa AC

```cpp

#include <bits/stdc++.h>
using namespace std;
// Thuật toán Euclid tính ước chung lớn nhất
int gcd(int a, int b)
{
    a = abs(a);
    b = abs(b);

    // Đảm bảo a >= b
    if (b > a)
    {
        swap(a, b);
    }

    int temp;
    while (b > 0)
    {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

string decimalization(int p, int q)
{

    q = abs(q);
    p = abs(p);

    p %= q;

    if (p)   // Nếu chia dư, tính phần thập phân
    {

        int g = gcd(p, q);
        p /= g, q /= g;

        deque<int> remain; // Lưu các số dư, có thể dùng STL set để cho cải thiện tốc độ tìm kiếm
        deque<char> dec;    // Lưu các chữ số thập phân,
        remain.push_back(p);

        deque<int>::iterator ri = remain.end();
        while (p)
        {
            p *= 10;
            dec.push_back(p / q + '0');
            p %= q;
            ri = find(remain.begin(), remain.end(), p); // Tìm xem phần dư hiện tại có được lặp lại hay không ?

            if (ri == remain.end())
            {
                // Nếu không thì thêm số dư hiện tại vào deque
                remain.push_back(p);
            }
            else
            {
                // Nếu có thì kết thúc phần tuần hoàn
                break;
            }
        }

        deque<char>::iterator begin_sequence = dec.begin() + (ri - remain.begin());

        // Phần không tuần hoàn



        // Phần tuần hoàn
        if (begin_sequence != dec.end())
        {
            return "repeating\n";
        }
        else return "finite\n";
    }
    else return "finite\n";
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector <int> a(n+1, 1);
        vector <int> b(n+1, 1);
        int x = n % 10;
        for(int i=0; i<x; ++i) cin >> a[i];
        for(int i=0; i<x; ++i) cin >> b[i];
        for(int i=0; i<x; ++i)
        {
            cout << decimalization(a[i] * a[i+1], b[i] * b[i+1]);
        }
    }
    return 0;
}
```
