// 3대 측정
// https://www.acmicpc.net/problem/20299

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<int> res;
	int n, k, l;
	cin >> n >> k >> l;
	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a + b + c >= k && a >= l && b >= l && c >= l) {
			res.push_back(a);
			res.push_back(b);
			res.push_back(c);
		}
	}
	cout << (res.size() / 3) << '\n';
	for (int i : res)
		cout << i << ' ';
	cout << '\n';
}

// 팀원 3명의 합격컷, 개인 합격컷을 모두 만족하는 팀은?
// 조건문 놀이 - 그런데 입력 팀이 500000개가 들어올 수 있음