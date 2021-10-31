// 홍익 절대평가
// https://www.acmicpc.net/problem/23320

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int x, y;
	cin >> x >> y;
	float resx = n * (x / 100.0);
	int resy = 0;
	for (int i = 0; i < n; i++) {
		if (v[i] >= y) {
			resy++;
		}
	}
	cout << int(resx) << ' ' << resy << '\n';
}

// n명의 학생 중 상대평가 적용 시 x%가, 절대평가 적용시 y점 이상일 때 A학점을 받을 수 있을 때, 평가 방식에 따른 A학점 인원 수 출력하기

// 상대평가에서는 무조건 전체 인원수의 x%가 A를 받는다 - 배열 관계 없이 n * (x / 100), float로
// 절대평가에서는 y점 이상인 사람만 A를 받는다 - 배열 순회하면서 y점 이상인 사람 카운트