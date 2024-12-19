#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(vr) vr.begin(), vr.end()
#define ld long double

void solve()
{
	ld x1, y1, x2, y2, x3, y3, x4, y4;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
	vector <ld> d(4);
	d[0]=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	d[1]=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
	d[2]=sqrt((x3-x4)*(x3-x4)+(y3-y4)*(y3-y4));
	d[3]=sqrt((x1-x4)*(x1-x4)+(y1-y4)*(y1-y4));
	sort(all(d));
	int t, cnt=0; cin >> t;
	while (t--) {
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
		vector <ld> t(4);
		t[0]=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
		t[1]=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
		t[2]=sqrt((x3-x4)*(x3-x4)+(y3-y4)*(y3-y4));
		t[3]=sqrt((x1-x4)*(x1-x4)+(y1-y4)*(y1-y4));
		sort(all(t));
		if (t==d) cnt++;
	}
	cout << cnt;
}

signed main()
{
	solve();
	return 0;
}
