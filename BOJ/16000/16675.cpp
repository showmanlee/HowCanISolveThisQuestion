// 두 개의 손
// https://www.acmicpc.net/problem/16675

#include <iostream>
#include <algorithm>
using namespace std;

int result(char c) {
    if (c == 'R') {
        return 0;
	} else if (c == 'S') {
        return 1;
	} else {
        return 2;
	}
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	char aa, ab, ba, bb;
	cin >> aa >> ab >> ba >> bb;
	int xa = result(aa);
	int xb = result(ab);
	int ya = result(ba);
	int yb = result(bb);
	if (xa == xb && ((xa + 2) % 3 == ya || (xa + 2) % 3 == yb)) {
		cout << "TK\n";
	} else if (ya == yb && ((ya + 2) % 3 == xa || (ya + 2) % 3 == xb)) {
		cout << "MS\n";
	} else {
		cout << "?\n";
	}
}

// 가위바위보 하나빼기에서 반드시 이기는 쪽 구하기