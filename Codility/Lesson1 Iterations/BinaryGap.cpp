int solution(int n) {
	int  l = -1, ans = 0;
	string s;

	while (n) {
		s += n % 2;
		n >>= 1;
	}
	for(int i=0; i<s.size(); i++) if (s[i] == 1) {
		if (l != -1) ans = max(ans, i - l - 1);
		l = i;
	}
	return ans;
}