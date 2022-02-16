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

const int MAX = 1000 + 10;
int n, k, arr[MAX], visited[MAX], com[MAX], curid, comsize[MAX], cyclelen[MAX], dp[MAX][MAX];
vvi graph;

void check_cycle(int node) {
	int cur, id, cycle = 0; stack<int> st;
	for (cur = node; !visited[cur]; cur = arr[cur]) {
		visited[cur] = true;
		st.push(cur);
	}
	if (com[cur] == 0) id = ++curid;
	else id = com[cur];
	int flag = (com[cur] == 0);
	while (!st.empty()) {
		int t = st.top(); st.pop();
		if (flag) {
			if (cur != t) cyclelen[id]++;
			else flag = 0;
		}
		com[t] = id;
		comsize[id]++;
	}
}

int f(int cur, int remain) {
	if (cur > curid) return 0;
	int& ret = dp[cur][remain];
	if (ret != -1) 
		return ret;
	for (int i = cyclelen[cur]; i <= comsize[cur] && remain - i >= 0; i++) {
		ret = max(ret, f(cur + 1, remain - i) + i);
	}
	ret = max(ret, f(cur + 1, remain));
	return ret;
}

signed main() {
	ini(dp, -1);
	cin >> n >> k;
	FOR(i, n) {
		cin >> arr[i]; arr[i]--;
	}
	FOR(i, n) {
		check_cycle(i);
	}
	FOR(i, MAX) cyclelen[i]++;
	cout << f(1, k);
}
