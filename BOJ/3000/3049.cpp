// 다각형의 대각선
// https://www.acmicpc.net/problem/3049

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int res = n * (n - 1) * (n - 2) * (n - 3) / 24;
	cout << res << '\n';
}

// 정n각형의 대각선들을 그릴 떄 생기는 교차점의 개수 구하기

// 수열로 접근해야 할 거 같지만 조합 문제
// 교차점이 생기려면 서로 다른 4개의 꼭짓점을 골라 교차가 되도록 선을 그어주면 된다 - 사각형의 케이스에서 볼 수 있듯이 그러한 경우의 수는 단 하나
// 따라서 이건 nC4와 같음(n == 3일 경우 0)