// 알고리즘 수업 - 알고리즘의 수행 시간 2
// https://www.acmicpc.net/problem/24263

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	cout << n << '\n' << 1 << '\n';
}

/*
MenOfPassion(A[], n) {
	sum <- 0;
	for i <- 1 to n
		sum <- sum + A[i]; # 코드
	return sum;
}
*/
// 이 코드에서 n이 주어질 때 코드의 수행 횟수와 시간 복잡도 지수 출력하기

// 1부터 n까지 진행하는 for 안에 코드가 들어가 있으므로 저 코드는 n번 실행됨
// 따라서 시간 복잡도는 O(n)