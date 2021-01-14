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

int dx[] = { -2, -2, -1, -1,  1, 1,  2, 2 };
int dy[] = { -1,  1, -2,  2, -2, 2, -1, 1 };

const int MAX = 500'000;
int n, m, a, b, ans, uni[MAX];

int root(int x) {
	if (uni[x] < 0) return x;
	return uni[x] = root(uni[x]);
}

bool IsConnected(int a, int b) {
	return root(a) == root(b);
}

void Connect(int a, int b) {
	a = root(a); b = root(b);
	if (a == b) return;
	uni[a] += uni[b];
	uni[b] = a;
}

signed main() {
	fastio;
	ini(uni, -1);
	cin >> n >> m;
	FOR(i, m) {
		cin >> a >> b;
		if (IsConnected(a, b)) {
			ans = i + 1;
			break;
		}
		Connect(a, b);
	}
	cout << ans;
}
