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

const int MAX = 100'000;
int n, k, cur = 1, base, seg[MAX * 4];

void init()
{
	for (base = 1; base < n; base <<= 1);
	FOR(i, n) seg[base + i] = 1;
	for (int i = base - 1; i >= 1; i--) seg[i] = seg[i * 2] + seg[i * 2 + 1];
}

int f(int cur) {
	int i = 1;
	while (i < base) {
		seg[i]--;
		if (seg[i * 2] >= cur) {
			i = i * 2;
		}
		else {
			cur -= seg[i * 2];
			i = i * 2 + 1;
		}
	}
	seg[i]--;
	return i - base + 1;
}

signed main() {
	fastio;
	cin >> n >> k;
	init();
	cout << "<";
	FOR(i, n) {
		cur = (cur + k - 2) % (n - i) + 1;
		cout << f(cur);
		if (i != n - 1) cout << ", ";
	}
	cout << ">";
}
