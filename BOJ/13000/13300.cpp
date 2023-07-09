// 방 배정
// https://www.acmicpc.net/problem/13300

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
typedef pair<int, string> pr;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	vector<int> v(13);
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v[(a * 6) + b]++;
	}
	int res = 0;
	for (int i = 1; i <= 12; i++) {
		res += ceil((double)v[i] / k);
	}
	cout << res << '\n';
}

// 초등학교 수학여행에서 각 학년별 같은 성별끼리 k명씩 방을 짤 때, 필요한 방 수는?

// 성별/학년별 학생 수를 구한 후 학생 수 / 방 정원의 최대를 구한다