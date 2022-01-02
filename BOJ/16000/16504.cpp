// 종이접기
// https://www.acmicpc.net/problem/16504

#include <iostream>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	long long res = 0;
	for (int i = 0; i < n * n; i++) {
		long long p;
		cin >> p;
		res += p;
	}
	cout << res << '\n';
}

// 각 칸에 숫자가 적혀있는 정사각형 색종이를 접으면 마주보는 면의 숫자가 합쳐진다. 색종이를 끝까지 접었을 때 남는 숫자는?
// 색종이 변의 길이가 2^m 꼴을 유지한다 - 끝까지 접어도 칸 중간이 접히는 일은 없다
// 결과적으로 색종이를 끝까지 접으면 색종이에 있던 모든 수가 합쳐진다