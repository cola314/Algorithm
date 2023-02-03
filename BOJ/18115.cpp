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
int n, skill;
vi v(MAX), result, origin(MAX);

signed main() {
    cin >> n;

    deque<int> dq;
    FOR(i, n) dq.pb(i);
    FOR(i, n) {
        cin >> skill;
        if (skill == 1) {
            result.pb(dq.front());
            dq.pop_front();
        } else if (skill == 2) {
            int temp = dq.front();
            dq.pop_front();
            result.pb(dq.front());
            dq.pop_front();
            dq.push_front(temp);
        } else if (skill == 3) {
            result.pb(dq.back());
            dq.pop_back();
        }
    }
    reverse(all(result));
    
    FOR(i, n) origin[result[i]] = i + 1;
    FOR(i, n) cout << origin[i] << " ";

    return 0;
}
