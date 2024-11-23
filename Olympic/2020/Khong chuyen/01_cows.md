## Tiếng Việt



## English



## Chinese (简体中文)



---

## Duyệt

```cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n, s;
    cin >> n >> s;
    long long sum = 0;
    for(int i = 1; i <= n; ++i)
    {
        sum += i;
    }
    cout << sum - s;
    return 0;
}
```

## Toán học

```cpp
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, S;
    cin >> n >> S;
    cout << (n * (n + 1) / 2 - S) << '\n';
    return 0;
}
```
