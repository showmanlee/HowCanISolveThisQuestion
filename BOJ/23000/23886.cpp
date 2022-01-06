// 알프수
// https://www.acmicpc.net/problem/23886

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	bool res = true;
	int d = s[1] - s[0];
	bool dir = s[1] < s[0];
	if (d == 0 || dir) {
		res = false;
	}
	if (res) {
		for (int i = 2; i < s.length(); i++) {
			int nd = s[i] - s[i - 1];
			bool ndir = s[i] < s[i - 1];
			if (nd == 0 || (dir == ndir && d != nd)) {
				res = false;
				break;
			}
			d = nd;
			dir = ndir;
		}
	}
	if (!dir) {
		res = false;
	}
	cout << (res ? "" : "NON ") << "ALPSOO\n";
}

// 어떤 정수의 자릿수를 높이로 만들 때, 처음은 오르막이고 마지막은 내리막이며 그 사이 평지가 없으며 변곡점을 제외한 경사의 기울기가 달라지지 않는 패턴이 나오는가?

// 정수가 충분히 길고, 자릿수 단위로 봐야 하기에 문자열로 입력 받기
// 이후 각 자릿수마다 현재 경사가 평지거나 경사 방향이 같은데 기울기가 다른 경우 실패 판정하며 돌리기
// 여기서 처음은 무조건 오르막, 마지막은 무조건 내리막이어야 함에 주의 - 212는 아님