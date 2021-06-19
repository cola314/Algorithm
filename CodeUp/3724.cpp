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

int dx[] = { -2, -2, -1, -1,  1, 1,  2, 2 };
int dy[] = { -1,  1, -2,  2, -2, 2, -1, 1 };

const int MAX = 300'010;
int n, t, memor[MAX][2], memol[MAX][2], ans = -INF;
vi v;

int fr(int x, bool flag) {
	int& ret = memor[x][flag];
	if (ret != -INF) {
		return ret;
	}
	if (x == n - 1) {
		return ret = v[x];
	}
	if (flag) {
		return ret = max(fr(x + 1, true) + v[x], v[x]);
	}
	else {
		return ret = max(v[x], max(fr(x + 1, true) + v[x], fr(x + 1, false)));
	}
}

int fl(int x, bool flag) {
	int& ret = memol[x][flag];
	if (ret != -INF) {
		return ret;
	}
	if (x == 0) {
		return ret = v[x];
	}
	if (flag) {
		return ret = max(fl(x - 1, true) + v[x], v[x]);
	}
	else {
		return ret = max(v[x], max(fl(x - 1, true) + v[x], fl(x - 1, false)));
	}
}

signed main() {
	fastio;
	FOR(i, MAX) FOR(j, 2) memor[i][j] = memol[i][j] = -INF;
	cin >> n;
	FOR(i, n) {
		cin >> t;
		v.pb(t);
	}
	FOR(i, n) {
		ans = max(ans, fr(i, true));
	}
	FOR(i, n - 1) {
		ans = max(ans, fl(i, false) + fr(i + 1, false));
	}
	cout << ans;
}
