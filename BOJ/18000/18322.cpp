// Word Processor
// https://www.acmicpc.net/problem/18322

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	vector<string> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int len = 0;
	bool eol = true;
	for (int i = 0; i < n; i++) {
		len += v[i].length();
		if (len <= k) {
			if (!eol) {
				cout << ' ';
			}
			cout << v[i];
			eol = false;
		} else {
			cout << '\n' << v[i];
			len = v[i].length();
			eol = false;
		}
	}
}

// 입력한 단어들과 한 줄에 들어가는 공백 제외 글자 수가 주어질 때, 주어진 단어들을 최대한 적은 줄로 출력하기

// 현재 선택한 단어의 글자수를 보고, 그 다음 단어의 글자도 넣을 수 있으면 넣어서 출력한다
// 다만 까다로운 건 공백 처리 - 줄 끝에 공백 등 추가 공백을 엄격하게 판정함
// 따라서 줄을 처음 시작할 때는 앞에 공백을 빼고, 그렇지 않다면 앞에 공백을 넣는 등 처리를 잘 해줘야 합니다...