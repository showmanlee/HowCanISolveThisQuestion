// 알고리즘 수업 - 알고리즘의 수행 시간 6
// https://www.acmicpc.net/problem/24267

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long n;
	cin >> n;
	long long res = (n * (n - 1) * (n - 2)) / 6;
	cout << res << '\n' << 3 << '\n';
}

/*
MenOfPassion(A[], n) {
	sum <- 0;
	for i <- 1 to n - 2
		for j <- i + 1 to n - 1
			for k <- j + 1 to n
				sum <- sum + A[i] × A[j] × A[k]; # 코드
	return sum;
}
*/
// 이 코드에서 n이 주어질 때 코드의 수행 횟수와 시간 복잡도 지수 출력하기

// 1부터 n-2, i + 1부터 n-1, j + 2부터 n까지 진행되는 for가 중첩되어 있음
// 4와 비슷한데 3차원이라고 보면 됨
// 따라서 실행 횟수는 저렇게, 시간복잡도는 O(n^3)