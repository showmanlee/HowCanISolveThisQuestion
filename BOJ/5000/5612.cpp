// 터널의 입구와 출구
// https://www.acmicpc.net/problem/5612

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int p;
	cin >> p;
	bool err = false;
	int res = p;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		p += a - b;
		if (p < 0) {
			err = true;
		}
		res = max(res, p);
	}
	if (err) {
		res = 0;
	}
	cout << res << '\n';
}

// 터널에 처음 들어간 차량 수와 n분 동안 들어가고 나간 차량 수가 주어질 때, 차량이 가장 많이 있던 시점의 차량 수 구하기

// 만약 어떤 시점의 차량 수가 음수가 될 경우 오류로 판단하고 0 출력하기
// 실시간으로 차량을 넣었다 뺐다 하면서 비교해보면 된다 - 그리고 어느 순간 총 차량 수가 음수가 됐다고 하면 오류 판정해서 마지막에 0 출력할 수 있도록