// 라디오
// https://www.acmicpc.net/problem/3135

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b, n;
	cin >> a >> b >> n;
	vector<int> channels(n + 1), dist(1000, 987654321);
	channels[0] = a;
	for (int i = 1; i <= n; i++) {
		cin >> channels[i];
	}
	for (int i = 0; i <= n; i++) {
		dist[channels[i]] = 1;
		if (i == 0) {
			dist[channels[i]] = 0;
		}
		for (int j = channels[i] - 1; j >= 0; j--) {
			dist[j] = min(dist[j], dist[channels[i]] + channels[i] - j);
		}
		for (int j = channels[i] + 1; j < 1000; j++) {
			dist[j] = min(dist[j], dist[channels[i]] + j - channels[i]);
		}
	}
	cout << dist[b] << '\n';
}

// 주파수를 1 올리고 줄이는 버튼과 특정 주파수로 이동하는 버튼들이 있을 때, 주파수 a에서 b로 이동하는데 필요한 최소 버튼 입력 갯수 구하기

// 주파수 범위가 1~999로 정해져있기 때문에 전체 거리 배열을 만들어둘 수 있음
// 거리 배열에서 출발지는 0, 버튼이 있는 곳은 1, 나머지 부분은 최대치로 세팅해두고, 최대치가 있는 부분을 0/1에서 시작하는 거리들 중 최솟값으로 갱신한다
// 이렇게 처리해두고 도착지의 배열값을 찾아서 출력해주기