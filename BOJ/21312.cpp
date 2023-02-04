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

int a, b, c;
vi v;

signed main() {
    int ret = 1;

    cin >> a >> b >> c;
    if (a % 2 == 1 || b % 2 == 1 || c % 2 == 1) {
        if (a % 2 == 1) ret *= a;
        if (b % 2 == 1) ret *= b;
        if (c % 2 == 1) ret *= c;
    } else {
        ret = a * b * c;
    }
    cout << ret;
}
