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

int n, a, b, cur, last;
vii v;

signed main() {
    cin >> n;
    FOR(i, n) {
        cin >> a >> b;
        v.pb(mp(a, b));
    }
    sort(all(v));
    last = v[0].se; cur = 1;
    for (int i = 1; i < sz(v); i++) {
        if (last <= v[i].fi) {
            last = v[i].se;
            cur++;
        } else if (v[i].se <= last) {
            last = v[i].se;
        }
    }
    cout << cur;
}
