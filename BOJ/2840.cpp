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

int n, m, cur;
char arr[30], check[200];

signed main() {
	cin >> n >> m;
	ini(arr, '?');
	FOR(i, m) {
		int k; char c;
		cin >> k >> c;
		cur = ((cur - k) % n + n) % n;
		if (arr[cur] != c && arr[cur] != '?') return cout << '!', 0;
		arr[cur] = c;
	}
	FOR(i, n) {
		if (check[arr[i]] > 0 && arr[i] != '?')
			return cout << '!', 0;
		check[arr[i]]++;
	}
	FOR(i, n) {
		cout << arr[(cur + i) % n];
	}
}