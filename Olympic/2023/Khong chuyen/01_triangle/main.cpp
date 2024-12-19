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

