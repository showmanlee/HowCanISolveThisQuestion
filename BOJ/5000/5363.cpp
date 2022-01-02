// 요다
// https://www.acmicpc.net/problem/5363

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main(void) {
	string n;
	getline(cin, n);
	for (int i = 0; i < stoi(n); i++) {
		vector<string> v;
		string s, p;
		getline(cin, s);
		stringstream ss(s);
		while (ss >> p)
			v.push_back(p);
		for (int j = 2; j < v.size() + 2; j++)
			cout << v[j % v.size()] << ' ';
		cout << '\n';
	}
}

// 요다는 처음 단어 2개를 맨 뒤로 보내서 말합니다
// 단어를 따기 위해 stringstream을 써볼까요
// 모든 것을 한 줄씩 따기 위해 getline도 쓰고