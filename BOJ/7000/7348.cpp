// 테이블 옮기기
// https://www.acmicpc.net/problem/7348

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		vector<int> v(200);
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			a = (a - 1) / 2;
			b = (b - 1) / 2;
			if (a > b) {
				swap(a, b);
			}
			for (int p = a; p <= b; p++) {
				v[p]++;
			}
		}
		int res = 0;
		for (int i = 0; i < 200; i++) {
			res = max(res, v[i]);
		}
		res *= 10;
		cout << res << '\n';
	}
}

// 홀수와 짝수 방이 같은 행에 있고 한 번에 한 테이블만 옮길 수 있는 200열 복도에서 방에서 방으로 테이블을 옮길 때, 소요 시간 구하기

// 같은 라인간 이동(+1, -1)은 소요 시간 없음, 그 외의 이동은 abs(((출발 - 1) / 2) - ((도착 - 1) / 2)) * 10분 소요
// 그리고 테이블을 옮길 때 경로가 겹치지 않으면 동시에 이동 가능
// 따라서 테이블 이동 커맨드가 주어질 때 해당 경로를 밟는 횟수를 배열에 저장한 후, 나중에 해당 배열의 최댓값을 찾아 결과로 출력한다