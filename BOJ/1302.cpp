// 베스트셀러
// https://www.acmicpc.net/problem/1302

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	string res;
	int resc = 0;
	map<string, int> cnt;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		cnt[s]++;
		if (cnt[s] > resc) {
			res = s;
			resc = cnt[s];
		}
		else if (cnt[s] == resc && s < res)
			res = s;
	}
	cout << res << '\n';
}

// 하루 동안의 책 판매량이 주어질 때, 가장 많이 팔린 책(동률일 경우 사전상 먼저 오는 책)은?

// map을 통해 숫자를 세고, 최댓값에 도달하면 사전 순서를 보고, 넘어섰다면 그냥 결과값을 갱신한다