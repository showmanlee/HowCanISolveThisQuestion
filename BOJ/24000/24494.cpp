// Herdle
// https://www.acmicpc.net/problem/24494

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<char> a(9), b(9);
	vector<int> ctr(27);
	for (int i = 0; i < 9; i++) {
		cin >> a[i];
		ctr[a[i] - 'A']++;
	}
	for (int i = 0; i < 9; i++) {
		cin >> b[i];
	}
	int resa = 0, resb = 0;
	for (int i = 0; i < 9; i++) {
		if (a[i] == b[i]) {
			ctr[b[i] - 'A']--;
			resa++;
			b[i] = 'Z' + 1;
		}
	}
	for (int i = 0; i < 9; i++) {
		if (ctr[b[i] - 'A'] > 0) {
			ctr[b[i] - 'A']--;
			resb++;
		}
	}
	cout << resa << '\n' << resb << '\n';
}

// 3*3 배열의 대문자로 구성된 답안지와 정답지가 주어질 떄, 글자와 위치가 모두 같은 수와 글자만 같은 수 구하기

// 답안지와 글자 개수를 구해준 뒤, 정답지를 받으며 해당 글자가 나오면 카운터를 줄이고, 답안지와 같은 위치에 있는지 확인한다
// 같은 위치에 나온 경우를 우선적으로 봐야 함에 주의 - 따라서 탐지 과정을 두 번 돌려주며, 첫 번째에서 통과된 글자는 'Z'+1로 맞춰 다음에 탐지되지 않도록 한다