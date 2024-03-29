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

const int MAX = 2000;
int n, m, a, b;
vvi graph(MAX);
vi visited(MAX);

int f(int start, int curdep = 1) {
	if (visited[start])
		return 0;
	if (curdep >= 5)
		return 1;
	visited[start] = 1;

	for (auto x : graph[start]) {
		if (f(x, curdep + 1))
			return 1;
	}

	visited[start] = 0;
	return 0;
}

signed main() {
	cin >> n >> m;
	FOR(i, m) {
		cin >> a >> b;
		graph[a].pb(b);
		graph[b].pb(a);
	}
	FOR(i, n) {
		if (f(i)) {
			cout << 1;
			return 0;
		}
	}
	cout << 0;
}
