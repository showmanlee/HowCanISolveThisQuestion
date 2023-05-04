// 야근
// https://www.acmicpc.net/problem/14402

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	map<string, int> cnt;
	int res = 0;
	for (int i = 0; i < n; i++) {
		string s;
		char c;
		cin >> s >> c;
		cnt[s] += (c == '+' ? 1 : -1);
		if (cnt[s] < 0) {
			res += -cnt[s];
			cnt[s] = 0;
		}
	}
	for (auto t : cnt) {
		if (t.second > 0) {
			res += t.second;
		}
	}
	cout << res << '\n';
}

// 하루 동안의 근태 기록표에서 어떤 사람이 출근하지 않았는데 퇴근하거나, 출근한 뒤 퇴근하지 않았을 때 야근으로 인정할 때, 야근 발생 횟수 구하기

// 각 이름별로 스택으로 관리 - +면 +1, -면 -1을 하는 식으로
// 여기서 스택 값이 음수가 되면 바로 야근 하나 올려주고, 기록이 끝났을 때 스택 값이 양수라면 그만큼 야근 횟수 채워주기