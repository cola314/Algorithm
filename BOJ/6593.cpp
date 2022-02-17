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

int dx[] = { 1, -1, 0, 0, 0, 0 };
int dy[] = { 0, 0, 1, -1, 0, 0 };
int dz[] = { 0, 0, 0, 0, 1, -1 };

struct POS { int x, y, z; };

const int MAX = 30;
int l, r, c, visited[MAX][MAX][MAX];
string arr[MAX][MAX];
POS s, e;
queue<pair<POS, int>> Q;

signed main() {
	while (true) {
		int ans = -1;
		ini(visited, 0);
		cin >> l >> r >> c;
		if (l + r + c == 0) break;
		FOR(i, l) {
			FOR(j, r) {
				cin >> arr[i][j];
			}
		}
		FOR(i, l) FOR(j, r) FOR(k, c) {
			if (arr[i][j][k] == 'S') s = { i, j, k };
			else if (arr[i][j][k] == 'E') e = { i, j, k };
		}
		Q.push({ s, 0 });
		while (!Q.empty()) {
			auto [t, dis] = Q.front(); Q.pop();
			if (t.x == e.x && t.y == e.y && t.z == e.z) ans = dis;
			FOR(i, 6) {
				POS next = t;
				next.x += dx[i]; next.y += dy[i]; next.z += dz[i];
				if (next.x < 0 || next.y < 0 || next.z < 0 || next.x >= l || next.y >= r || next.z >= c) continue;
				if (arr[next.x][next.y][next.z] == '#') continue;
				if (!visited[next.x][next.y][next.z]) {
					visited[next.x][next.y][next.z] = true;
					Q.push({ next, dis + 1 });
				}
			}
		}
		if (ans == -1) cout << "Trapped!" << endl;
		else cout << "Escaped in " << ans << " minute(s)." << endl;
	}
}
