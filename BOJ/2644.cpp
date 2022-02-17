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

const int MAX = 110;
int n, m, a, b, x, y, visited[MAX], ans = -1;
vvi graph(MAX);
queue<ii> Q;

signed main() {
	cin >> n >> a >> b >> m;
	FOR(i, m) {
		cin >> x >> y;
		graph[x].pb(y);
		graph[y].pb(x);
	}
	Q.push(mp(a, 0));
	while (!Q.empty()) {
		auto [t, dis] = Q.front(); Q.pop();
		if (t == b) ans = dis;
		for (auto d : graph[t]) {
			if (!visited[d]) {
				visited[d] = true;
				Q.push(mp(d, dis + 1));
			}
		}
	}
	cout << ans;
}
