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

string s1, s2;

int solve(string s1, string s2) {
	int ans = 987654321;
	for (int i = 0; i <= s2.size() - s1.size(); i++) {
		int cnt = 0;
		for (int j = 0; j < s1.size(); j++) if (s1[j] != s2[i + j]) cnt++;
		ans = min(ans, cnt);
	}
	return ans;
}

signed main() {
	fastio;
	cin >> s1 >> s2;
	cout << solve(s1, s2);
}