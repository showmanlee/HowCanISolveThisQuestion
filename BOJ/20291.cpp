// 파일 정리
// https://www.acmicpc.net/problem/20291

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	map<string, int> count;
	vector<string> res;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		string t = s.substr(s.find('.') + 1);
		count[t]++;
		if (count[t] == 1)
			res.push_back(t);
	}
	sort(res.begin(), res.end());
	for (string s : res)
		cout << s << ' ' << count[s] << '\n';
}

// 주어진 파일 리스트에서 등장한 확장자와 등장 횟수를 정렬하여 출력하기

// 등장한 확장자 로스터는 배열에 넣고, 세는 것은 map에서 담당하기 - 확장자 추출은 s.find('.') + 1로 인덱스 잡아서 substr로
// 만약 새로 들어온 확장자의 경우 로스터 배열에 새로 삽입하기
// 모든 파일을 입력받은 후에는 로스터 배열을 정렬하고, 정렬한 것을 순회하며 해당 확장자와 map으로 카운트한 값을 출력하기