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

int k, maxv = -1, minv = 98765432100LL;
string s;
vi v, maxa, mina;

int calc(vi v) {
	int ret = 0;
	FOR(i, sz(v)) {
		ret *= 10;
		ret += v[i];
	}
	return ret;
}

signed main() {
	cin >> k;
	cin.ignore();
	getline(cin, s);
	FOR(i, 10) v.pb(i);
	sort(all(v));
	do {
		int flag = 1;
		FOR(i, k) {
			if (!((s[i * 2] == '<' && v[i] < v[i + 1]) || (s[i * 2] == '>' && v[i] > v[i + 1]))) {
				flag = 0;
			}
		}
		if (flag) {
			int t = calc(v);
			if (maxv < t) {
				maxv = t;
				maxa = v;
			}
			if (minv > t) {
				minv = t;
				mina = v;
			}
		}
	} while (next_permutation(all(v)));

	FOR(i, k + 1) cout << maxa[i];
	cout << endl;
	FOR(i, k + 1) cout << mina[i];
}
