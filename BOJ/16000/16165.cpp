// 걸그룹 마스터 준석이
// https://www.acmicpc.net/problem/16165

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	map<string, string> group;
	map<string, vector<string>> member;
	for (int i = 0; i < n; i++) {
		string g;
		int p;
		cin >> g >> p;
		for (int j = 0; j < p; j++) {
			string e;
			cin >> e;
			group[e] = g;
			member[g].push_back(e);
		}
		sort(member[g].begin(), member[g].end());
	}
	for (int i = 0; i < m; i++) {
		string q;
		int t;
		cin >> q >> t;
		if (t == 0)
			for (string s : member[q])
				cout << s << '\n';
		else
			cout << group[q] << '\n';
	}
}

// 걸그룹의 이름과 속한 멤버들의 이름이 주어질 때, 멤버 이름이 주어질 때 해당 멤버가 속한 그룹을, 그룹 이름이 주어질 때 해당 그룹에 속한 멤버를 출력하기
// map을 사용해보자 - 멤버를 인덱스로 하여 그룹을 저장하는 group, 그룹을 인덱스로 하여 속한 멤버들을 저장하는 member
// 이후 문제의 종류에 따라 group이나 member에서 해당되는 정보 가져오기
// member의 멤버 목록은 정렬되어야 함에 주의