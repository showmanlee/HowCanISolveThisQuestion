// Dynamic Dictionary Coding
// https://www.acmicpc.net/problem/6973

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	cin.ignore();
	for (int t = 0; t < tt; t++) {
		map<string, int> dict;
		vector<string> v;
		while (true) {
			string s;
			getline(cin, s);
			if (s == "") {
				break;
			}
			v.push_back(s);
		}
		int cnt = 0;
		for (int i = 0; i < v.size(); i++) {
			stringstream ss(v[i]);
			vector<string> vv;
			string s;
			while (ss >> s) {
				vv.push_back(s);
			}
			for (int j = 0; j < vv.size(); j++) {
				if (dict[vv[j]] == 0) {
					dict[vv[j]] = ++cnt;
					cout << vv[j];
				} else {
					cout << dict[vv[j]];
				}
				if (j < vv.size() - 1) {
					cout << ' ';
				}
			}
			cout << '\n';
		}
		cout << '\n';
	}
}

// 여러 단어로 구성된 문자열 여러 줄을 받으며 등장한 순서대로 사전에 저장한 뒤, 사전에 나온 단어가 나오면 저장된 순서를 대신 출력하기

// 저장 자체는 map으로 처리할 수 있음 - 기본값이 0임을 이용해 처리 가능
// 테케 입력 및 분리, 그리고 출력이 까다로움에 주의 - 테케 구분은 빈 줄, 문자열 끝 공백이 없어야 함 
// getline을 이용한 공백 있는 문자열 입력, stringstream을 통한 파싱, 이걸 입력 조건에 맞춰 해내야 함