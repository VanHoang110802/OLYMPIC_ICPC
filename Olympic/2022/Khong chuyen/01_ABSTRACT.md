## Tiếng Việt



## English



## Chinese (简体中文)



---

## Duyệt + Xử lý mảng (mảng đánh dấu)

```cpp
#include <bits/stdc++.h>
using namespace std;

int n, m, h[1005][1005];
bool seen[1005][1005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> h[i][j];
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        {
            int mx = 0;
            for (int j = 1; j <= m; ++j)
            {
                if (mx < h[i][j])
                {
                    mx = h[i][j];
                    seen[i][j] = true;
                }
            }
        }

        {
            int mx = 0;
            for (int j = m; j >= 1; --j)
            {
                if (mx < h[i][j])
                {
                    mx = h[i][j];
                    seen[i][j] = true;
                }
            }
        }
    }

    for (int j = 1; j <= m; ++j)
    {
        {
            int mx = 0;
            for (int i = 1; i <= n; ++i)
            {
                if (mx < h[i][j])
                {
                    mx = h[i][j];
                    seen[i][j] = true;
                }
            }
        }

        {
            int mx = 0;
            for (int i = n; i >= 1; --i)
            {
                if (mx < h[i][j])
                {
                    mx = h[i][j];
                    seen[i][j] = true;
                }
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            ans += seen[i][j];
        }
    }
    cout << ans << '\n';

    return 0;
}
```
