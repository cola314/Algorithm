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

int dx[] = { 1, 2, 1, 2 };
int dy[] = { 2, 1, -2, -1 };

int n, m, t, k, a, b, ans;
vi A, B;

signed main() {
	cin >> n >> m >> k;
	FOR(i, n) cin >> t, A.pb(t);
	FOR(i, m) cin >> t, B.pb(t);
	sort(all(A)); sort(all(B));
	while (a < sz(A) && b < sz(B)) {
		if (abs(A[a] - B[b]) <= k) {
			ans++;
			a++; b++;
		}
		else if (A[a] < B[b]) a++;
		else b++;
	}
	cout << ans;
}
