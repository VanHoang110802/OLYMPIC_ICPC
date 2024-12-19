#include <iostream>
#include <cmath>
using namespace std;

char a[1000007];
int seg[4000007][26];
int n, q;

void Build_Seg(int id, int le, int ri)
{
    if(le == ri)
    {
        seg[id][a[le] - 'a'] = 1;
        return;
    }

    int mid = (le + ri) >> 1;
    Build_Seg(2 * id, le, mid);
    Build_Seg(2 * id + 1, mid + 1, ri);

    for(int i = 0; i <= 25; ++i)
    {
        seg[id][i] = seg[2 * id][i] + seg[2 * id + 1][i];
    }
}

int Query_Seg(int id, int le, int ri, int u, int v, int ch)
{
    if(le > v || ri < u)
    {
        return 0;
    }
    if(u <= le && ri <= v)
    {
        return seg[id][ch];
    }
    int mid = (le + ri) >> 1;

    return Query_Seg(2 * id, le, mid, u, v, ch) + Query_Seg(2 * id + 1, mid + 1, ri, u, v, ch);
}

signed main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n >> q;
    for(int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    Build_Seg(1, 1, n);
    while(q--)
    {
        int x, y;
        cin >> x >> y;
        ++x;
        ++y;
        int ans = 0;
        for(int i = 0; i <= 25; ++i)
        {
            if(Query_Seg(1, 1, n, x, y, i) & 1)
            {
                ++ans;
            }
        }
        cout << ((ans <= 1) ? 0 : ceil(ans / 2)) << "\n";
    }

    return 0;
}
