// 삼각형만들기
// https://www.acmicpc.net/problem/2622

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	int res = 0;
	for (int i = 1; i < n; i++) {
		for (int j = i; j < n; j++) {
			int k = n - i - j;
			if (k < j) {
				break;
			}
			if (i + j > k) {
				res++;
			}
		}
	}
	cout << res << '\n';
}

// 주어진 성냥개비들로 만들 수 있는 서로 다른 삼각형의 개수 구하기

// 가장 긴 변의 길이보다 나머지 두 변의 합이 더 커야 삼각형 형성 가능
// 이를 이용하여, i + j + k == n이면서 i + j > k 형태를 만족하는 모든 순서쌍을 찾아본다