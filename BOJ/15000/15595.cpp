// 정답 비율 계산하기
// hhttps://www.acmicpc.net/problem/15595

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	map<string, int> status;
	int correct = 0, tries = 0;
	for (int i = 0; i < n; i++) {
		int num, result, mem, time, lang, len;
		string name;
		cin >> num >> name >> result >> mem >> time >> lang >> len;
		if (status[name] >= 0) {
			status[name]++;
		}
		if (result == 4 && status[name] > 0) {
			if (name == "megalusion") {
				continue;
			}
			correct++;
			tries += status[name];
			status[name] *= -1;
		}
	}
	if (tries == 0) {
		cout << 0 << '\n';
	} else {
		cout.precision(16);
		double res = (double)correct / (double)tries * 100;
		cout << res << '\n';
	}
}

// BOJ의 정답 비율이 (정답자 / (정답자 + 정답자가 최초 정답을 내기 전 오답 수))로 계산될 때, 문제의 제출 현황을 통해 정답 비율 구하기

// 여러 정보가 주어지지만 우리에게 필요한 건 이름과 결과 뿐
// 일단 이름이 들어오면 시도 횟수에 계속 누적시키다, 정답이 들어오면 분자에 +1, 분모에 시도 수를 더한다
// 여기서 "megalusion"이란 관리자 이름이 들어오면 카운팅하지 않는다 - 그리고 이미 정답을 받은 사람 역시 더 이상 카운팅하지 않는다
// 이를 이용해 분모와 분자를 구해서 백분율로 출력하기 - 분모가 0일 경우에는 0 출력