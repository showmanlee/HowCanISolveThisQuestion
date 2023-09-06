// ZOAC 4
// https://www.acmicpc.net/problem/23971

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int h, w, n, m;
	cin >> h >> w >> n >> m;
	int res = (((h + n) / (n + 1)) * ((w + m) / (m + 1)));
	cout << res << '\n';
}

// w*h 보드에서 세로로 n칸 가로로 m칸 띄어 앉아야 할 떄, 보드에 넣을 수 있는 최대 인원 수 구하기

// 적당히 계산하면 구할 수 있음 - 나눗셈 올림