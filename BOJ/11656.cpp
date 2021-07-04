// 접미사 배열
// https://www.acmicpc.net/problem/11656

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	vector<string> res;
	for (int i = 0; i < s.length(); i++) 
		res.push_back(s.substr(i));
	sort(res.begin(), res.end());
	for (string r : res)
		cout << r << '\n';
}

// 어떤 문자열의 가능한 모든 접미사를 사전 순으로 정렬하여 출력하기

// 어떤 문자열의 뒤쪽 문자열만 1~n개 떼어낸 것이 접미사
// 따라서 substr을 통해 이러한 문자열을 추출해 배열에 넣고, 이를 정렬하여 출력한다