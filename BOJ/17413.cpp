// 단어 뒤집기 2
// https://www.acmicpc.net/problem/17413

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	getline(cin, s);
	vector<pr> index;
	int idx = 0;
	bool inbraket = false;
	index.push_back({ -1, 0 });
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '<') {
			index[idx].second = i;
			inbraket = true;
			idx++;
			index.push_back({ -1, 0 });
		}
		else if (s[i] == '>') {
			inbraket = false;
		}
		else if (s[i] == ' ') {
			index[idx].second = i;
			idx++;
			index.push_back({ -1, 0 });
		}
		else if (!inbraket) {
			if (index[idx].first == -1)
				index[idx].first = i;
		}
	}
	index[idx].second = s.length();
	for (pr p : index) {
		if (p.first == -1)
			continue;
		reverse(s.begin() + p.first, s.begin() + p.second);
	}
	cout << s << '\n';
}

// 주어진 문자열에서 <>로 둘러싸인 태그 바깥의 공백으로 나눠진 단어들을 뒤집어 출력하기

// 단어별로 인덱스 앞과 뒤를 저장하여, reverse로 뒤집기
// 이를 위해 인덱스 앞과 뒤 영역을 문자열의 문자를 순회하며 따야 한다 - 봐야 하는 케이스는 4가지
// <인 경우 현재 단어를 마무리하고 태그에 들어왔음을 표시한 후, 새로운 인덱스를 미리 만들어두기
// >인 경우 태그에서 나왔음을 표시하기 - 태그 꺽은괄호는 중첩되지 않음이 보장됨
// 공백인 경우 현재 단어를 마무리하고 새로운 인덱스 만들기
// 나머지 문자의 경우 태그 내부가 아니라면 인덱스 안에 넣기 - 만약 인덱스 시작점이라면 시작점으로 기록하고
// 인덱스 시작점 판정은 문자를 찾았을 때 시작점이 초기값인 -1인지 확인하는 것 - 만약 -1이라면 아직 준비되지 않은 인덱스임을 의미
// 마지막으로 모든 인덱스를 순회하며, 준비되지 않은 찌꺼기 -1 인덱스를 제외한 나머지 인덱스의 시작과 끝 지점을 뒤집은 후 출력하기