// 볼링 점수 계산
// https://www.acmicpc.net/problem/17215

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	int turn = 1, op = 0;
	vector<int> scores(10);
	vector<int> status(10);
	int idx = 0;
	for (int i = 0; i < 10; i++) {
		while (op < 2) {
			char c = s[idx];
			idx++;
			bool striked = false;
			int sc = 0;
			if (isdigit(c))
				sc = c - '0';
			else if (c == 'P') {
				sc = 10 - scores[i];
				status[i] = 3;
			}
			else if (c == 'S') {
				sc = 10;
				striked = true;
				status[i] = 2;
			}
			scores[i] += sc;
			if (i >= 1 && status[i - 1] == 3) {
				scores[i - 1] += sc;
				status[i - 1] = 0;
			}
			else if (i >= 1 && status[i - 1] > 0) {
				scores[i - 1] += sc;
				status[i - 1]--;
			}
			if (i >= 2 && status[i - 2] > 0) {
				scores[i - 2] += sc;
				status[i - 2]--;
			}
			if (striked)
				break;
			op++;
		}
		op = 0;
	}
	if (s[idx - 1] == 'S' || s[idx - 1] == 'P') {
		int r = (s[idx - 1] == 'S' ? 2 : 1);
		for (int i = 0; i < r; i++) {
			char c = s[idx];
			idx++;
			bool striked = false;
			int sc = 0;
			if (isdigit(c))
				sc = c - '0';
			else if (c == 'P')
				sc = 10 - (s[idx - 2] - '0');
			else if (c == 'S') 
				sc = 10;
			scores[9] += sc;
			if (status[8] == 3) {
				scores[8] += sc;
				status[8] = 0;
			}
			else if (status[8] > 0) {
				scores[8] += sc;
				status[8]--;
			}
		}
	}
	int res = 0;
	for (int i = 0; i < 10; i++)
		res += scores[i];
	cout << res << '\n';
}

// 스트라이크를 S, 스페어를 P, 미스를 -로 표시한 볼링 점수판이 주어졌을 때, 점수 계산하기
// 
// S/P 처리가 중요한 문제 - S/P만 없다면 주어진 20개의 숫자를 모두 순서대로 더하면 됨
// 우선 각 프레임 당 점수를 따로 관리할 수 있도록 점수 배열을 두고, 추가 점수를 받아야되는지 표시하는 상태 배열도 마련해두기
// 이후 10프레임을 돌면서 각 프레임의 문자를 확인하기 - 기본적으로 두 번의 시도지만, 스트라이크인 경우에는 한 번만 수행
// 숫자면 적힌 점수 먹고, S면 10점 먹고 추가 시도 없이 다음 프레임으로 넘어가도록 설정
// P면 (10 - 이전 시도에서 먹은 점수) 먹기 - P는 두 번째 시도에서만 등장함
// 이후 S면 상태 배열을 2로, P면 3으로 채우기 - 2는 두 번 먹고, 3은 한 번만 먹을 수 있도록
// 마지막으로 현재 얻은 점수에 대해 내 전/전전 프레임에 추가 점수로 줘야 되는 경우 추가 점수 지급
// 모든 프레임을 마친 이후 보너스 점수를 얻을 수 있는 경우 경우에 맞게 다시 1~2번 굴리기 - 여기서도 다른 프레임이 추가 점수를 받도록 하기
// 이렇게 모은 점수들을 모두 더한 것이 결과