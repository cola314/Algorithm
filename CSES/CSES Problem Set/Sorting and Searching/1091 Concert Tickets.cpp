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

int n, m, t, l, r, ret;
vi v;
map<int, int> cnt, pre;

int f(int t) {
    if (cnt[t] > 0) return t;
    if (t == v[0] || t <= 0) return -1;
    return pre[t] = f(pre[t]);
}

int bs(int t) {
    l = 0, r = n-1, ret = -1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (v[m] <= t) ret = max(ret, v[m]), l = m + 1;
        else r = m - 1;
    }
    return ret;
}

signed main() {
    fastio;
    cin >> n >> m;
    FOR(i, n) cin >> t, v.pb(t);
    sort(all(v));
    FOR(i, n) cnt[v[i]]++;
    FOR(i, n - 1) if (v[i] < v[i + 1]) pre[v[i + 1]] = v[i];
    FOR(i, m) {
        cin >> t;
        int p = bs(t);
        p = f(p);
        cout << p << endl;
        cnt[p]--;
    }
}
