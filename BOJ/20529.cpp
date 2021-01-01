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
//#define int ll
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

int TC, n;
string s;
map<string, int> M;
vector<string> v;

int f(int a, int b) {
	int ret = 0;
	FOR(i, 4) ret += v[a][i] != v[b][i];
	return ret;
}

signed main() {
	fastio;
	cin >> TC;
	while (TC--) {
		int ans = INF;
		v.clear(); M.clear();
		cin >> n;
		FOR(i, n) {
			cin >> s;
			M[s]++;
			if (M[s] <= 3)
				v.pb(s);
		}
		n = sz(v);
		FOR(i, n) FOR(j, n) FOR(k, n) if (i != j && j != k && k != i) {
			ans = min(ans, f(i, j) + f(j, k) + f(k, i));
		}
		cout << ans << endl;
	}
}