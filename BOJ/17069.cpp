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

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int n, arr[40][40], dp[40][40][3];

int check(int y, int x) {
	return y < 0 || y >= n || x < 0 || x >= n || arr[y][x];
}


int f(int y, int x, int r) {
	if (check(y, x)) return 0;
	if (r == 2 && (check(y - 1, x - 1) || check(y, x - 1) || check(y - 1, x))) return 0;
	if (y == n - 1 && x == n - 1) return 1;
	int& ret = dp[y][x][r];
	if (ret != -1) return ret;
	if (r == 0) ret = f(y, x + 1, 0) + f(y + 1, x + 1, 2);
	if (r == 1) ret = f(y + 1, x, 1) + f(y + 1, x + 1, 2);
	if (r == 2) ret = f(y, x + 1, 0) + f(y + 1, x, 1) + f(y + 1, x + 1, 2);
	return ret;
}

signed main() {
	ini(dp, -1);
	cin >> n;
	FOR(i, n) FOR(j, n) cin >> arr[i][j];
	cout << f(0, 1, 0);
}