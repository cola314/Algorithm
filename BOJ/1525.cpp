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

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

int n, t;
queue<ii> Q;
map<int, int> M;

int get_(int n, int x, int y) {
	int d = 1000000000;
	FOR(i, x + y * 3) d /= 10;
	return n % d / (d / 10);
}

int set_(int n, int x, int y, int v) {
	int d = 1000000000;
	FOR(i, x + y * 3) d /= 10;
	int cur = get_(n, x, y);
	n = n - cur * (d / 10) + v * (d / 10);
	return n;
}

int get_next(int cur, int idx) {
	FOR(i, 3) FOR(j, 3) if (get_(cur, i, j) == 0) {
		int x = i + dx[idx];
		int y = j + dy[idx];
		if (0 <= x && x < 3 && 0 <= y && y < 3) {
			int t = set_(cur, i, j, get_(cur, x, y));
			t = set_(t, x, y, 0);
			return t;
		}
	}
	return -1;
}

signed main() {
	FOR(i, 9) {
		cin >> t;
		n = n * 10 + t;
	}
	Q.push({ n, 0 });
	M[n] = 1;
	while (!Q.empty()) {
		auto [cur, dis] = Q.front(); Q.pop();
		if (cur == 123456780) return cout << dis, 0;
		FOR(i, 4) {
			int next = get_next(cur, i);
			if (next != -1 && !M[next]) {
				M[next] = 1;
				Q.push({ next, dis + 1 });
			}
		}
	}
	cout << -1;
}
