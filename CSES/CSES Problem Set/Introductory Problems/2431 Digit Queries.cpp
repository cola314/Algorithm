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

int q, k;

int f(int n) {
	int ret = n, d = 10, i = 2;
	while (n >= d) {
		ret += n - d + 1;
		d *= 10;
		i++;
	}
	return ret;
}

vi rev(int n) {
	vi t;
	while (n) {
		t.pb(n % 10);
		n /= 10;
	}
	reverse(all(t));
	return t;
}

int answer(int n) {
	int l = 0, r = 100000000000000000LL, m, ans = 0;
	while (l <= r) {
		m = (l + r) / 2;
		if (f(m) < n) {
			ans = max(ans, m);
			l = m + 1;
		}
		else {
			r = m - 1;
		}
	}
	return rev(ans + 1)[n - f(ans) - 1];
}

signed main() {
	cin >> q;
	while (q--) {
		cin >> k;
		cout << answer(k) << endl;
	}
}