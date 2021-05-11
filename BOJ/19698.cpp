// 헛간 청약
// https://www.acmicpc.net/problem/19698

#include <iostream>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, w, h, l;
	cin >> n >> w >> h >> l;
	int res = (w / l) * (h / l);
	cout << (res > n ? n : res) << '\n';
}

// w*h 헛간을 l*l씩 나누어 n마리의 소를 넣으려고 할 때, 넣을 수 있는 소는?
// w*h에서 확보할 수 있는 l*l의 수는 (w / l) * (h / l)
// 여기서 n과 결과 중 더 작은 값으로 출력 