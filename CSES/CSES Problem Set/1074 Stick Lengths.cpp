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

int dx[] = { 1, 2, 1, 2 };
int dy[] = { 2, 1, -2, -1 };

const int MAX = 2 * 10e5 + 10;
int n, maxv, ans = -1, arr[MAX], sum[MAX], sumr[MAX];

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    sort(arr + 1, arr + 1 + n);
    maxv = *max_element(arr + 1, arr + 1 + n);
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + maxv - arr[i];
    for (int i = n; i >= 1; i--) sumr[i] = sumr[i + 1] + arr[i];
    for (int i = 1; i <= n; i++) {
        int l = sum[i] - (maxv - arr[i]) * i;
        int r = sumr[i] - arr[i] * (n - i + 1);
        ans = (ans == -1 ? l + r : min(ans, l + r));
    }
    cout << ans;
}
