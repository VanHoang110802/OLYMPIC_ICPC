#include <iostream>
#include <algorithm>
using namespace std;

long long a[100007], pref[100007], seg[420007];

void Build_Seg(int id, int le, int ri)
{
    if(le == ri)
    {
        seg[id] = a[le];
        return;
    }

    int mid = (le + ri) >> 1;
    Build_Seg(2 * id, le, mid);
    Build_Seg(2 * id + 1, mid + 1, ri);

    seg[id] = max(seg[2 * id], seg[2 * id + 1]);
}

long long Get_Seg(int id, int le, int ri, int u, int v)
{
    if(le > v || ri < u)
    {
        return 0LL;
    }
    if(le >= u && ri <= v)
    {
        return seg[id];
    }

    int mid = (le + ri) >> 1;
    long long Get_1 = Get_Seg(2 * id, le, mid, u, v);
    long long Get_2 = Get_Seg(2 * id + 1, mid + 1, ri, u, v);

    return max(Get_1, Get_2);
}

void XuLy()
{
    int n, k, cnt = 0; cin >> n >> k;
    for(int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }
    Build_Seg(1, 1, n);
    for(int i = 1; i <= n - k + 1; ++i)
    {
        long long tmp_1 = pref[i + k - 1] - pref[i - 1];
        long long tmp_2 = Get_Seg(1, 1, n, i, i + k - 1);
        if(tmp_1 >= tmp_2 + tmp_2) cnt++;
    }
    cout << cnt;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    XuLy();
    return 0;
}