// 콘테스트
// https://www.acmicpc.net/problem/5576

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	vector<int> a(10), b(10);
	for (int i = 0; i < 10; i++)
		cin >> a[i];
	for (int i = 0; i < 10; i++)
		cin >> b[i];
	sort(a.begin(), a.end(), greater<int>());
	sort(b.begin(), b.end(), greater<int>());
	cout << (a[0] + a[1] + a[2]) << ' ' << (b[0] + b[1] + b[2]) << '\n';
}

// 10명씩 두 팀으로 나눠진 게임에서 상위 3명의 점수로 승부를 가를 때 그 결과는?
// 10명씩 받고 정렬 후 계산 출력