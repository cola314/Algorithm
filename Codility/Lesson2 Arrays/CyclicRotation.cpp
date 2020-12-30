vector<int> solution(vector<int> &A, int K) {
	int n = A.size();
	vector<int> ret(n);
	for (int i = 0; i < A.size(); i++) {
		ret[(i +  K) % n] = A[i];
	}
	return ret;
}