// 전구
// https://www.acmicpc.net/problem/21918

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<int> lights(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> lights[i];
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1)
			lights[b] = c;
		else {
			for (int j = b; j <= c; j++) {
				if (a == 2)
					lights[j] = !lights[j];
				else if (a == 3)
					lights[j] = 0;
				else if (a == 4)
					lights[j] = 1;
			}
		}
	}
	for (int i = 1; i <= n; i++)
		cout << lights[i] << ' ';
	cout << '\n';
}

// n개의 전구의 초기 상태와 전구를 조작하는 명령어들이 주어질 때, 명령을 수행한 후의 전구 상태 출력하기
// a, b, c 꼴에서 a == 1이면 전구 b의 상태를 c로 바꾸기
// a == 2면 b~c 전구들의 상태를 뒤집기, a == 3이면 모두 켜기, a == 4면 모두 끄기

// 각 전구의 상태를 배열로 만든 후, 시키는 대로 켜고 꺼주면 됨
// 전구나 명령어가 최대 4000까지 주어지므로 n^2 기반으로도 충분히 켜고 끌 수 있음

// BOJ 900문제 돌파! - 1000문제에 도달하면 문제 수 500위는 물론 400위도 바라볼 수 있다
// 새로운 카테고리의 문제를 풀어보고, solved.ac 1000위 돌파도 노려보자