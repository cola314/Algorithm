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

int n, m, dp[5010][5010], dpf[5010], a, b, uni[5010];

int s(int n, int k) {
	if (n < k) return 0;
	if (n == k || k == 1) return 1;
	if(dp[n][k] < 0) dp[n][k] = (s(n - 1, k - 1) + k * s(n - 1, k)) % MOD;
	return dp[n][k];
}

int f(int n) {
	int &ret = dpf[n];
	if (ret >= 0) return ret;
	ret = 0;
	for(int k=1; k<=n; k++) ret = (ret + s(n, k)) % MOD;
	return ret;
}

int root(int x) {
	if (uni[x] < 0) return x;
	return uni[x] = root(uni[x]);
}

void connect(int x, int y) {
	x = root(x); y = root(y);
	if (x == y) return;
	uni[x] += uni[y];
	uni[y] = x;
}

int isConnected(int x, int y) {
	return root(x) == root(y);
}

signed main() {
	fastio;
	ini(uni, -1); ini(dp, -1); ini(dpf, -1);	
	cin >> n >> m;
	int total = n;
	FOR(i, m) {
		cin >> a >> b;
		if (!isConnected(a, b)) {
			total--;
			connect(a, b);
		}
		cout << f(total) << endl;
	}
}