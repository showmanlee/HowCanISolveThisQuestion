// 트로피 진열
// https://www.acmicpc.net/problem/1668

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	vector<int> trophy(n);
	for (int& i : trophy)
		cin >> i;
	int l = 0, r = 0;
	int lm = 0, rm = 0;
	for (int i = 0; i < n; i++) {
		if (lm < trophy[i]) {
			lm = trophy[i];
			l++;
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		if (rm < trophy[i]) {
			rm = trophy[i];
			r++;
		}
	}
	cout << l << '\n' << r << '\n';
}

// 일렬로 놓은 트로피를 양 끝에서 볼 때 보이는 트로피 개수는?
// 마지막으로 본 트로피 높이보다 높은 트로피가 있을 경우 그 트로피는 보이는 트로피
