// Banana
// https://www.acmicpc.net/problem/18679

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
	map<string, string> dict;
	for (int i = 0; i < n; i++) {
		string s, _, t;
		cin >> s >> _ >> t;
		dict[s] = t;
	}
	int t;
	cin >> t;
	for (int tt = 0; tt < t; tt++) {
		int p;
		cin >> p;
		for (int i = 0; i < p; i++) {
			string s;
			cin >> s;
			cout << dict[s] << ' ';
		}
		cout << '\n';
	}
}

// 어떤 단어의 번역 결과가 주어졌을 때, 주어진 문장 번역하기

// map으로 일대일 대응관계를 저장한 다음, 단어가 주어질 때마다 그대로 출력한다
// 사전에 나온 단어만 나옴이 보장되므로 그렇게 찍어주면 됨