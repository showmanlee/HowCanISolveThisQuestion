// 배부른 마라토너
// https://www.acmicpc.net/problem/10546

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<string> roster(n);
	set<string> uniqued;
	map<string, int> finished;
	for (int i = 0; i < n; i++) {
		cin >> roster[i];
		uniqued.insert(roster[i]);
		finished[roster[i]]++;
	}
	for (int i = 1; i < n; i++) {
		string s;
		cin >> s;
		finished[s]--;
	}
	for (string s : uniqued) {
		if (finished[s] != 0)
			cout << s << '\n';
	}
}

// 참가자 명단(동명이인 존재 가능)과 완주자 목록이 주어질 때, 완주하지 못한 1명은?

// 로스터에 동명이인이 존재할 수 있음 - 따라서 완주 여부를 bool로 판정할 수 없음
// 여기서는 세 가지 자료구조를 모두 사용할 수 있음 - 순서대로 저장하는 vector, 중복을 빼고 저장하는 set, string을 key로 삼는 map
// vector로 참가자 로스터를 받고, 여기서 받은 값을 set에 중복을 빼고 저장하면서, int를 value로 갖는 map에 참가자 수를 누적시킨다
// 이후 완주자 명단을 받으며 map에 누적된 참가자 수를 하나씩 빼주고, set을 순회하면서 map의 값이 0이 아닌 사람을 찾아 그 사람 이름 출력하기
// 사실 n이 10만까지고, 이 정도면 연속 선형 탐색도 무리가 아니니 set은 굳이 안 넣어도 됨 - 그래도 탐색 효율을 위해 넣긴 했음