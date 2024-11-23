## Tiếng Việt



## English



## Chinese (简体中文)



---

## Duyệt + Xử lý mảng

```cpp
#include <bits/stdc++.h>
using namespace std;
string s;
int n, numQueries;
int cnt[26][1000005];

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> numQueries;
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        cnt[s[i] - 'a'][i + 1]++;
    }
    for (int c = 0; c < 26; c++)
    {
        for (int i = 1; i <= n; i++)
        {
            cnt[c][i] += cnt[c][i - 1];
        }
    }
    for (int query = 1; query <= numQueries; query++)
    {
        int l, r;
        cin >> l >> r;
        l++;
        r++;
        int numb = 0;
        for (int c = 0; c < 26; c++)
        {
            if ((cnt[c][r] - cnt[c][l - 1]) % 2 == 1)
            {
                numb++;
            }
        }
        cout << numb / 2 << "\n";
    }
    return 0;
}
```
