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

int n;
vector<double> v(100);
string s;
stack<double> ST;
double ret;

signed main() {
	cin >> n >> s;
	FOR(i, n) cin >> v[i];
	for (auto c : s) {
		if ('A' <= c && c <= 'Z') {
			ST.push(v[c - 'A']);
		}
		else {
			double b = ST.top(); ST.pop();
			double a = ST.top(); ST.pop();
			if (c == '+') ST.push(a + b);
			if (c == '-') ST.push(a - b);
			if (c == '*') ST.push(a * b);
			if (c == '/') ST.push(a / b);
		}
	}
	cout << fixed << setprecision(2) << ST.top();
}
