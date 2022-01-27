// 移動 (Moving)
// https://www.acmicpc.net/problem/24079

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int x, y, z;
	cin >> x >> y >> z;
	cout << (z + 0.5 >= x + y) << '\n';
}

// a에서 b로 갈 때 x시간, b에서 c로 갈 때 y시간이 걸릴 떄, a-b-c로 가는데 z.5시간 이하의 시간이 필요한지 판정하기

// (x + y <= z + 0.5)