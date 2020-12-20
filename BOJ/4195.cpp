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

const int MAX = 200010;
int n, TC, uni[MAX];
string s1, s2;

int root(int x) {
	if (uni[x] < 0) return x;
	return uni[x] = root(uni[x]);
}

void connect(int a, int b) {
	a = root(a); b = root(b);
	if (a == b) return;
	uni[a] += uni[b];
	uni[b] = a;
}

int size(int a) {
	return -uni[root(a)];
}

signed main() {
	fastio;
	cin >> TC;
	while (TC--) {
		ini(uni, -1);
		int cnt = 1;
		map<string, int> M;
		cin >> n;
		FOR(i, n) {
			cin >> s1 >> s2;
			if (!M[s1]) M[s1] = cnt++;
			if (!M[s2]) M[s2] = cnt++;
			connect(M[s1], M[s2]);
			cout << size(M[s1]) << endl;
		}
	}
}