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

string s;

int f(string s, int n) {
	int ret = 0;
	for (char c : s) {
		ret *= n;
		if ('0' <= c && c <= '9') ret += c - '0';
		else ret += c - 'a' + 10;
	}
	return ret;
}

signed main() {
	cin >> s;
	if (sz(s) >= 3 && s[1] == 'x') cout << f(s.substr(2), 16);
	else if (s[0] == '0') cout << f(s, 8);
	else cout << s;
}