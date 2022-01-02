// 사분면
// https://www.acmicpc.net/problem/9610

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> res(6);
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		if (x > 0 && y > 0)
			res[1]++;
		else if (x < 0 && y > 0)
			res[2]++;
		else if (x < 0 && y < 0)
			res[3]++;
		else if (x > 0 && y < 0)
			res[4]++;
		else
			res[5]++;
	}
	for (int i = 1; i <= 4; i++)
		cout << "Q" << i << ": " << res[i] << '\n';
	cout << "AXIS: " << res[5] << '\n';
}

// 2차원 좌표상의 점들이 주어질 때, 각 사분면에 몇 개의 점이 있는지 판정하기

// 사분면 판정을 else if로 모두 묶은 뒤, 마지막 else로 축에 있는 점 판정하기