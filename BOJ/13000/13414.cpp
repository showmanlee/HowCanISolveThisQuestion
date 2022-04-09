// 수강신청
// https://www.acmicpc.net/problem/13414

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int k, l;
	cin >> k >> l;
	vector<string> order(l);
	map<string, int> candi;
	for (int i = 0; i < l; i++) {
		string s;
		cin >> s;
		order[i] = s;
		if (candi.count(s) != 0) {
			order[candi[s]] = "";
		}
		candi[s] = i;
	}
	int cnt = 0;
	for (int i = 0; i < l; i++) {
		if (order[i] != "") {
			cnt++;
			cout << order[i] << '\n';
		}
		if (cnt == k) {
			break;
		}
	}
} 

// k명이 들을 수 있는 수업에 l번의 수강신청이 들어왔는데, 같은 사람이 연속으로 수강신청할 경우 우선순위가 맨 뒤로 밀릴 때, 최종적으로 수강하는 사람 수 구하기

// 결국 마지막에 입력된 순서대로 우선순위가 갈리기에, 학번을 입력받으며 map으로 마지막 우선순위를 갱신한다
// 그러면서 동시에 마지막 우선순위만 남는 배열을 마련하면서 갱신한다
// 이후 그 배열을 순회하며 빈칸이 아닌 칸을 k만큼 출력한다