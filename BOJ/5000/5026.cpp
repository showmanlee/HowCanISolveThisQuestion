// 박사 과정
// https://www.acmicpc.net/problem/5026

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		string s;
		cin >> s;
		if (s == "P=NP") {
			cout << "skipped\n";
		} else {
			stringstream ss(s);
			string a, b;
			getline(ss, a, '+');
			getline(ss, b, '+');
			cout << stoi(a) + stoi(b) << '\n';
		}
	}
}

// a+b 꼴의 식이 나오면 a와 b의 합을, P=NP가 나오면 skipped 출력하기

// 잘 받아서 출력해주면 됩니다... - 어차피 예외는 P=NP 뿐이니까
