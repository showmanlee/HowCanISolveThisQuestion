// 0의 개수
// https://www.acmicpc.net/problem/11170

#include <iostream>
#include <string>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int n, m;
		cin >> n >> m;
		int res = 0;
		for (int i = n; i <= m; i++) {
			for (char c : to_string(i))
				if (c == '0')
					res++;
		}
		cout << res << '\n';
	}
}

// n부터 m까지 정수 중 0이 나오는 횟수는?
// 이건 직접 세보는 수밖에 없지 - for문 돌면서 i를 string으로 변환 후 그 안에서 '0' 개수 세기