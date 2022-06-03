// Odchudzanie
// https://www.acmicpc.net/problem/8711

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int res = 0, ress = 0, maxx = 0;
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		if (p >= maxx) {
			maxx = p;
			res = max(res, ress);
			ress = 0;
		}
		ress = max(res, maxx - p);
	}
	res = max(res, ress);
	cout << res << '\n';
}

// 몸무게 현황이 주어질 때, 최대로 다이어트한 몸무게 차는?

// 단순히 최대/최소만 구하면 안됨 - 최소가 최대 이전에 나온다면 그건 감량폭이 아니기 때문
// 따라서 최댓값과의 차 중 최댓값을 결과로 쓰되, 중간에 최댓값 이상의 값이 들어온 경우 최댓값을 갱신하면서 지금까지 나온 결과를 다른 곳으로 옮겨야 함 - 새로운 최댓값에서 최대 차가 나오지 않을 수 있기 때문
// 결과적으로 배열로 따로 담을 필요는 없음