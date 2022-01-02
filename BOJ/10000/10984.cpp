// 내 학점을 구해줘
// https://www.acmicpc.net/problem/10984

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int n;
		cin >> n;
		int cnt = 0;
		double sum = 0;
		for (int i = 0; i < n; i++) {
			int a;
			double b;
			cin >> a >> b;
			cnt += a;
			sum += a * b;
		}
		cout << fixed;
		cout.precision(1);
		cout << cnt << ' ' << (sum / cnt) << '\n';
	}
}

// 총 학점과 평점 구하기

// 학점의 합을 구하고, 평점을 학점으로 곱한 것의 합을 구한 뒤, 이를 이용해 총 학점과 평균을 구한다