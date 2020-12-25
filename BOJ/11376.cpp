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
//#define double long double
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int dx[] = { 1, -1, 0, 0, 1, 1, -1, -1 };
int dy[] = { 0, 0, 1, -1, 1, -1, 1, -1 };

const int MAX = 1010;
int n, m, k, t, ans, visited[MAX], selected[MAX];
vvi graph(MAX);

int dfs(int x) {
	for (int y : graph[x]) {
		if (visited[y]) continue;
		visited[y] = 1;
		if (selected[y] == -1 || dfs(selected[y])) {
			selected[y] = x;
			return 1;
		}
	}	
	return 0;
}

signed main() {
	fastio;
	cin >> n >> m;
	FOR(i, n) {
		cin >> k;
		while(k--) {
			cin >> t;
			t--;
			graph[i].pb(t);
		}
	}
	ini(selected, -1);
	FOR(j, 2) FOR(i, n) {
		ini(visited, 0);
		if (dfs(i))
			ans++;
	}
	cout << ans;
}