// Roll the Dice
// https://www.acmicpc.net/problem/6856

#include <iostream>
#include <cctype>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	int res = 0;
	for (int i = 1; i <= 9; i++) {
		if (i <= n && (10 - i) <= m) {
			res++;
		}
	}
	cout << "There " << (res == 1 ? "is " : "are ") << res << " way" << (res == 1 ? "" : "s") << " to get the sum 10.\n";
}

// 1부터 n/m까지 써진 주사위 2개가 주어질 떄, 합해서 10이 나오는 경우의 수를 문법에 맞춰 출력하기

// 1+9부터 9+1까지 가능한 경우를 모두 출력합니다