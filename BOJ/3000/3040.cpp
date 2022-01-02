// 백설 공주와 일곱 난쟁이
// https://www.acmicpc.net/problem/3040

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	vector<int> gob(9);
	for (int i = 0; i < 9; i++)
		cin >> gob[i];
	sort(gob.begin(), gob.end());

	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 9; j++) {
			int res = 0;
			for (int k = 0; k < 9; k++)
				if (k != i && k != j)
					res += gob[k];
			if (res == 100) {
				for (int k = 0; k < 9; k++)
					if (k != i && k != j)
						cout << gob[k] << '\n';
				return 0;
			}
		}
	}
	return 0;
}

// 아홉 난쟁이 중 키의 합이 100이 되는 일곱 난쟁이는?
// 2309와 동일한 문제
// n^3으로 2개를 빼고 합을 구하는데, 100이 되면 선택한 숫자들 출력하기
// 브루트포스 입문 문제