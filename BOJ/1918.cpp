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

int dx[] = { -2, -2, -1, -1,  1, 1,  2, 2 };
int dy[] = { -1,  1, -2,  2, -2, 2, -1, 1 };

string s;
stack<char> S;

void flush(function<bool(char)> pre) {
	while (!S.empty() && pre(S.top())) {
		cout << S.top();
		S.pop();
	}
}

void process(char c) {
	if (c == '+' || c == '-') {
		flush([](char c) {
			return c == '*' || c == '/' || c == '+' || c == '-';
		});
		S.push(c);
	}
	else if (c == '*' || c == '/') {
		flush([](char c) {
			return c == '*' || c == '/';
		});
		S.push(c);
	}
	else if (c == '(') {
		S.push(c);
	}
	else if (c == ')') {
		flush([](char c) {
			return c != '(';
		});
		S.pop();
	}
	else {
		cout << c;
	}
}

signed main() {
	cin >> s;
	for (auto c : s) {
		process(c);
	}
	flush([](char _) { return true; });
}
