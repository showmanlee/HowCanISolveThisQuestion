// 욕심쟁이 돼지
// https://www.acmicpc.net/problem/3060

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
		int n;
		cin >> n;
		int cur = 0;
		for (int i = 0; i < 6; i++) {
			int p;
			cin >> p;
			cur += p;
		}
		int day = 1;
		while (cur <= n) {
			cur *= 4;
			day++;
		}
		cout << day << '\n';
	}
}

// 6마리의 돼지가 첫 날에 먹는 양과 매일 줄 수 있는 사료의 양이 주어진 상황에서 각 돼지는 원형으로 둘러 앉아 다음 날 전날 먹은 양에 양옆 및 맞은편 돼지가 먹은 양을 추가로 요구할 때, 사료를 줄 수 없는 상황이 오는 날은?

// 현재 상황에서 돼지 식사량의 합을 구하고 통과했다면 예비 배열에 현재 / 맞은편 / 양옆 양을 더하여 다시 본 배열에 옮긴다
// 그 과정을 날짜 세면서 통과할 수 없는 상황까지 반복하여 결과 출력하기
// 그런데 그렇게 생각할 필요 없이 간단하게 생각하면... 결국 서로 다른 돼지 3마리의 사료양과 자신의 양을 추가로 요구하게 되는 것이므로 매일 4배씩 늘어난다고 생각할 수도 있음
// 