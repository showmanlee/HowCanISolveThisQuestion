// 하얀 칸
// https://www.acmicpc.net/problem/1100

#include <iostream>
using namespace std;

int main(void) {
	int res = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			char c;
			cin >> c;
			if (c == 'F' && (i + j) % 2 == 0)
				res++;
		}
	}
	cout << res << '\n';
}

// 8*8 체스판의 하얀 칸 위에 말이 몇 개가 있는지 확인하기
// 0,0이 하얀 칸이니, i + j가 짝수면 하얀 칸