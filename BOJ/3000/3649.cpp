// 로봇 프로젝트
// https://www.acmicpc.net/problem/3649

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int x;
	while (cin >> x) {
		x *= 10000000;
		int n;
		cin >> n;
		vector<int> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		int left = 0, right = n - 1;
		while (left < right) {
			if (v[left] + v[right] == x) {
				break;
			}
			else if (v[left] + v[right] > x) {
				right--;
			}
			else {
				left++;
			}
		}
		if (left >= right) {
			cout << "danger\n";
		}
		else {
			cout << "yes " << v[left] << ' ' << v[right] << '\n';
		}
	}
}

// x cm(x*10000000 nm)의 구멍을 막기 위해 두 개의 레고 블록을 사용할 수 있을 때, 사용할 수 있는 블록은?

// 투 포인터를 사용해서 계산해보자
// 주어진 블록들을 정렬한 다음, 양 끝쪽에서부터 포인터를 움직인다 - 목표보다 작다면 왼쪽, 크다면 오른쪽을 움직여서
// 그러다가 정확히 구멍 길이에 맞춰지면 그 블록들을 출력하고, 맞추지 못한 채 포인터가 교차했다면 실패 판정
// 구멍은 cm, 블록은 nm 단위로 주어짐에 주의