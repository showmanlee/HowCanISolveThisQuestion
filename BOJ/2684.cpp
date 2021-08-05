// 동전 게임
// https://www.acmicpc.net/problem/2684

#include <iostream>
#include <string>
#include <map>
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
		map<string, int> count;
		for (int i = 0; i < 38; i++)
			count[s.substr(i, 3)]++;
		cout << count["TTT"] << ' ' << count["TTH"] << ' ' << count["THT"] << ' ' << count["THH"] << ' ' << count["HTT"] << ' ' << count["HTH"] << ' ' << count["HHT"] << ' ' << count["HHH"] << '\n';
	}
}

// 동전을 40번 던진 결과가 주어질 때, 연속해서 3번 던진 부분 결과의 등장 횟수 출력하기

// 등장할 수 있는 부분 결과의 형태는 TTT TTH THT THH HTT HTH HHT HHH - 그리고 던지는 형태는 H와 T로 구성된 길이 40의 문자열
// 따라서 반복문과 substr을 통해 길이 3의 모든 문자열을 순회하고, 이 등장 횟수를 map을 통해 카운팅
// 그리고 그 카운팅 결과를 위와 같은 형태로 출력하기v