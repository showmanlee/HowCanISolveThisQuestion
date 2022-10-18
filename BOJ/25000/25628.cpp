// 햄버거 만들기
// https://www.acmicpc.net/problem/25628

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	cout << min(n / 2, m) << '\n';
}

// 빵 2개와 패티 하나가 들어가는 햄버거를 만드는 상황에서 빵과 패티의 개수가 주어질 때 만들 수 있는 햄버거의 개수 구하기

// 빵/2와 패티의 최소 개수 구하기... 완전한 햄버거를 만들어야 하므로
