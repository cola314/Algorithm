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
//#define int ll
#define double long double
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

const int MAX = 2e5 + 10;
int n, q, t, x, y, s, e, idx[MAX], arr[MAX], cur;

signed main() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> t, arr[i] = t, idx[t] = i;
    for (int i = 1; i <= n; i++) if (idx[i] > idx[i + 1]) cur++;
    while(q--) {
        cin >> x >> y;
        if (arr[x] > arr[y]) swap(x, y);
        cur += (idx[arr[x] - 1] < x) - (idx[arr[x] - 1] < y);
        if (arr[x] + 1 != arr[y]) {
            cur += (idx[arr[x] + 1] > x) - (idx[arr[x] + 1] > y);
            cur += (idx[arr[y] - 1] < y) - (idx[arr[y] - 1] < x);
        } else {
            cur += (x < y ? 1 : -1);
        }
        cur += (idx[arr[y] + 1] > y) - (idx[arr[y] + 1] > x);
        cout << cur << endl;

        swap(arr[x], arr[y]);
        swap(idx[arr[x]], idx[arr[y]]);
    }
}
