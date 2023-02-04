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

const int MAX = 1e6 + 10;
int n, maxv;
int p, q;
vector<iii> v;
vi cnt(MAX), seatByUser(MAX);
priority_queue<int> pq;

void seat(int user) {
    int s;
    if (pq.empty()) {
        s = maxv;
        maxv++;
    } else {
        s = -pq.top();
        pq.pop();
    }
    seatByUser[user] = s;
    cnt[s]++;
}

void go(int user) {
    int seat = seatByUser[user];
    pq.push(-seat);
}

signed main() {
    fastio;
    cin >> n;
    FOR(i, n) {
        cin >> p >> q;
        v.pb(mp(mp(p, 1), i));
        v.pb(mp(mp(q, -1), i));
    }
    sort(all(v));
    
    for (auto t : v) {
        if (t.fi.se == 1) seat(t.se);
        else go(t.se);
    }
    cout << maxv << endl;
    FOR(i, maxv) cout << cnt[i] << " ";

    return 0;
}
