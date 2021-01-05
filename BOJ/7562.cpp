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

int TC, l, a, b, c, d, check[300][300];

signed main() {
    fastio;
	cin >> TC;
	while (TC--) {
		cin >> l >> a >> b >> c >> d;
		ini(check, -1);
		queue<ii> Q; Q.push({ a, b });
		check[a][b] = 0;
		while (!Q.empty()) {
			auto [x, y] = Q.front(); Q.pop();
			if (x == c && y == d) {
				cout << check[x][y] << endl;
				break;
			}
			FOR(i, 8) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (0 <= nx && nx < l && 0 <= ny && ny < l && check[nx][ny] == -1) {
					Q.push({ nx, ny });
					check[nx][ny] = check[x][y] + 1;
				}
			}
		}
	}
}