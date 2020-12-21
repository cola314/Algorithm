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
#define int unsigned long long
//#define double long double
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

//int dx[] = { 1, -1, 0, 0, 1, 1, -1, -1 };
//int dy[] = { 0, 0, 1, -1, 1, -1, 1, -1 };

int n, ans, cur = 4, cnt = 0;

signed main() {
	cin >> n;
	int a = 1, b = 2;
	while (b <= n) {
		if (n % b == 0) {
			ans = n / b * a;
			cnt = cur;
		}
		cur++;
		int t = a + b;
		a = b;
		b = t;
	}
	if (ans) cout << ans << " " << cnt;
	else cout << -1;
}