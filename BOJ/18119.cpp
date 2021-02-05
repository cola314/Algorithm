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

int n, m, t, forget;
char c;
string s;
vi v;

signed main() {
	fastio;
	cin >> n >> m;
	FOR(i, n) {
		cin >> s;
		v.pb(0);
		for (char c : s) v[i] |= (1 << (c - 'a'));
	}
	FOR(i, m) {
		cin >> t >> c;
		if (t == 1) forget |= (1 << (c - 'a'));
		else forget &= ~(1 << (c - 'a'));
		int cur = 0;
		FOR(i, n) if (!(forget & v[i])) cur++;
		cout << cur << endl;
	}
}
