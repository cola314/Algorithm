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

const int MAX = 60;
int n, t, root, deleted[MAX];
vvi graph(MAX);

void DeleteNode(int t) {
	deleted[t] = 1;
	for (int i : graph[t]) {
		DeleteNode(i);
	}
}

int CountLeafNode(int t) {
	int cnt = 0;
	for (int i : graph[t]) {
		cnt += CountLeafNode(i);
	}
	if (cnt == 0) cnt = !deleted[t];
	return cnt;
}

signed main() {
	cin >> n;
	FOR(i, n) {
		cin >> t;
		if (t == -1) root = i;
		else graph[t].pb(i);
	}
	cin >> t;
	DeleteNode(t);
	cout << CountLeafNode(root);
}