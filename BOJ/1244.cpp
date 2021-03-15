// 스위치 켜고 끄기
// hhttps://www.acmicpc.net/problem/1244

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	vector<bool> sw(n + 1);
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		sw[i] = (k == 1);
	}
	int m;
	cin >> m;
	for (int t = 0; t < m; t++) {
		int s, o;
		cin >> s >> o;
		if (s == 1) {
			for (int i = o; i <= n; i += o)
				sw[i] = !sw[i];
		}
		else {
			sw[o] = !sw[o];
			for (int i = 1; i <= n; i++) {
				if (o - i < 1 || o + i > n)
					break;
				if (sw[o - i] == sw[o + i])
					sw[o - i] = sw[o + i] = !sw[o - i];
				else
					break;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << sw[i] << ' ';
		if (i % 20 == 0)
			cout << '\n';
	}
	cout << '\n';
}

// 1~n번 까지의 스위치가 있을 때, 남학생은 받은 스위치 번호의 배수인 스위치를 조작하고, 여학생은 받은 스위치 번호를 중심으로 좌우가 대칭이면서 가장 많은 스위치를 포함하는 구간의 스위치를 조작한다.
// 모든 학생이 스위치를 조작한 결과는?
// 스위치 수도 100, 학생 수도 100 - 무작정 접근 가능
// 남자는 오른쪽을 뻗는 반복문, 여자는 양쪽을 뻗는 반복문
// 출력은 한 줄에 20개씩 해야 함에 주의