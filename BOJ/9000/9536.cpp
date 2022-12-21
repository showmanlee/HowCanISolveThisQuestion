// 여우는 어떻게 울지?
// https://www.acmicpc.net/problem/9536

#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <map>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	string tt;
	getline(cin, tt);
	for (int t = 0; t < stoi(tt); t++) {
		string saying;
		getline(cin, saying);
		string s;
		map<string, bool> keys;
		while (getline(cin, s)) {
			if (s == "what does the fox say?") {
				break;
			}
			stringstream ss(s);
			string p;
			for (int i = 0; i < 3; i++) {
				ss >> p;
			}
			keys[p] = true;
		}
		string pp;
		stringstream sss(saying);
		while (sss >> pp) {
			if (!keys[pp]) {
				cout << pp << ' ';
			}
		}
		cout << '\n';
	}
}

// 소문자 단어들로 구성된 울음소리 녹음 현황과 다른 동물들의 울음소리가 주어질 때, 이들의 울음소리를 뺀 여우의 울음소리는?

// stringstream을 잘 써먹어야 한다 - getline으로 울음소리들 받고, 이후 끝날 때까지 울음소리들을 받는다
// 울음소리를 받을 때는 stringstream으로 세 번째 단어를 map에 체크해주고, 다 받은 후에는 울음소리에 stringstream을 돌려 없다면 출력