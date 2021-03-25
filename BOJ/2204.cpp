// 도비의 난독증 테스트
// https://www.acmicpc.net/problem/2204

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;
typedef pair<string, int> pr;

int main(void) {
	while (true) {
		int n;
		cin >> n;
		if (n == 0)
			break;

		vector<string> origin(n);
		vector<pr> sorter(n);
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			origin[i] = s;
			for (char& c : s)
				c = tolower(c);
			sorter[i] = { s, i };
		}
		sort(sorter.begin(), sorter.end());

		cout << origin[sorter[0].second] << '\n';
	}
}

// 대소문자가 섞인 단어들을 대소문자를 무시하고 정렬한 결과로 나오는 첫 단어는?
// 원래 단어를 저장하는 배열과 소문자화한 단어와 원래 인덱스를 저장한 배열 생성 후 입력
// 이후 2번째 배열을 정렬하여 해당 배열의 첫 번째 원소의 인덱스 가리키는 원래 단어를 출력하기