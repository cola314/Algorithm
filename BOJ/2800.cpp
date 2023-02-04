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

string s;
vi brackets;
vii pairs;
stack<int> st;
vector<string> ret;

string create_string(int flag) {
    vi v(sz(s));
    FOR(i, sz(pairs)) if (flag & (1 << i)) {
        v[pairs[i].fi] = v[pairs[i].se] = 1;
    }
    int cnt = 0;
    string rs;
    FOR(i, sz(s)) {
        if (s[i] == '(' || s[i] == ')') {
            if (!v[i]) {
                continue;
            }
        }
        rs += s[i];
    }
    return rs;
}

signed main() {
    cin >> s;
    FOR(i, sz(s)) {
        if (s[i] == '(') {
            brackets.pb(1);
            st.push(i);
        } else if (s[i] == ')') {
            brackets.pb(-1);
            pairs.pb(mp(st.top(), i));
            st.pop();
        }
    }

    FOR(flag, (1 << sz(pairs)) - 1) {
        ret.pb(create_string(flag));
    }
    
    sort(all(ret));
    FOR(i, sz(ret)) {
        if (i == 0 || ret[i] != ret[i - 1]) {
            cout << ret[i] << endl;
        }
    }
    return 0;
}
