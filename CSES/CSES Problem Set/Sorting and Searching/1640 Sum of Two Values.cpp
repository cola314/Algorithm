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

int n, x, t;
vii v;

bool cmp(ii a, ii b) {
    return a.fi < b.fi;
}

signed main() {
    cin >> n >> x;
    FOR(i, n) cin >> t, v.pb(mp(t, i + 1));
    sort(all(v), cmp);
    FOR(i, sz(v)) {
        auto target = x - v[i].fi;
        auto e = upper_bound(v.begin() + i + 1, v.end(), mp(target, 0), cmp);
        auto s = lower_bound(v.begin() + i + 1, v.end(), mp(target, 0), cmp);
        if (e - s > 0) {
            cout << v[i].se << " " << s->se;
            return 0;
        }
    }
    cout << "IMPOSSIBLE";
}
