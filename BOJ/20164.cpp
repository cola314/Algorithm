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

int a;

int getOddCnt(int n) {
	int cnt = 0;
	while (n > 0) {
		cnt += n % 2;
		n /= 10;
	}
	return cnt;
}

int getNumLen(int n) {
	int cnt = 0;
	while (n > 0) {
		cnt++;
		n /= 10;
	}
	return cnt;
}

int maxf(int n) {
	int cur = getOddCnt(n);
	if (n < 10) {
		return cur;
	}
	else if (n < 100) {
		cur += maxf(n / 10 + n % 10);
		return cur;
	}
	else {
		int maxv = 0;
		for (int i = 1; i < getNumLen(n) - 1; i++) {
			for (int j = i + 1; j < getNumLen(n); j++) {
				int t = (n % (int)pow(10L, i))
					+ (n % (int)pow(10L, j) / (int)pow(10L, i))
					+ (n / (int)pow(10L, j));

				maxv = max(maxv, maxf(t));
			}
		}
		return cur + maxv;
	}
}

int minf(int n) {
	int cur = getOddCnt(n);
	if (n < 10) {

		return cur;
	}
	else if (n < 100) {
		cur += minf(n / 10 + n % 10);
		return cur;
	}
	else {
		int minv = INF;
		for (int i = 1; i < getNumLen(n) - 1; i++) {
			for (int j = i + 1; j < getNumLen(n); j++) {
				int t = (n % (int)pow(10L, i))
					+ (n % (int)pow(10L, j) / (int)pow(10L, i))
					+ (n / (int)pow(10L, j));

				minv = min(minv, minf(t));
			}
		}
		return cur + minv;
	}
}

signed main() {
	cin >> a;
	cout << minf(a) << " " << maxf(a);
}