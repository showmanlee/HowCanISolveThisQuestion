// 일곱 난쟁이
// https://www.acmicpc.net/problem/2309

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
// 아홉개만 주어지고 정답은 아무 거나 나와도 되니 n^3으로도 풀 수 있겠지