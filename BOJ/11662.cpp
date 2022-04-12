#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(),x.end()
#define y1 omg
#define INF 1000000010
#define FOR(x, n) for(int x=0; x<n; x++)
#define ini(x, n) memset(x, n, sizeof(x));
#define MOD ((int)1e9 + 7)
#define atoi(x) ((x)-'0')
#define int ll
#define double long double
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

//int dx[] = { 1, 2, 1, 2 };
//int dy[] = { 2, 1, -2, -1 };

double ax, ay, bx, by, cx, cy, dx, dy, s = 0, e = 1, ans = INF;

auto f(double t) {
	auto x1 = ax + (bx - ax) * t;
	auto y1 = ay + (by - ay) * t;
	auto x2 = cx + (dx - cx) * t;
	auto y2 = cy + (dy - cy) * t;
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

signed main() {
	cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;
	FOR(i, 100000) {
		double m1 = s + (e - s) / 3;
		double m2 = s + (e - s) * 2 / 3;
		double v1 = f(m1), v2 = f(m2);
		if (v1 < v2) {
			e = m2;
		}
		else if (v1 > v2) {
			s = m1;
		}
		else {
			s = m1, e = m2;
		}
		ans = min(ans, v1);
		ans = min(ans, v2);
	}
	cout << fixed << setprecision(9) << ans;
}
