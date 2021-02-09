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

string s, bomb;
stack<char> st;
stack<char> temp;

signed main() {
	fastio;
	cin >> s >> bomb;
	FOR(i, sz(s)) {
		st.push(s[i]);
		char hasBomb = 1;
		if (sz(st) >= sz(bomb)) {
			FOR(i, sz(bomb)) {
				if (bomb[sz(bomb) - i - 1] == st.top()) {
					temp.push(st.top());
					st.pop();
				}
				else {
					hasBomb = 0;
				}
			}
			if (!hasBomb) while (!temp.empty()) st.push(temp.top()), temp.pop();
			else {
				while (!temp.empty()) temp.pop();
			}
		}
	}
	if (st.empty()) {
		cout << "FRULA";
		return 0;
	}
	while (!st.empty()) temp.push(st.top()), st.pop();
	while (!temp.empty()) {
		cout << temp.top(); temp.pop();
	}
}
