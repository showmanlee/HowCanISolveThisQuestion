// 이름 궁합
// https://www.acmicpc.net/problem/15312

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int lines[26] = { 3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1 };

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string a, b;
	cin >> a >> b;
	vector<int> v;
	int idxa = 0, idxb = 0;
	while (idxa < a.length() && idxb < b.length()) {
		v.push_back(lines[a[idxa] - 'A']);
		v.push_back(lines[b[idxb] - 'A']);
		idxa++;
		idxb++;
	}
	while (idxa < a.length()) {
		v.push_back(lines[a[idxa] - 'A']);		
		idxa++;
	}
	while (idxb < b.length()) {
		v.push_back(lines[b[idxb] - 'A']);
		idxb++;
	}
	while (v.size() > 2) {
		for (int i = 0; i < v.size() - 1; i++) {
			v[i] = (v[i] + v[i + 1]) % 10;
		}
		v.pop_back();
	}
	cout << v[0] << v[1] << '\n';
}

// 이름 궁합을 볼 대문자 이름들이 주어졌을 때, 이름 궁합도 출력하기

// 교차로 이름 문자들을 두고 각 글자 아래 획수를 적은 후, 마주보는 두 숫자끼리 더해서 %10하는 과정을 2개 남을 때까지 반복한다
// 우선 두 문자열에서 얻은 횟수를 담은 배열을 하나 만든다
// 이후 배열의 길이가 2가 될 때까지 자신과 자신 앞의 수를 더해서 %10한 값을 자신의 값으로 만들고 맨 뒤의 원소를 뺀다
// 이렇게 남은 2개의 수가 답