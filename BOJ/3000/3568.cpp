// iSharp
// https://www.acmicpc.net/problem/3568

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	vector<string> v;
	while (cin >> s) {
		v.push_back(s);
	}
	string res;
	vector<string> prefix(v.size(), v[0]);
	vector<string> name(v.size());
	for (int i = 1; i < v.size(); i++) {
		string p;
		for (char c : v[i]) {
			if (c == '&' || c == '*') {
				p = c + p;
			} else if (c == '[') {
				p = "[]" + p;
			} else if (c != ',' && c != ';' && c != ']') {
				name[i] += c;
			}
		}
		prefix[i] += p;
	}
	for (int i = 1; i < v.size(); i++) {
		cout << prefix[i] << ' ' << name[i] << ";\n";
	}
}

// 기본 변수형과 변수가 참조, 포인터, 배열 표시와 함께 한 줄로 선언되었을 때, 각 줄에 선언하도록 변환하기

// 기본 변수형 뒤에 기호들이 오고, 변수명 뒤에 기호들이 온다 - 다만 변수명 뒤에 붙는 기호들은 기본 변수형 앞으로 올 때 순서가 뒤집혀야 한다
// 따라서 분리되는 변수형의 형태는 기본 변수형 + 기본 변수형 기호 + 개별 변수 기호 역순 - 따라서 처음 두 부분은 주어진 문자열 첫 칸으로 확인 가능
// 