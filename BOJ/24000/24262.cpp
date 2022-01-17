// 알고리즘 수업 - 알고리즘의 수행 시간 1
// https://www.acmicpc.net/problem/24262

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	cout << 1 << '\n' << 0 << '\n';
}

/*
MenOfPassion(A[], n) {
	i = ⌊n / 2⌋;
	return A[i]; # 코드
}
*/
// 이 코드에서 n이 주어질 때 코드의 수행 횟수와 시간 복잡도 지수 출력하기

// n이 얼마가 들어오든 수행 횟수는 언제나 1
// 따라서 시간 복잡도는 O(1)