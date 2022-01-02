// 골뱅이 찍기 - 뒤집힌 ㄱ
// https://www.acmicpc.net/problem/23802

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 0; i < n * 5; i++) {
		for (int j = 0; j < n * 5; j++) {
			if (i / n == 0 ||j / n == 0) {
				cout << '@';
			}
		}
		cout << '\n';
	}
}

// 두께가 n인 좌우 반전된 ㄱ 그리기

// 기본적인 형태는 동일하고, 최종 크기는 n * 5
// 크기를 잡고, i/j 크기를 n으로 나눴을 때 0일 때 골뱅이를 출력한다

// 이번에 새로 나온 골뱅이 찍기 계열 문제는 이렇게 풀어주면 됨
// 다만 문제에 따라 공백 출력 관련해서 출력 초과가 뜰 수 있으니 예제가 어떻게 나오는지 확인하자