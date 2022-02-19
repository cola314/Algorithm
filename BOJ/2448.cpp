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

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

const int MAX = 3 * (1 << 10);
int n;
char arr[MAX][MAX * 3], ans[MAX][MAX * 3];

char m[][5] = {
	{1, 1, 1, 1, 1},
	{0, 1, 0, 1, 0 },
	{0, 0, 1, 0, 0},
};

void f(int n, int y, int x) {
	if (n == 3) {
		FOR(i, 3) FOR(j, 5) arr[y + i][x + j] = m[i][j];
		return;
	}
	f(n / 2, y, x);
	f(n / 2, y, x + n);
	f(n / 2, y + n / 2, x + n / 2);
}

signed main() {
	cin >> n;
	f(n, 0, 0);
	for(int i = n - 1; i >= 0; i--) {
		FOR(j, n * 2) {
			cout << (arr[i][j] ? '*' : ' ');
		}
		cout << endl;
	}
}
