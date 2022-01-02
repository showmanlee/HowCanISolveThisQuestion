// 멀티탭 스케줄링
// https://www.acmicpc.net/problem/1700

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	vector<int> order(k);
	for (int i = 0; i < k; i++)
		cin >> order[i];
	vector<int> plug(n);
	int res = 0;
	for (int t = 0; t < k; t++) {
		int d = order[t];
		bool plugged = false;
		for (int i = 0; i < n; i++){
			if (plug[i] == d) {
				plugged = true;
				break;
			}
		}
		if (plugged)
			continue;
		for (int i = 0; i < n; i++) {
			if (plug[i] == 0) {
				plugged = true;
				plug[i] = d;
				break;
			}
		}
		if (plugged)
			continue;
		int idx = -1, time = -1;
		for (int i = 0; i < n; i++) {
			int p = 0;
			for (int j = t + 1; j < k; j++) {
				if (plug[i] == order[j])
					break;
				p++;
			}
			if (p > time) {
				idx = i;
				time = p;
			}
		}
		res++;
		plug[idx] = d;
	}
	cout << res << '\n';
}

// n구 멀티탭에 여러 개의 전자기기를 꽂아야 할 때, 가장 효율적으로 플러그를 교체하는 횟수는?

// 앞으로 안 쓰거나 가장 나중에 쓸 플러그를 뽑으면 된다 - 페이지 교체 알고리즘의 OPT
// 사용할 전자기기들을 탐색하며 이미 꽂혀있다면 패스
// 만약 빈 공간이 있다면 해당 위치에 꽂고 패스 - 여기까지 오면 무언가를 뽑아야 하는 상황
// 플러그에 꽂힌 전자기기들에 대해 앞으로의 일정을 확인해, 언제 다시 사용되는지 확인
// 그 중 가장 오랫동안 사용되지 않는 것(또는 아예 사용되지 않는 것)을 선택한 후, 플러그를 교체해준다 - 그러면서 횟수 추가
// 결국 그리기 관점에서 풀 수 있는 문제