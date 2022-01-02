// 저울
// https://www.acmicpc.net/problem/2437

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> board(n);
	for (int i = 0; i < n; i++)
		cin >> board[i];
	sort(board.begin(), board.end());
	int res = 1;
	if (board[0] == 1) {
		for (int i = 1; i < n; i++) {
			if (board[i] > res + 1)
				break;
			res += board[i];
		}
		res++;
	}
	cout << res << '\n';
}

// 양팔저울의 한 쪽에만 주어진 무게추를 올려놓을 수 있을 때, 측정할 수 없는 무게의 최솟값 출력하기

// 한 쪽에만 추를 올릴 수 있으므로 무게를 빼는 것은 고려하지 않음 - 하지만 조합 문제로 접근하면 시간 초과(2^1000)
// 여기에 그리디를 적용할 수 있음 - 누적합 기반
// 무게추들을 정렬한 후, 추들의 누적합을 구한다
// 그 과정에서 추가하려는 추의 무게가 현재 누적합 + 1보다 크다면 누적합 + 1을 만들 수 없는 상황이므로 누적합 + 1을 결과값으로 출력 - 그렇지 않다면 계속 누적
// 다만 첫 번째 추의 무게가 1이 아니라면 1은 어떻게 해도 만들 수 없으므로 1 출력
// 누적합 + 1을 체크하는 이유는 지금까지의 모든 추를 이용해 누적합까지의 무게를 만들 수 있음을 알기 때문 - 그리디 원리
// 그리고 추가하려는 추가 누적합 + 1보다 크다면 해당 추를 쓰든 나머지 추를 쓰든 누적합 + 1을 만들 수 없게 되고, 그렇기에 '만들 수 없는 최솟값'이 누적합 + 1이 되는 것