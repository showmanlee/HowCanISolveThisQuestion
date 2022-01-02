// 영단어 암기는 괴로워
// https://www.acmicpc.net/problem/20920

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
typedef pair<string, int> prs;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	set<string> shown;
	map<string, int> count;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s.length() >= m) {
			shown.insert(s);
			count[s]++;
		}
	}
	vector<prs> res;
	for (string s : shown)
		res.push_back({ s, count[s] });
	sort(res.begin(), res.end(), [](prs a, prs b) -> bool {
		if (a.second != b.second)
			return a.second > b.second;
		if (a.first.length() != b.first.length())
			return a.first.length() > b.first.length();
		return a.first < b.first;
		});
	for (prs p : res)
		cout << p.first << '\n';
}

// 주어진 영단어 중 길이가 m 이상인 것들을 뽑아 등장한 횟수 내림차순 -> 길이 내림차순 -> 사전 순으로 정렬한 결과 출력하기

// 이를 위해 단어의 등장 횟수를 세는 map, 그리고 중복 없이 후보군을 추려줄 set이 필요함
// 단어들을 받으면서, 길이가 m 이상이라면 후보군에 넣고 등장 횟수를 늘려줌
// 이후 그 후보군과 카운트를 pair로 만들어 vector에 넣고, 앞서 말한 정렬 기준에 맞춰 정렬한 뒤 출력하기