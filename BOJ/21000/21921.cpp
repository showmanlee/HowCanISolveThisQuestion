// 블로그
// https://www.acmicpc.net/problem/21921

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int x, n;
	cin >> n >> x;
	vector<int> board(n);
	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}
	int sum = 0;
	for (int i = 0; i < x; i++) {
		sum += board[i];
	}
	int maxx = sum;
	int cnt = 1;
	for (int i = 0; i < n - x; i++) {
		sum -= board[i];
		sum += board[i + x];
		if (sum == maxx) {
			cnt++;
		}
		else if (sum > maxx) {
			maxx = sum;
			cnt = 1;
		}
	}
	if (maxx == 0) {
		cout << "SAD\n";
	}
	else {
		cout << maxx << '\n' << cnt << '\n';
	}
} 

// n일 동안의 방문자수 기록이 주어졌을 때, 연속된 x일 동안의 방문자수 최대와 횟수 구하기 

// 먼저 0~x-1일의 방문자 합을 구한다
// 이후 한 칸씩 앞으로 가면서 그 상태의 합이 현재 최대보다 높으면 갱신, 같다면 등장 횟수를 늘린다
// 앞으로 가는 방법은 현재 영역 다음 칸의 방문자수를 더하면서 사라지는 칸의 방문자수를 빼는 것 - 슬라이딩 윈도우
// 그렇게 해서 최종적으로 최대 방문자수가 0이면 SAD, 그렇지 않다면 최대와 횟수 출력하기