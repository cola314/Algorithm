#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define fastio cin.tie(NULL); cin.sync_with_stdio(false);
#define endl "\n"
#define FOR(x, y) for(int x = 0; x < y; x++)
#define pb push_back
#define all(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define ini(x, y) memset(x, y, sizeof(x));
#define INF 987654321
#define y1 omg
#define fi first
#define se second
#define mp make_pair
#define ceildv(x, y) ((x) / (y) + ((x) % (y) != 0))
#define sumn(x) ((x) * ((x) + 1) / 2)
#define square(x) ((x) * (x))
#define int ll
using namespace std;
using ll = long long;
using vi = vector<int>;
using ii = pair<int, int>;
using iii = pair<pair<int, int>, int>;
using vii = vector<ii>;

int n, k, t, flag;
vi v;

signed main() {
    fastio;
    cin >> k >> n;
    FOR(i, k) {
        cin >> t;
        v.pb(t);
    }
    sort(all(v), [](auto a, auto b) {
        auto sa = to_string(a) + to_string(b);
        auto sb = to_string(b) + to_string(a);
        if (sz(sa) != sz(sb)) return sz(sa) > sz(sb);
        FOR(i, sz(sa)) {
            if (sa[i] != sb[i]) return sa[i] > sb[i];
        }
        return false;
    });
    auto remain = *max_element(all(v));
    FOR(i, k) {
        int count;
        if (!flag && remain == v[i]) {
            flag = 1;
            count = n - k + 1;
        } else {
            count = 1;
        }
        FOR(j, count) cout << v[i];
    }
    return 0;
}
